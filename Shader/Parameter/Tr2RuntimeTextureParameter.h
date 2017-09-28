////////////////////////////////////////////////////////////
//
//    Created:   September 2017
//    Copyright: CCP 2017
//
#pragma once

#include "include/ITriEffectParameter.h"

BLUE_DECLARE_INTERFACE( ITr2TextureProvider );

BLUE_CLASS( Tr2RuntimeTextureParameter ): public ITriEffectResourceParameter
{
public:
	Tr2RuntimeTextureParameter( IRoot* lockobj = nullptr );

	EXPOSE_TO_BLUE();

	virtual void CopyValueToEffect( 
		Tr2RenderContextEnum::ShaderType inputType,
		unsigned char* destHandle,
		size_t size,
		Tr2RenderContext &renderContext ) const;
	virtual const char* GetParameterName() const;
	virtual void RebuildEffectHandles( Tr2Shader* effectRes );
	virtual unsigned GetHashValue( unsigned startingHash ) const;

	void Create( const BlueSharedString& name, ITr2TextureProvider* texture );

	void SetTextureProvider( ITr2TextureProvider* texture );
private:
	BlueSharedString m_name;
	ITr2TextureProviderPtr m_texture;
	Tr2EffectResource::Type m_resourceType;
};

TYPEDEF_BLUECLASS( Tr2RuntimeTextureParameter );