////////////////////////////////////////////////////////////
//
//    Created:   2018
//    Copyright: CCP 2018
//
#pragma once
#ifndef EveChildModifierHaloInverted_H
#define EveChildModifierHaloInverted_H

#include "IEveChildTransformModifier.h"

BLUE_CLASS( EveChildModifierHaloInverted ) :
	public IEveChildTransformModifier
{
public:
	EXPOSE_TO_BLUE();

	EveChildModifierHaloInverted( IRoot* lockobj = NULL );
	~EveChildModifierHaloInverted();

	Matrix ApplyTransform( const Matrix& transform ) const;
};

TYPEDEF_BLUECLASS( EveChildModifierHaloInverted );

#endif