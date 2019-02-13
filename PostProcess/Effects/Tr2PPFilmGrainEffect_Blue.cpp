////////////////////////////////////////////////////////////////////////////////
//
// Created:		February 2019
// Copyright:	CCP 2019
//

#include "StdAfx.h"
#include "Tr2PPFilmGrainEffect.h"

BLUE_DEFINE( Tr2PPFilmGrainEffect );

const Be::ClassInfo* Tr2PPFilmGrainEffect::ExposeToBlue()
{
	EXPOSURE_BEGIN( Tr2PPFilmGrainEffect, "" )
		MAP_INTERFACE( Tr2PPEffect )

		MAP_ATTRIBUTE( "intensity", m_intensity, "Film grain intensity", Be::READWRITE | Be::PERSIST | Be::NOTIFY )
		MAP_ATTRIBUTE( "colored", m_colored, "If film grain is grayscale or colored", Be::READWRITE | Be::PERSIST | Be::NOTIFY )
		MAP_ATTRIBUTE( "colorAmount", m_colorAmount, "Color amount in film grain if ColoredGrain is set", Be::READWRITE | Be::PERSIST | Be::NOTIFY )
		MAP_ATTRIBUTE( "grainSize", m_grainSize, "Grain size in pixels", Be::READWRITE | Be::PERSIST | Be::NOTIFY )
		MAP_ATTRIBUTE( "luminanceExponent", m_luminanceExponent, "Grain intensity falloff with brightness", Be::READWRITE | Be::PERSIST | Be::NOTIFY )

		EXPOSURE_CHAINTO( Tr2PPEffect )
}
