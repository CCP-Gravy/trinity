////////////////////////////////////////////////////////////
//
//    Created:   September 2017
//    Copyright: CCP 2017
//

#include "StdAfx.h"
#include "Tr2RuntimeTextureParameter.h"
#include "ITr2TextureProvider.h"
#include "Shader/Tr2Shader.h"
#include "Tr2Renderer.h"

// --------------------------------------------------------------------------------------
Tr2RuntimeTextureParameter::Tr2RuntimeTextureParameter( IRoot* lockobj )
	:m_resourceType( Tr2EffectResource::TEXTURE_TYPELESS )
{
}

// --------------------------------------------------------------------------------------
void Tr2RuntimeTextureParameter::CopyValueToEffect(
	Tr2RenderContextEnum::ShaderType inputType,
	unsigned char* destHandle,
	size_t resourceFlags,
	Tr2RenderContext &renderContext ) const
{
	unsigned int ix = *destHandle;
	bool isUav = ( resourceFlags & RESOURCE_FLAG_UAV ) != 0;
	if( Tr2TextureAL* tex = ( m_texture ? m_texture->GetTexture() : nullptr ) )
	{
		if( isUav )
		{
			renderContext.SetUav( inputType, ix, *tex );
		}
		else
		{
			bool isSrgb = ( resourceFlags & RESOURCE_FLAG_SRGB ) != 0;
			auto colorSpace = isSrgb ? Tr2RenderContextEnum::COLOR_SPACE_SRGB : Tr2RenderContextEnum::COLOR_SPACE_LINEAR;
			renderContext.m_esm.ApplyTexture( inputType, ix, *tex, colorSpace );
		}
	}
	else
	{
		if( isUav )
		{
			// TODO: Fix the signature of SetUav to take a const reference
			renderContext.SetUav( inputType, ix, const_cast<Tr2TextureAL&>( nullTX ) );
		}
		else
		{
			Tr2Renderer::ApplyFallbackTexture( inputType, ix, m_resourceType, m_name.c_str(), renderContext );
		}
	}
}

// --------------------------------------------------------------------------------------
const char* Tr2RuntimeTextureParameter::GetParameterName() const
{
	return m_name.c_str();
}

// --------------------------------------------------------------------------------------
void Tr2RuntimeTextureParameter::RebuildEffectHandles( Tr2Shader* effectRes )
{
	if( m_name.empty() || !effectRes )
	{
		return;
	}

	auto resource = effectRes->GetResource( m_name.c_str() );
	if( !resource )
	{
		return;
	}
	m_resourceType = resource->type;
}

// --------------------------------------------------------------------------------------
unsigned Tr2RuntimeTextureParameter::GetHashValue( unsigned startingHash ) const
{
	return CcpHashFNV1( m_texture.p, sizeof( m_texture.p ), startingHash );
}

// --------------------------------------------------------------------------------------
void Tr2RuntimeTextureParameter::Create( const BlueSharedString& name, ITr2TextureProvider* texture )
{
	m_name = name;
	m_texture = texture;
}

// --------------------------------------------------------------------------------------
void Tr2RuntimeTextureParameter::SetTextureProvider( ITr2TextureProvider* texture )
{
	m_texture = texture;
}