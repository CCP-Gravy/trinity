#include "StdAfx.h"
#include "Wander.h"
#include "Include/TriMath.h"
#include "include/TriQuaternion.h"

Wander::Wander(IRoot* lockobj) :
	m_weightWander(66.f),
	m_freq(0.01f),
	rand1( 13.6842f ),
	rand2( 27.5111456 ),
	rand3( 256.654f )
{
}

Wander::~Wander()
{
}

void Wander::CalculateBehavior( std::vector<DroneAgent>& agents, const float deltaTime, BehaviorGroup& sys, EveChildBehaviorSystem& system )
{	
	for (auto agent = agents.begin(); agent != agents.end(); ++agent)
	{
		float seed = agent->lifetime + agent->id;

		Vector3 p = Vector3( seed * rand1, seed * rand2, seed * rand3 ) * m_freq;

		Vector3 force( float( PerlinNoise1D( p.x, 2, 1, 1 ) ), float( PerlinNoise1D( p.y, 2, 1, 1 ) ), float( PerlinNoise1D( p.z, 2, 1, 1 ) ) );
		agent->acceleration += force * m_weightWander;
	}
}

void Wander::RenderDebugInfo(Tr2DebugRenderer& renderer, Vector3 agentPos)
{
}
