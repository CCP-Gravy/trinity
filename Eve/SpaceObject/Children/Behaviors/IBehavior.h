#pragma once
#ifndef IBehavior_h
#define IBehavior_h

BLUE_INTERFACE( IBehavior ): public IRoot
{
public:
	virtual void IBehavior::CalculateBehavior( DroneAgent& agent, const float deltaTime ) = 0;
	virtual void IBehavior::RenderDebugInfo( Tr2DebugRenderer& renderer, Vector3 agentPos ) = 0;
};

#endif
