////////////////////////////////////////////////////////////////////////////////
//
// Created:		1/17/2019 
// Copyright:	CCP 2019
//
#pragma once

#ifndef Tr2PPGodRaysEffect_H
#define Tr2PPGodRaysEffect_H

#include "StdAfx.h"
#include "Shader/Tr2Effect.h"
#include "Shader/Parameter/TriTextureParameter.h"
#include "PostProcess/Effects/Tr2PPEffect.h"
#include "PostProcess/Tr2PostProcessRenderInfo.h"


BLUE_DECLARE( Tr2ShaderBuffer );
BLUE_DECLARE( Tr2RenderTarget );

BLUE_CLASS( Tr2PPGodRaysEffect ) :
	public Tr2PPEffect,
	public INotify
{
public:
	EXPOSE_TO_BLUE();

	Tr2PPGodRaysEffect( IRoot* lockobj = NULL );
	~Tr2PPGodRaysEffect();

	void Render( Tr2RenderContext& renderContext, Tr2PostProcessRenderInfo* renderInfo );

	//////////////////////////////////////////////////////////////////////////
	// INotify
	virtual bool OnModified( Be::Var* value );

	
private:
	Color m_godRayColor;
	float m_intensity;
	BlueSharedString m_noiseTexturePath;

	Vector4 m_intensityVector;

	Tr2EffectPtr m_downSampleEffect;
	Tr2EffectPtr m_effect;
};
TYPEDEF_BLUECLASS( Tr2PPGodRaysEffect );

#endif
