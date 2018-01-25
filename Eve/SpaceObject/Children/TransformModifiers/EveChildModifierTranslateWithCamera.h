////////////////////////////////////////////////////////////
//
//    Created:   2018
//    Copyright: CCP 2018
//
#pragma once
#ifndef EveChildModifierTranslateWithCamera_H
#define EveChildModifierTranslateWithCamera_H

#include "IEveChildTransformModifier.h"

BLUE_CLASS( EveChildModifierTranslateWithCamera ) :
	public IEveChildTransformModifier
{
public:
	EXPOSE_TO_BLUE();

	EveChildModifierTranslateWithCamera( IRoot* lockobj = NULL );
	~EveChildModifierTranslateWithCamera();

	Matrix ApplyTransform( const Matrix& transform ) const;
};

TYPEDEF_BLUECLASS( EveChildModifierTranslateWithCamera );

#endif