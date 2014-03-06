////////////////////////////////////////////////////////////
//
//    Created:   January 2014
//    Copyright: CCP 2014
//
#pragma once
#ifndef EveMetaballItem_H
#define EveMetaballItem_H

// --------------------------------------------------------------------------------
// Description:
//   This class is for rendering metaballs (aka isosurfaces)
// --------------------------------------------------------------------------------
BLUE_CLASS( EveMetaballItem ) :
	public IRoot
{
public:
	EXPOSE_TO_BLUE();

	EveMetaballItem(IRoot* lockobj = NULL);
	~EveMetaballItem();

	Vector3 GetPosition(void) { return m_position; };
	float GetRadius(void) { return m_radius; };
	
private:
	Vector3 m_position;
	float m_radius;
};

TYPEDEF_BLUECLASS( EveMetaballItem );
BLUE_DECLARE_VECTOR( EveMetaballItem );

#endif