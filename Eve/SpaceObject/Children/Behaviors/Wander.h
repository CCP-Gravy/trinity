#pragma once
#ifndef Wander_H
#define Wander_H
#include "Eve/SpaceObject/Children/EveChildBehaviorSystem.h"
#include "IBehavior.h"

BLUE_CLASS( Wander ) :
	public IBehavior
{
public:
	EXPOSE_TO_BLUE();
	Wander( IRoot* lockobj = nullptr );
	~Wander();

	virtual void CalculateBehavior(DroneAgent& agent, const float deltaTime , BehaviorGroup& sys );

	void RenderDebugInfo( Tr2DebugRenderer& renderer, Vector3 agentPos );

private:
	float m_circleDistance;
	float m_circleRadius;
	float m_weightWander;	//priority of behavior
	Vector3 m_wanderForce;

	float m_xPoint, m_yPoint;
	Vector3 m_Tc, m_centerOfCircle, m_desiredVector;
};

TYPEDEF_BLUECLASS( Wander );

#endif