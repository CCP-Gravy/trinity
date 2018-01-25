////////////////////////////////////////////////////////////
//
//    Created:   2018
//    Copyright: CCP 2018
//
#include "StdAfx.h"
#include "EveChildModifierBillboard.h"

BLUE_DEFINE( EveChildModifierBillboard );

const Be::ClassInfo* EveChildModifierBillboard::ExposeToBlue()
{
	EXPOSURE_BEGIN( EveChildModifierBillboard, "" )
		MAP_INTERFACE( EveChildModifierBillboard )
		MAP_INTERFACE( IEveChildTransformModifier )

	EXPOSURE_END()
}