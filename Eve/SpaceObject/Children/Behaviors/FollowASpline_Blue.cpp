#include "StdAfx.h"
#include "FollowASpline.h"

BLUE_DEFINE_INTERFACE( IBehavior );

BLUE_DEFINE( FollowASpline );

const Be::ClassInfo* FollowASpline::ExposeToBlue()
{
	EXPOSURE_BEGIN( FollowASpline, "" )
		MAP_INTERFACE( FollowASpline )
		MAP_INTERFACE( IBehavior )

		MAP_ATTRIBUTE( "behaviorWeight", m_behaviorWeight, ":jessica-group: followASpline", Be::READWRITE | Be::PERSIST )

	EXPOSURE_END()
}