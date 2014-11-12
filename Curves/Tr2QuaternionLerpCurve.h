#pragma once
#ifndef Tr2QuaternionLerpCurve_h
#define Tr2QuaternionLerpCurve_h

#include "include/ITriFunction.h"
#include "include/ITriCurveLength.h"

class Tr2QuaternionLerpCurve :
    public ITriQuaternionFunction,
    public ITriCurveLength
{
public:
    EXPOSE_TO_BLUE();

    Be::Time mStart;
    float mLength;

    Quaternion mValue;
    ITriQuaternionFunctionPtr mStartCurve;
    ITriQuaternionFunctionPtr mEndCurve;

    Tr2QuaternionLerpCurve(IRoot* lockobj = NULL);
    ~Tr2QuaternionLerpCurve();

    /////////////////////////////////////////////////////////////////////////////////////
    // ITriFunction
    /////////////////////////////////////////////////////////////////////////////////////
    void UpdateValue( double time ) { Quaternion q; Update( &q, time ); }

    /////////////////////////////////////////////////////////////////////////////////////
    // ITriCurveLength
    /////////////////////////////////////////////////////////////////////////////////////
    float Length() { return mLength; }

    /////////////////////////////////////////////////////////////////////////////////////
    // ITriQuaternionFunction
    /////////////////////////////////////////////////////////////////////////////////////
    Quaternion* Update(
        Quaternion* in,
        Be::Time time
        );

    Quaternion* Update(
        Quaternion* in,
        double time
        );

    Quaternion* GetValueAt(
        Quaternion* in,
        Be::Time time
        );

    Quaternion* GetValueAt(
        Quaternion* in,
        double time
        );

    Quaternion* GetValueDotAt(
        Quaternion* in,
        Be::Time time
        );

    Quaternion* GetValueDotAt(
        Quaternion* in,
        double time
        );

    Quaternion* GetValueDoubleDotAt(
        Quaternion* in,
        Be::Time time
        );

    Quaternion* GetValueDoubleDotAt(
        Quaternion* in,
        double time
        );
};

TYPEDEF_BLUECLASS(Tr2QuaternionLerpCurve);
#endif //Tr2QuaternionLerpCurve_h
