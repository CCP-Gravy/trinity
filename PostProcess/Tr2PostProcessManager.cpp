////////////////////////////////////////////////////////////////////////////////
//
// Created:		January 2019
// Copyright:	CCP 2019
//

#pragma once

#include "StdAfx.h"
#include "Tr2Renderer.h"
#include "Tr2PostProcessManager.h"
#include "RenderJob\TriStepSetStandardRenderStates.h"


Tr2PostProcessManager::Tr2PostProcessManager( IRoot* lockobj )
{
	m_renderInfo.CreateInstance();
	
	m_basePostProcess.CreateInstance();
}


Tr2PostProcessManager::~Tr2PostProcessManager()
{
	
}


void Tr2PostProcessManager::SetBasePostProcess( Tr2PostProcess2* postProcess )
{
	m_basePostProcess = postProcess;
}


void Tr2PostProcessManager::Update()
{
	m_finalPostProcess = m_basePostProcess;
}


void Tr2PostProcessManager::Render( Tr2RenderContext& renderContext, Tr2ShaderBuffer* psData )
{
	m_renderInfo->SetPerFrameData( psData );
	m_finalPostProcess->Render( renderContext, m_renderInfo );
	
}
