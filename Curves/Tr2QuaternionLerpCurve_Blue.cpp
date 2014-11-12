#include "StdAfx.h"
#include "Tr2QuaternionLerpCurve.h"

BLUE_DEFINE( Tr2QuaternionLerpCurve );

const Be::ClassInfo* Tr2QuaternionLerpCurve::ExposeToBlue()
{
    EXPOSURE_BEGIN(Tr2QuaternionLerpCurve, "no comment")
        MAP_INTERFACE(ITriFunction)
        MAP_INTERFACE(ITriQuaternionFunction)
        MAP_INTERFACE(ITriCurveLength)

        MAP_ATTRIBUTE
        ( 
            "start",
            mStart,
            "The time at which the sequence should begin",
            Be::READWRITE | Be::PERSIST
        )
        MAP_ATTRIBUTE
        ( 
            "length",
            mLength,
            "Length of the ",
            Be::READWRITE | Be::PERSIST
        )
        MAP_ATTRIBUTE
        (  
            "value",
            mValue,
            "na",
            Be::READWRITE | Be::PERSIST
        )
        MAP_ATTRIBUTE
        ( 
            "startCurve",
            mStartCurve,
            "Starting rotation curve",
            Be::READWRITE | Be::PERSIST
        )
        MAP_ATTRIBUTE
        ( 
            "endCurve",
            mEndCurve,
            "End rotation curve",
            Be::READWRITE | Be::PERSIST
        )

    EXPOSURE_END()
}
