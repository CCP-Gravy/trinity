#include "StdAfx.h"
#include "followASpline.h"
#include "Include/TriMath.h"
#include "include/TriQuaternion.h"

FollowASpline::FollowASpline( IRoot* lockobj ) :
	m_behaviorWeight( 10.f ),
	m_smoothPullFactor( 0.8 )
{
}

FollowASpline::~FollowASpline()
{
}


void FollowASpline::CalculateBehavior( DroneAgent& agent, const float deltaTime, BehaviorGroup& group, EveChildBehaviorSystem& system )
{
	auto tunnels = system.GetTunnels();
	m_desiredVector = Vector3(0,0,0 );
	float rampingForce = 1;
	if(agent.tunnelLock == -1)
	{
		// not associated with a tunnel
		for (auto tunnel = tunnels.begin(); tunnel != tunnels.end(); ++tunnel)
		{
			auto t = ( *tunnel );
			Vector3 dist = t.splinePoints[ 0 ].pos - agent.position;
			float length = Length( dist );
			if( length < t.pointOfNoReturnSize )
			{
				agent.tunnelLock = t.tunnelID;
				agent.tunnelPoint = 0;
			} 
			else if( length < t.pullSize )
			{
				// the Dot product is positive if the agent is facing the pointCenter
				if ( Dot( dist, Vector3( agent.rotation ) ) < 0 )
				{
					continue;
				}

				// normalize the distance between outer and inner spheres to increase pull-strength
				if ( t.pullSize == t.pointOfNoReturnSize )
				{
					continue;
				}

				float mod = ( length - t.pointOfNoReturnSize ) / ( t.pullSize - t.pointOfNoReturnSize );
				mod = 1 - max(0.f,min( mod, 1.f));
				m_desiredVector = dist;
				rampingForce = min(1.f, max(0.f, 1 - m_smoothPullFactor + ( m_smoothPullFactor * mod )));
				break;
			}
		}
	}

	if (agent.tunnelLock != -1)
	{
		
		
		auto t = tunnels[ agent.tunnelLock ];
		auto pID = agent.tunnelPoint; // Point ID

		
		Vector3 dist = t.splinePoints[ pID ].pos - agent.position;

		if( t.splinePoints[ pID ] == (*t.splinePoints.end()) )
		{
			m_desiredVector = t.splinePoints[ pID ].rot;

			// the Dot product is positive if the agent is facing the pointCenter
			if ( Dot( dist, Vector3( agent.rotation ) ) < 0 )
			{
				agent.tunnelLock = -1;
				agent.tunnelPoint = 0;
			}
		}
		else
		{
			float lengthFromShip = Length( dist );

			float lengthBetweenPoints;

			if ( t.splinePoints[ pID ] == ( *t.splinePoints.begin() ) )
			{
				lengthBetweenPoints = t.pointOfNoReturnSize;
			}
			else
			{
				Vector3 dist = t.splinePoints[ pID - 1 ].rot;
				lengthBetweenPoints = Length( dist );
			}

			float blendingMod = 0;

			if( lengthBetweenPoints != 0 )
			{
				blendingMod = min(1.f,max( 0.f, ( lengthBetweenPoints - lengthFromShip ) / lengthBetweenPoints));
				blendingMod = blendingMod * blendingMod;
			}

			m_desiredVector = (1 - blendingMod) * Normalize(dist) + blendingMod * Normalize(t.splinePoints[ pID ].rot + dist );

			if( (lengthFromShip + group.GetBoundingSphereRadius()) < t.pointOfNoReturnSize)
			{
				// the Dot product is positive if the agent is facing the pointCenter
				//if ( Dot( dist, Vector3( agent.rotation ) ) < 0 )
				//{
					//temp breakoff
					agent.tunnelPoint++;
				//}
			}

			
			//rework into cylinder collision
			if ( lengthFromShip > 3 * lengthBetweenPoints )
			{
				agent.tunnelLock = -1;
				agent.tunnelPoint = 0;
			}
		}
	}
	
	if ( m_desiredVector == Vector3( 0, 0, 0 ) ) 
	{
		return;
	}

	m_pullForce = Normalize( m_desiredVector );
	m_pullForce *= m_behaviorWeight * rampingForce;
	agent.acceleration += m_pullForce;

}

void FollowASpline::RenderDebugInfo( Tr2DebugRenderer& renderer, Vector3 agentPos )
{
	return;
}