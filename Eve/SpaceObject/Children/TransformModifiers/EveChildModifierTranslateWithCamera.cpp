////////////////////////////////////////////////////////////
//
//    Created:   2018
//    Copyright: CCP 2018
//
#include "StdAfx.h"
#include "EveChildModifierTranslateWithCamera.h"
#include "Tr2Renderer.h"

EveChildModifierTranslateWithCamera::EveChildModifierTranslateWithCamera( IRoot* lockobj )
{
}

EveChildModifierTranslateWithCamera::~EveChildModifierTranslateWithCamera()
{
}

Matrix EveChildModifierTranslateWithCamera::ApplyTransform( const Matrix& transform ) const
{
	Matrix result = transform;
	result.GetTranslation() += Tr2Renderer::GetViewPosition();
	return result;
}