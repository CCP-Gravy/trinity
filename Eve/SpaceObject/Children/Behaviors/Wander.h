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

	virtual void CalculateBehavior( std::vector<DroneAgent>& agents, const float deltaTime, BehaviorGroup& sys, EveChildBehaviorSystem& system );

	void RenderDebugInfo( Tr2DebugRenderer& renderer, Vector3 agentPos );

private:
	float m_freq;
	float m_weightWander;	//priority of behavior

	//debugging purposes
	float rand1, rand2, rand3;
};

TYPEDEF_BLUECLASS( Wander );

#endif