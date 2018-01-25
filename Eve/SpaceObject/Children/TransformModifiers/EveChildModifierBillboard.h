////////////////////////////////////////////////////////////
//
//    Created:   2018
//    Copyright: CCP 2018
//
#pragma once
#ifndef EveChildModifierBillboard_H
#define EveChildModifierBillboard_H

#include "IEveChildTransformModifier.h"

BLUE_CLASS( EveChildModifierBillboard ) :
	public IEveChildTransformModifier
{
public:
	EXPOSE_TO_BLUE();

	EveChildModifierBillboard( IRoot* lockobj = NULL );
	~EveChildModifierBillboard();

	Matrix ApplyTransform( const Matrix& transform ) const;
};

TYPEDEF_BLUECLASS( EveChildModifierBillboard );

#endif