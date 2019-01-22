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
		MAP_INTERFACE( INotify )
		
		MAP_ATTRIBUTE( "basePostProcess", m_basePostProcess, "Accesses the base level post process", Be::READWRITE )
		MAP_ATTRIBUTE( "postProcess", m_finalPostProcess, "Accesses the combined post process", Be::READ )

		MAP_ATTRIBUTE( "destBuffer", m_destBuffer, "The destination buffer of the post process", Be::READWRITE )
		MAP_ATTRIBUTE( "sourceBuffer", m_sourceBuffer, "The source buffer of the post process", Be::READWRITE | Be::NOTIFY)
		MAP_ATTRIBUTE( "velocityBuffer", m_velocityBuffer, "The velocity buffer of the post process", Be::READWRITE )
		MAP_ATTRIBUTE( "accumulationBuffer", m_accumulationBuffer, "The accumulation buffer of the post process", Be::READWRITE )

		MAP_ATTRIBUTE( "rt1", m_rt1, "One of the render buffers", Be::READWRITE )
		MAP_ATTRIBUTE( "rt2", m_rt2, "the other render buffer", Be::READWRITE )
		
		MAP_METHOD_AND_WRAP("CreateBuffers", CreateBuffers, "Creates the rendertargets with the correct width and height")
		

	EXPOSURE_END()
}

