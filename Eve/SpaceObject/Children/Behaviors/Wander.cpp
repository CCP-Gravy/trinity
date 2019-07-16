#include "StdAfx.h"
#include "Wander.h"
#include "Include/TriMath.h"
#include "include/TriQuaternion.h"

Wander::Wander(IRoot* lockobj) :
	m_weightWander(4.f),
	m_circleDistance(1.5f),
	m_wanderForce(1, 1, 1),
	m_circleRadius(25.f)
{
}

Wander::~Wander()
{
}

void Wander::CalculateBehavior(DroneAgent& agent, const float deltaTime, BehaviorGroup& sys )
{	
	/*Find the center of circle in front of agent
				
			 (  C  )
				|	m_circleDistance(float, for length)
				|
				|	m_wanderForce(Vec3, for direction)
			   a.pos

	*/
	m_centerOfCircle = agent.position + Normalize( m_wanderForce ) * m_circleDistance;

	Vector3 rightVector = Cross( m_wanderForce, Vector3( 0, 1, 0 ) ); //0°

	//Random angle between 0 and 2PI radians
	float randomAngle = TriFloatRandom01() * XM_2PI;

	Quaternion rightVectorRotation = RotationQuaternion( m_wanderForce, randomAngle );
	//Rotate the right vector by the quaternion
	TriVectorRotateQuaternion( &rightVector, &rightVector, &rightVectorRotation );
	//Vector3 targetPoint = m_centerOfCircle + rightVector * (TriFloatRandom01() * m_circleRadius);

	m_desiredVector = rightVector - agent.position;
	m_wanderForce = Normalize(m_desiredVector);
	m_wanderForce *= m_weightWander;
	agent.acceleration += m_wanderForce;

}

void Wander::RenderDebugInfo(Tr2DebugRenderer& renderer, Vector3 agentPos)
{
	//renderer.DrawSphere(this, agentPos, m_circleRadius, 16, Tr2DebugRenderer::Lit, 0xffffff00 );
	renderer.DrawLine(this, agentPos, m_desiredVector, 0xffffff00 );


}
