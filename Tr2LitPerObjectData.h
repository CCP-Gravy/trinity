#pragma once

#ifndef Tr2LitPerObjectData_h
#define Tr2LitPerObjectData_h

#include "Tr2PerObjectData.h"

// --------------------------------------------------------------------------------------
// Description:
//   Per-object data for lit objects.
// --------------------------------------------------------------------------------------
class Tr2LitPerObjectData : public Tr2PerObjectDataStandard
{
public:
	// Constructor
	Tr2LitPerObjectData() 
		: m_numPointLights( 0 )
	{
		m_padding[0] = m_padding[1] = m_padding[2] = 0;
	}

	virtual void SetPerObjectDataToDevice( Tr2ConstantBufferAL** buffers, unsigned constantTypeMask, Tr2RenderContext& renderContext ) const
	{
		Tr2PerObjectDataStandard::SetPerObjectDataToDevice( buffers, constantTypeMask, renderContext );
		renderContext.SetNumberOfLights( m_numPointLights );
	}

	// ----------------------------------------------------------------------------------
	// Description:
	//   Sets the number of active point and spot lights.
	// Arguments:
	//   numPointLights - The number of active point lights
	//   numSpotLights - The number of active spot lights
	// ----------------------------------------------------------------------------------
	void SetLightsActive( int32_t numPointLights, int32_t numSpotLights )
	{
		m_numPointLights = numPointLights;
	}

private:
	// Number of point lights
	int32_t m_numPointLights;
	// Padding
	int32_t m_padding[3];
};

// --------------------------------------------------------------------------------------
// Description:
//   Per-object data for skinned, lit objects
// --------------------------------------------------------------------------------------
class Tr2LitPerObjectDataSkinned : public Tr2PerObjectDataSkinned
{
public:
	// Constructor
	Tr2LitPerObjectDataSkinned() 
		: m_numPointLights( 0 ) 
	{
		m_padding[0] = m_padding[1] = m_padding[2] = 0;
	}

	virtual void SetPerObjectDataToDevice( Tr2ConstantBufferAL** buffers, unsigned constantTypeMask, Tr2RenderContext& renderContext ) const
	{
		Tr2PerObjectDataSkinned::SetPerObjectDataToDevice( buffers, constantTypeMask, renderContext );
		renderContext.SetNumberOfLights( m_numPointLights );
	}

	// ----------------------------------------------------------------------------------
	// Description:
	//   Sets the number of active point and spot lights.
	// Arguments:
	//   numPointLights - The number of active point lights
	//   numSpotLights - The number of active spot lights
	// ----------------------------------------------------------------------------------
	void SetLightsActive( unsigned int numPointLights, unsigned int numSpotLights )
	{
		m_numPointLights = numPointLights;
	}

private:
	// Number of point lights
	int32_t m_numPointLights;
	// Padding
	int32_t m_padding[3];
};

#endif
