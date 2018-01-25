////////////////////////////////////////////////////////////
//
//    Created:   2018
//    Copyright: CCP 2018
//
#pragma once
#ifndef EveChildModifierHalo_H
#define EveChildModifierHalo_H

#include "IEveChildTransformModifier.h"

BLUE_CLASS( EveChildModifierHalo ) :
	public IEveChildTransformModifier
{
public:
	EXPOSE_TO_BLUE();

	EveChildModifierHalo( IRoot* lockobj = NULL );
	~EveChildModifierHalo();

	Matrix ApplyTransform( const Matrix& transform ) const;
};

TYPEDEF_BLUECLASS( EveChildModifierHalo );

#endif