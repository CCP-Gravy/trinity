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

BLUE_CLASS( Tr2PPSignalLossEffect ) :
	public IRoot
{
public:
	EXPOSE_TO_BLUE();

	Tr2PPSignalLossEffect( IRoot* lockobj = NULL );
	~Tr2PPSignalLossEffect();
	
	void Render( Tr2RenderContext& renderContext );

private:
	float m_strength;
	Tr2EffectPtr m_effect;
};
TYPEDEF_BLUECLASS( Tr2PPSignalLossEffect );

#endif
