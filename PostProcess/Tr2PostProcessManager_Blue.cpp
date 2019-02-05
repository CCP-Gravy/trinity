////////////////////////////////////////////////////////////////////////////////
//
// Created:		January 2019
// Copyright:	CCP 2019
//

#include "StdAfx.h"
#include "Tr2PostProcessManager.h"
#include "Tr2RenderTarget.h"

BLUE_DEFINE( Tr2PostProcessManager );

const Be::ClassInfo* Tr2PostProcessManager::ExposeToBlue()
{
	EXPOSURE_BEGIN( Tr2PostProcessManager, "" )
		MAP_INTERFACE( IRoot )
		
		MAP_ATTRIBUTE( "basePostProcess", m_basePostProcess, "Accesses the base level post process", Be::READWRITE )
		MAP_ATTRIBUTE( "postProcess", m_finalPostProcess, "Accesses the combined post process", Be::READ )

		MAP_ATTRIBUTE( "renderInfo", m_renderInfo, "Accesses the render information used for the post process effects", Be::READ )

	EXPOSURE_END()
}

