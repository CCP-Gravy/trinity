////////////////////////////////////////////////////////////
//
//    Created:   May 2017
//    Copyright: CCP 2017
//

#include "StdAfx.h"
#include "Tr2CurveVector2.h"

BLUE_DEFINE( Tr2CurveVector2 );

const Be::ClassInfo* Tr2CurveVector2::ExposeToBlue()
{
	EXPOSURE_BEGIN( Tr2CurveVector2, ":jessica-icon: tree/trivectorcurve.png" )
		MAP_INTERFACE( Tr2CurveVector2 )
		MAP_INTERFACE( ITriFunction )
		MAP_INTERFACE( ITriCurveLength )

		MAP_ATTRIBUTE(
			"name",
			m_name,
			"",
			Be::READWRITE | Be::PERSIST )
		MAP_ATTRIBUTE(
			"x",
			m_x,
			"X component curve",
			Be::READ | Be::PERSIST )
		MAP_ATTRIBUTE(
			"y",
			m_y,
			"Y component curve",
			Be::READ | Be::PERSIST )
		MAP_ATTRIBUTE(
			"currentValue",
			m_currentValue,
			"Curve value after the last update",
			Be::READ )

		MAP_METHOD_AND_WRAP(
			"GetValueAt",
			GetValue,
			"Returns curve value at specified time\n"
			":param time: input time"
		)

	EXPOSURE_END()
}