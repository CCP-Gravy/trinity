////////////////////////////////////////////////////////////////////////////////
//
// Created:		1/15/2019 
// Copyright:	CCP 2019
//

#pragma once

#ifndef Tr2PPSignalLossEffect_H
#define Tr2PPSignalLossEffect_H

#include "StdAfx.h"
#include "Shader/Tr2Effect.h"
#include "PostProcess/Effects/Tr2PPEffect.h"
#include "PostProcess/Tr2PostProcessRenderInfo.h"


BLUE_CLASS( Tr2PPSignalLossEffect ) :
	public Tr2PPEffect,
	public INotify
{
public:
	EXPOSE_TO_BLUE();

	Tr2PPSignalLossEffect( IRoot* lockobj = NULL );
	~Tr2PPSignalLossEffect();
	
	void Render( Tr2RenderContext& renderContext, Tr2PostProcessRenderInfo* renderInfo );
	
	//////////////////////////////////////////////////////////////////////////
	// INotify
	virtual bool OnModified( Be::Var* value );

	//////////////////////////////////////////////////////////////////////////
	// Tr2PPEffect
	bool IsActive() override;

private:
	float m_strength;
	Tr2EffectPtr m_effect;
};
TYPEDEF_BLUECLASS( Tr2PPSignalLossEffect );

#endif
