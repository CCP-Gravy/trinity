////////////////////////////////////////////////////////////////////////////////
//
// Created:		1/15/2019
// Copyright:	CCP 2019
//

#include "StdAfx.h"
#include "Tr2PPSignalLossEffect.h"
#include "Tr2Renderer.h"


Tr2PPSignalLossEffect::Tr2PPSignalLossEffect( IRoot* lockobj ) :
	m_strength( 0.0f )
{
	// Create the effect
	m_effect.CreateInstance();
	m_effect->StartUpdate();
	m_effect->SetEffectPathName( "res:/Graphics/Effect/Managed/Space/PostProcess/SignalLoss.fx" );
	m_effect->EndUpdate();

	Tr2Renderer::RegisterEffect( m_effect );
}


Tr2PPSignalLossEffect::~Tr2PPSignalLossEffect()
{
}


void Tr2PPSignalLossEffect::Render( Tr2RenderContext& renderContext )
{
	if( m_effect && m_strength )
	{
		// Draw the thing to the backbuffer
		m_effect->StartUpdate();
		m_effect->SetParameter( BlueSharedString( "NoiseStrength" ), m_strength );
		m_effect->EndUpdate();
		Tr2Renderer::DrawScreenQuad( m_effect );
	}
}


