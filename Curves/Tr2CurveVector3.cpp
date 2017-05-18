////////////////////////////////////////////////////////////
//
//    Created:   May 2017
//    Copyright: CCP 2017
//

#include "StdAfx.h"
#include "Tr2CurveVector3.h"
#include "Tr2CurveScalar.h"


Tr2CurveVector3::Tr2CurveVector3( IRoot* lockobj )
	:PARENTLOCK( m_x ),
	PARENTLOCK( m_y ),
	PARENTLOCK( m_z ),
	m_currentValue( 0, 0, 0 )
{
}

void Tr2CurveVector3::UpdateValue( double time )
{
	m_currentValue.x = m_x.Update( time );
	m_currentValue.y = m_y.Update( time );
	m_currentValue.z = m_z.Update( time );
}

float Tr2CurveVector3::Length()
{
	return std::max( std::max( m_x.Length(), m_y.Length() ), m_z.Length() );
}

Vector3 Tr2CurveVector3::GetValue( double time ) const
{
	return Vector3( m_x.GetValue( time ), m_y.GetValue( time ), m_z.GetValue( time ) );
}
