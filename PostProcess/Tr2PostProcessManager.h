////////////////////////////////////////////////////////////////////////////////
//
// Created:		January 2019
// Copyright:	CCP 2019
//

#pragma once

#ifndef Tr2PostProcessManager_H
#define Tr2PostProcessManager_H

#include "Tr2PostProcessRenderInfo.h"
#include "Tr2PostProcess2.h"
#include "Shader/Tr2Effect.h"
#include "RenderJob/TriRenderJob.h"
#include "Shader/Tr2ShaderBuffer.h"
#include "Tr2RenderTarget.h"
#include "Tr2RenderContext.h"

BLUE_DECLARE( Tr2PostProcessManager );
BLUE_DECLARE( Tr2PostProcessManager );
BLUE_DECLARE( Tr2PostProcess2 );
BLUE_DECLARE( Tr2Effect );
BLUE_DECLARE( Tr2RenderJob );
BLUE_DECLARE( Tr2ShaderBuffer );
BLUE_DECLARE( Tr2RenderTarget );


BLUE_CLASS( Tr2PostProcessManager ):
	public IRoot
{
public:
	EXPOSE_TO_BLUE();

	Tr2PostProcessManager( IRoot* lockobj = NULL );
	~Tr2PostProcessManager();

	void SetBasePostProcess( Tr2PostProcess2* postProcess );

	void Update();

	void Render( Tr2RenderContext& renderContext, Tr2ShaderBuffer* psData );

private:

	Tr2PostProcess2Ptr m_basePostProcess;
	Tr2PostProcess2Ptr m_finalPostProcess;

	Tr2PostProcessRenderInfoPtr m_renderInfo;
};

TYPEDEF_BLUECLASS( Tr2PostProcessManager );

#endif
