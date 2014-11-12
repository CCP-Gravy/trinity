#include "StdAfx.h"
#include "Tr2QuaternionLerpCurve.h"


Tr2QuaternionLerpCurve::Tr2QuaternionLerpCurve(IRoot* lockobj) :
    mStart  ( 0 ),
    mLength  ( 0 ),
    mValue( 0.0f, 0.0f, 0.0f, 1.0f )
{
    mValue = Quaternion( 0.0f, 0.0f, 0.0f, 1.0f );
}


Tr2QuaternionLerpCurve::~Tr2QuaternionLerpCurve()
{
}


Quaternion* Tr2QuaternionLerpCurve::Update(
    Quaternion* in,
    Be::Time t
    )
{
    GetValueAt(&mValue, t);
    *in = mValue;
    return in;
}


Quaternion* Tr2QuaternionLerpCurve::Update(
    Quaternion* in,
    double t
    )
{
    GetValueAt(&mValue, t);
    *in = mValue;
    return in;
}


Quaternion* Tr2QuaternionLerpCurve::GetValueAt(
    Quaternion* in,
    Be::Time now 
    )
{
    if( !mStartCurve || !mEndCurve || mLength <= 0 )
    {
        return in;
    }

    Quaternion start;
    Quaternion end;

    float delta = TimeAsFloat(now - mStart);
    float ratio = max(0.0f, min(1.0f, delta / mLength));

    D3DXQuaternionSlerp(in, mStartCurve->GetValueAt(&start, now), mEndCurve->GetValueAt(&end, now), ratio);

    return in;
}


Quaternion* Tr2QuaternionLerpCurve::GetValueAt(
    Quaternion* in,
    double pos
    )
{
    if( !mStartCurve || !mEndCurve || mLength <= 0 )
    {
        return in;
    }

    Quaternion start;
    Quaternion end;

    float delta = float(pos - TimeAsDouble(mStart));
    float ratio = max(0.0f, min(1.0f, delta / mLength));

    D3DXQuaternionSlerp(in, mStartCurve->GetValueAt(&start, pos), mEndCurve->GetValueAt(&end, pos), ratio);

    return in;
}


Quaternion* Tr2QuaternionLerpCurve::GetValueDotAt(
    Quaternion* in,
    Be::Time time
    )
{
    return in;
}


Quaternion* Tr2QuaternionLerpCurve::GetValueDotAt(
    Quaternion* in,
    double time
    )
{
    return in;
}


Quaternion* Tr2QuaternionLerpCurve::GetValueDoubleDotAt(
    Quaternion* in,
    Be::Time time
    )
{
    return in;
}


Quaternion* Tr2QuaternionLerpCurve::GetValueDoubleDotAt(
    Quaternion* in,
    double time
    )
{
    return in;
}
