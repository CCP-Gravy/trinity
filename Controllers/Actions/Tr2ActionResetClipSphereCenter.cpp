#include "StdAfx.h"
#include "Tr2ActionResetClipSphereCenter.h"
#include "Controllers/Tr2Controller.h"
#include "Eve/SpaceObject/EveSpaceObject2.h"


void Tr2ActionResetClipSphereCenter::Start( Tr2Controller& controller )
{
	if( EveSpaceObject2Ptr owner = BlueCastPtr( controller.GetOwner() ) )
	{
		owner->ResetClipSphereCenter();
	}
}