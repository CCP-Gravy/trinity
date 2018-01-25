////////////////////////////////////////////////////////////
//
//    Created:   2018
//    Copyright: CCP 2018
//
#pragma once
#ifndef EveChildTransformCommon_H
#define EveChildTransformCommon_H

#include "StdAfx.h"
#include "include/TriMath.h"

inline void DistanceBase( const Matrix &transform, Matrix& alignMat, float& distCenter, Vector3& d )
{
	const Vector3& myPos = transform.GetTranslation();
	const Vector3& camPos = Tr2Renderer::GetViewPosition();
	d = camPos - myPos;

	Vector3 camFwd = d;
	Matrix parentT = Transpose( transform );
	TriVectorRotateMatrix( &camFwd, &camFwd, &parentT );

	float lengthSq = LengthSq( transform.GetX() );
	camFwd.x /= lengthSq;
	lengthSq = LengthSq( transform.GetY() );
	camFwd.y /= lengthSq;
	lengthSq = LengthSq( transform.GetZ() );
	camFwd.z /= lengthSq;

	distCenter = Length( camFwd );
	camFwd = Normalize( camFwd );

	const Matrix& viewMatrix = Tr2Renderer::GetViewTransform();
	Vector3 right( viewMatrix._11, viewMatrix._21, viewMatrix._31 );
	TriVectorRotateMatrix( &right, &right, &parentT );

	Vector3 up = Normalize( Cross( camFwd, right ) );

	TriMatrixChangeBase( &alignMat, &camFwd, &up );
}

#endif