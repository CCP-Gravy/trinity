#include "StdAfx.h"
#include "EveSpaceObjectFxAttributes.h"
#include "Tr2Renderer.h"

EveSpaceObjectFxAttributes::EveSpaceObjectFxAttributes( IRoot* lockobj ) :
	m_distanceToShip( 0 ),
	m_boundingSphereRadius( 0 ),
	m_distanceToChildParent( 0 )
{
}

EveSpaceObjectFxAttributes::~EveSpaceObjectFxAttributes()
{
}

void EveSpaceObjectFxAttributes::UpdateAsyncronous( EveUpdateContext& updateContext, const EveChildUpdateParams& params )
{
	// gather attributes
	Vector3 objPos;
	Vector4 sphere;
	params.spaceObjectParent->GetBoundingSphere( sphere );
	params.spaceObjectParent->GetModelCenterWorldPosition( objPos );

	m_distanceToShip = Length( objPos ) - m_boundingSphereRadius;
	m_boundingSphereRadius = sphere.w;	
}