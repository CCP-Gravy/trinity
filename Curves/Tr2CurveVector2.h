////////////////////////////////////////////////////////////
//
//    Created:   May 2017
//    Copyright: CCP 2017
//

#pragma once

#include "Include/ITriFunction.h"
#include "Include/ITriCurveLength.h"
#include "Tr2CurveScalar.h"


BLUE_CLASS( Tr2CurveVector2 ) :
	public ITriCurveLength,
	public ITriFunction
{
public:
	Tr2CurveVector2( IRoot* lockobj = nullptr );

	EXPOSE_TO_BLUE();

	virtual void UpdateValue( double time );

	virtual float Length();

	Vector2 GetValue( double time ) const;
private:
	std::string m_name;

	PTr2CurveScalar m_x;
	PTr2CurveScalar m_y;

	Vector3 m_currentValue;
};

TYPEDEF_BLUECLASS( Tr2CurveVector2 );
