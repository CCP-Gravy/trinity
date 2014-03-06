////////////////////////////////////////////////////////////
//
//    Created:   January 2014
//    Copyright: CCP 2014
//
#include "StdAfx.h"
#include "EveMetaballItem.h"

#include "Include/TriMath.h"
#include "Utilities/BoundingBox.h"

// --------------------------------------------------------------------------------
// Description:
//   Initialize data members
// --------------------------------------------------------------------------------
EveMetaballItem::EveMetaballItem( IRoot* lockobj ) :
	m_position( 0.f, 0.f, 0.f ),
	m_radius( 10.f )
{
}

// --------------------------------------------------------------------------------
// Description:
//   tear down
// --------------------------------------------------------------------------------
EveMetaballItem::~EveMetaballItem()
{
}
