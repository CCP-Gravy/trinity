////////////////////////////////////////////////////////////
//
//    Created:   2018
//    Copyright: CCP 2018
//
#include "StdAfx.h"
#include "EveChildModifierCameraRotationAligned.h"

BLUE_DEFINE( EveChildModifierCameraRotationAligned );

const Be::ClassInfo* EveChildModifierCameraRotationAligned::ExposeToBlue()
{
	EXPOSURE_BEGIN( EveChildModifierCameraRotationAligned, "" )
		MAP_INTERFACE( EveChildModifierCameraRotationAligned )
		MAP_INTERFACE( IEveChildTransformModifier )

	EXPOSURE_END()
}