////////////////////////////////////////////////////////////////////////////////
//
// Created:		November 2019
// Copyright:	CCP 2019
//

#include "StdAfx.h"
#include "Tr2PPFidelityFXEffect.h"

BLUE_DEFINE( Tr2PPFidelityFXEffect );

const Be::ClassInfo* Tr2PPFidelityFXEffect::ExposeToBlue()
{
	EXPOSURE_BEGIN( Tr2PPFidelityFXEffect, "" )
		MAP_INTERFACE( Tr2PPEffect )

		MAP_ATTRIBUTE( "intensity", m_intensity, "Intensity of sharpness filter", Be::READWRITE | Be::PERSIST | Be::NOTIFY )

		EXPOSURE_CHAINTO( Tr2PPEffect )
}