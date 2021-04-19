#pragma once

#include "Eve/EveUpdateContext.h"
#include "Eve/SpaceObject/Children/IEveSpaceObjectChild.h"

#include "IEveFxAttribute.h"


BLUE_CLASS( EveSpaceObjectFxAttributes ) :
	public IEveFxAttribute
{
public:
	EXPOSE_TO_BLUE();
	EveSpaceObjectFxAttributes( IRoot* lockobj = nullptr );
	~EveSpaceObjectFxAttributes();
	
	void UpdateAsyncronous( EveUpdateContext & updateContext, const EveChildUpdateParams& params ) override;

private:
	// Controls
	BlueSharedString m_name;

	float m_distanceToShip;
	float m_boundingSphereRadius;
	float m_distanceToChildParent;
};

TYPEDEF_BLUECLASS( EveSpaceObjectFxAttributes );