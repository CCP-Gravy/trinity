////////////////////////////////////////////////////////////
//
//    Created:   2018
//    Copyright: CCP 2018
//
#include "StdAfx.h"
#include "EveChildModifierCameraRotationAligned.h"
#include "Tr2Renderer.h"
#include "EveChildModifierTransformCommon.h"

EveChildModifierCameraRotationAligned::EveChildModifierCameraRotationAligned( IRoot* lockobj )
{
}

EveChildModifierCameraRotationAligned::~EveChildModifierCameraRotationAligned()
{
}

Matrix EveChildModifierCameraRotationAligned::ApplyTransform( const Matrix& transform ) const
{
	Matrix alignMat;
	float distCenter;
	Vector3 d;
	DistanceBase( transform, alignMat, distCenter, d );

	return alignMat * transform;
}