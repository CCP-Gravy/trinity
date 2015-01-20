////////////////////////////////////////////////////////////
//
//    Created:   January 2015
//    Copyright: CCP 2015
//

#include "StdAfx.h"
#include "Tr2PointLight.h"

Tr2PointLight::Tr2PointLight( IRoot* lockobj )
	:m_position( 0.f, 0.f, 0.f ),
	m_radius( 0.f ),
	m_color( 0.f, 0.f, 0.f, 1.f )
{
}