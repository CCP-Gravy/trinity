#include "StdAfx.h"
#include "EveSpaceObjectFxAttributes.h"

BLUE_DEFINE( EveSpaceObjectFxAttributes );

const Be::ClassInfo* EveSpaceObjectFxAttributes::ExposeToBlue()
{
	EXPOSURE_BEGIN( EveSpaceObjectFxAttributes, "" )
		MAP_INTERFACE( EveSpaceObjectFxAttributes )
		MAP_INTERFACE( IEveFxAttribute )
		
		MAP_ATTRIBUTE( "name", m_name, "", Be::READWRITE | Be::PERSIST )

		MAP_ATTRIBUTE( "boundingSphereRadius", m_boundingSphereRadius, "SpaceObject Parent bounding sphere radius \n:jessica-group: General", Be::READ )
	
		MAP_ATTRIBUTE( "ship", m_distanceToShip, "player ship distance to spaceObject-parent \n:jessica-group: DistanceTo", Be::READ )
		MAP_ATTRIBUTE( "childParent", m_distanceToChildParent, "distance to closest-parent \n:jessica-group: DistanceTo", Be::READ )
		
	EXPOSURE_END()
}