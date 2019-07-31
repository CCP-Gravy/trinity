#pragma once
#ifndef FollowASpline_H
#define FollowASpline_H
#include "Eve/SpaceObject/Children/EveChildBehaviorSystem.h"
#include "IBehavior.h"

BLUE_DECLARE( TriCurveSet );

BLUE_CLASS( FollowASpline ) :
	public IBehavior
{
public:
	EXPOSE_TO_BLUE();
	FollowASpline( IRoot* lockobj = nullptr );
	~FollowASpline();

	virtual void CalculateBehavior( std::vector<DroneAgent>& agents, const float deltaTime , BehaviorGroup& group , EveChildBehaviorSystem& system );
	void RenderDebugInfo( Tr2DebugRenderer& renderer, Vector3 agentPos );

private:
	float m_behaviorWeight;	
	float m_smoothPullFactor;
	Vector3 m_pullForce;
	Vector3 m_desiredVector;
};

TYPEDEF_BLUECLASS( FollowASpline );

#endif
