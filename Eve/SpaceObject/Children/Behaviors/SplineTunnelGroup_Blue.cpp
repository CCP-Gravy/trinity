#include "StdAfx.h"
#include "SplineTunnelGroup.h"



BLUE_DEFINE( SplineTunnelGroup );

const Be::ClassInfo* SplineTunnelGroup::ExposeToBlue()
{
	EXPOSURE_BEGIN( SplineTunnelGroup, "" )
		MAP_INTERFACE( SplineTunnelGroup )
		MAP_INTERFACE( INotify )


		//MAP_ATTRIBUTE( "theSplineTunnels", m_tunnels, "", Be::READWRITE | Be::PERSIST )
		MAP_ATTRIBUTE( "curveSets", m_curveSets, "", Be::READ | Be::PERSIST | Be::NOTIFY )
		MAP_ATTRIBUTE( "breakPoints", m_numBreakPoints, "", Be::READWRITE | Be::PERSIST | Be::NOTIFY )
		MAP_ATTRIBUTE( "tunnelWidth", m_tunnelWidth, "", Be::READWRITE | Be::PERSIST | Be::NOTIFY )
		MAP_ATTRIBUTE( "entrancePullSize", m_entrancePullSize, "", Be::READWRITE | Be::PERSIST | Be::NOTIFY )
		MAP_ATTRIBUTE( "entrySize", m_entrySize, "", Be::READWRITE | Be::PERSIST | Be::NOTIFY )


		
		MAP_METHOD_AND_WRAP("createSplineTunnels", createSplineTunnels,
		                    "recreate all tunnels \n:jessica-placement: TOOLBAR\n:jessica-icon: far-bomb\n")
		MAP_METHOD_AND_WRAP( "debugPoints", tempDebugPointsDEV,
			" \n:jessica-placement: TOOLBAR\n:jessica-icon: far-dev\n" )

	EXPOSURE_END()
}