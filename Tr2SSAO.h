////////////////////////////////////////////////////////////////////////////////
//
// Created:   March 2022
// Copyright: CCP 2022
//

#pragma once

#include "Tr2DeviceResource.h"
#include "TriFrustum.h"
#include "ffx_cacao.h"

enum class SSAOQuality
{
	HIGHEST = 0,
	HIGH = 1,
	MEDIUM = 2,
	LOW = 3,
	LOWEST = 4,
};

BLUE_DECLARE( Tr2Effect );
BLUE_DECLARE( Tr2TextureReference );
BLUE_DECLARE( Tr2RenderTarget );
BLUE_DECLARE( Tr2DepthStencil );
BLUE_DECLARE( Tr2GpuBuffer );
BLUE_DECLARE( TriTextureRes );
BLUE_DECLARE_INTERFACE( ITriTextureRes );

BLUE_CLASS( Tr2SSAO ) :
	public INotify,
	public Tr2DeviceResource
{
public:
	EXPOSE_TO_BLUE();

	Tr2SSAO( IRoot* lockobj = NULL );
	~Tr2SSAO();

	void ReleaseResources( TriStorage s );
	bool OnPrepareResources();

	bool IsValid();

	bool OnModified( Be::Var* value );

	void SetInputBuffers( Tr2DepthStencilPtr depthBuffer, Tr2RenderTargetPtr normalBuffer );

	void Filter( Tr2RenderContext& renderContext );

	Tr2RenderTargetPtr GetOutput() const;

private:
	static constexpr unsigned SSAO_PASS_COUNT = 4;

	HRESULT ApplyConstBuffer( unsigned pass, Tr2RenderContext& renderContext );
	void PerformPass( SSAOQuality quality, const FFX_CACAO_Settings& settingsTemplate, float zoomLevel, Tr2Effect* ssaoEffect, Tr2RenderContext& renderContext );
	void UpdateEffect( Tr2Effect * ssaoEffect, uint32_t blurPassCount );

	SSAOQuality m_ssaoQuality = SSAOQuality::HIGHEST;

	bool m_initialized = false;
	bool m_enabled = true;
	bool m_downsampledSSAO = false;
	bool m_largeEffect = true;
	float m_zoomLevel = 5.f;
	float m_zoomLevelLarge = 1300.f;

	FFX_CACAO_Settings m_settings;
	FFX_CACAO_Settings m_settingsLarge;

	Tr2EffectPtr m_ssaoEffect;
	Tr2EffectPtr m_ssaoLargeEffect;

	Tr2ConstantBufferAL m_constBuffers[SSAO_PASS_COUNT + 1]{};

	// Input
	Tr2DepthStencilPtr m_inputDepthBuffer;
	Tr2RenderTargetPtr m_inputNormalBuffer;

	// Prepare
	Tr2TextureAL m_deinterleavedDepthTexture;
	Tr2TextureAL m_deinterleavedNormalTexture;
	Tr2RenderTargetPtr m_deinterleavedDepthTarget;
	Tr2RenderTargetPtr m_deinterleavedNormalTarget;

	// SSAO
	Tr2TextureAL m_ssaoWorkerTextureA;
	Tr2TextureAL m_ssaoWorkerTextureB;
	Tr2RenderTargetPtr m_ssaoWorkerTargetA;
	Tr2RenderTargetPtr m_ssaoWorkerTargetB;
	Tr2GpuBufferPtr m_loadCounterBuffer;

	// Importance
	Tr2RenderTargetPtr m_importanceTargetA;
	Tr2RenderTargetPtr m_importanceTargetB;

	// Output
	TriTextureResPtr m_blankOutputTexture;
	Tr2RenderTargetPtr m_outputTarget;
};

TYPEDEF_BLUECLASS( Tr2SSAO );
