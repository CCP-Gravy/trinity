////////////////////////////////////////////////////////////
//
//    Created:   2018
//    Copyright: CCP 2018
//
#include "StdAfx.h"
#include "EveChildModifierTranslateWithCamera.h"

BLUE_DEFINE( EveChildModifierTranslateWithCamera );

const Be::ClassInfo* EveChildModifierTranslateWithCamera::ExposeToBlue()
{
	EXPOSURE_BEGIN( EveChildModifierTranslateWithCamera, "" )
		MAP_INTERFACE( EveChildModifierTranslateWithCamera )
		MAP_INTERFACE( IEveChildTransformModifier )

	EXPOSURE_END()
}