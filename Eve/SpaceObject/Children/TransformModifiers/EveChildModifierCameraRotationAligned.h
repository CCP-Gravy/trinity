////////////////////////////////////////////////////////////
//
//    Created:   2018
//    Copyright: CCP 2018
//
#pragma once
#ifndef EveChildModifierCameraRotationAligned_H
#define EveChildModifierCameraRotationAligned_H

#include "IEveChildTransformModifier.h"

BLUE_CLASS( EveChildModifierCameraRotationAligned ) :
	public IEveChildTransformModifier
{
public:
	EXPOSE_TO_BLUE();

	EveChildModifierCameraRotationAligned( IRoot* lockobj = NULL );
	~EveChildModifierCameraRotationAligned();

	Matrix ApplyTransform( const Matrix& transform ) const;
};

TYPEDEF_BLUECLASS( EveChildModifierCameraRotationAligned );

#endif