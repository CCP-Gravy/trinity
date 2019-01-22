////////////////////////////////////////////////////////////////////////////////
//
// Created:		January 2019
// Copyright:	CCP 2019
//

#pragma once

#ifndef Tr2PostProcessManager_H
#define Tr2PostProcessManager_H

#include "Tr2PostProcess2.h"
#include "Shader/Tr2Effect.h"
#include "RenderJob/TriRenderJob.h"
#include "Shader/Tr2ShaderBuffer.h"
#include "Tr2RenderTarget.h"
#include "Tr2RenderContext.h"

BLUE_DECLARE( Tr2PostProcessManager );
BLUE_DECLARE( Tr2PostProcess2 );
BLUE_DECLARE( Tr2Effect );
BLUE_DECLARE( Tr2RenderJob );
BLUE_DECLARE( Tr2ShaderBuffer );
BLUE_DECLARE( Tr2RenderTarget );


BLUE_CLASS( Tr2PostProcessManager ):
	public INotify
{
public:
	EXPOSE_TO_BLUE();

	Tr2PostProcessManager( IRoot* lockobj = NULL );
	~Tr2PostProcessManager();

	void SetBasePostProcess( Tr2PostProcess2Ptr postProcess );

	void Update();

	void Render( Tr2ShaderBufferPtr m_psData, Tr2RenderContext& renderContext );

	void CreateBuffers(uint32_t width, uint32_t height);

	//////////////////////////////////////////////////////////////////////////
	// INotify
	virtual bool OnModified( Be::Var* value );

private:
	void CopySourceTo( Tr2RenderTargetPtr renderTarget );

	Tr2PostProcess2Ptr m_basePostProcess;
	Tr2PostProcess2Ptr m_finalPostProcess;

	// Buffers
	Tr2RenderTargetPtr m_sourceBuffer;
	Tr2RenderTargetPtr m_destBuffer;
	Tr2RenderTargetPtr m_velocityBuffer;
	Tr2RenderTargetPtr m_distortionBuffer;
	Tr2RenderTargetPtr m_accumulationBuffer;

	Tr2RenderTargetPtr m_rt1;
	Tr2RenderTargetPtr m_rt2;
};

TYPEDEF_BLUECLASS( Tr2PostProcessManager );

#endif
