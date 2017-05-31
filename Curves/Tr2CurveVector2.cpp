////////////////////////////////////////////////////////////
//
//    Created:   May 2017
//    Copyright: CCP 2017
//

#include "StdAfx.h"
#include "Tr2CurveVector2.h"
#include "Tr2CurveScalar.h"


// --------------------------------------------------------------------------------
Tr2CurveVector2::Tr2CurveVector2( IRoot* lockobj )
	:PARENTLOCK( m_x ),
	PARENTLOCK( m_y ),
	m_currentValue( 0, 0, 0 )
{
}

// --------------------------------------------------------------------------------
void Tr2CurveVector2::UpdateValue( double time )
{
	m_currentValue.x = m_x.Update( time );
	m_currentValue.y = m_y.Update( time );
}

// --------------------------------------------------------------------------------
float Tr2CurveVector2::Length()
{
	return std::max( m_x.Length(), m_y.Length() );
}

// --------------------------------------------------------------------------------
Vector2 Tr2CurveVector2::GetValue( double time ) const
{
	return Vector2( m_x.GetValue( time ), m_y.GetValue( time ) );
}
