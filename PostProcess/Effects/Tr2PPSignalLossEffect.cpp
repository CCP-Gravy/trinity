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
}


Tr2PPSignalLossEffect::~Tr2PPSignalLossEffect()
{
}


bool Tr2PPSignalLossEffect::OnModified( Be::Var* value )
{
	m_effect->StartUpdate();
	m_effect->SetParameter( BlueSharedString( "NoiseStrength" ), m_strength );
	m_effect->EndUpdate();
	return true;
}


bool Tr2PPSignalLossEffect::IsActive()
{
	return m_display && m_strength > 0.0f;
}


void Tr2PPSignalLossEffect::Render( Tr2RenderContext& renderContext, Tr2PostProcessRenderInfo* renderInfo )
{
	if( IsActive() )
	{
		Tr2Renderer::DrawScreenQuad( m_effect );	
	}
}


