////////////////////////////////////////////////////////////
//
//    Created:   May 2015
//    Copyright: CCP 2015
//
#pragma once
#ifndef Tr2ToggleCurve_h
#define Tr2ToggleCurve_h

#include "Tr2ScalarCurve.h"



// --------------------------------------------------------------------------------
// Description:
//   This class represents a key into the toggle curve 
// --------------------------------------------------------------------------------
BLUE_CLASS( Tr2ToggleKey ):
	public IRoot,
	public Tr2Key<bool>
{
public:
	Tr2ToggleKey( IRoot* lockobj = NULL );
	EXPOSE_TO_BLUE();
};
BLUE_DECLARE_VECTOR( Tr2ToggleKey );



// --------------------------------------------------------------------------------
// Description:
//   This class represents a curve that flicks a boolean on and off, kinda like so:
// 
//         _______         _______
//   _____|       |_______|
//
// SeeAlso:
//   Tr2Curve
// --------------------------------------------------------------------------------
BLUE_CLASS( Tr2ToggleCurve ):
	public Tr2Curve<Tr2ToggleKey, PTr2ToggleKeyVector, bool>
{
public:
	EXPOSE_TO_BLUE();
	
	bool Initialize();
	void Sort();
	void AddKey_(float time, const bool& value);
		
	Tr2ToggleCurve( IRoot* lockobj = NULL );
	bool* Interpolate( bool* out, Tr2ToggleKey* lastKey, Tr2ToggleKey* nextKey );
};

TYPEDEF_BLUECLASS( Tr2ToggleCurve );
TYPEDEF_BLUECLASS( Tr2ToggleKey );
#endif //Tr2ToggleCurve_h
