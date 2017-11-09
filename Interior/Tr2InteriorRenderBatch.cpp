#include "StdAfx.h"

#include "Tr2InteriorRenderBatch.h"
#include "Resources/TriGeometryRes.h"


// -----------------------------------------------------------------------------------------------------
// Description
//   Draws the cubemap using a screenspace quad.
// -----------------------------------------------------------------------------------------------------
void Tr2InteriorBackgroundCubemapBatch::SubmitGeometry( Tr2RenderContext& renderContext )
{
	using namespace Tr2RenderContextEnum;
	
	Tr2Renderer::DrawCameraSpaceScreenQuad( this->GetShaderStateInterface() , this->GetShaderMaterialInterface() );
}

