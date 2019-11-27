////////////////////////////////////////////////////////////////////////////////
//
// Created:		November 2019
// Copyright:	CCP 2019
//

#pragma once

#include "PostProcess/Effects/Tr2PPEffect.h"

BLUE_DECLARE( Tr2RenderTarget );


BLUE_CLASS( Tr2PPFidelityFXEffect ) :
	public Tr2PPEffect
{
public:
	EXPOSE_TO_BLUE();

	Tr2PPFidelityFXEffect( IRoot* lockobj = NULL );
	~Tr2PPFidelityFXEffect();

	// Tr2PPEffect
	bool IsActive() override;

	float m_intensity;
};

TYPEDEF_BLUECLASS( Tr2PPFidelityFXEffect );