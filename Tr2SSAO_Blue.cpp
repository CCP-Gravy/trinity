////////////////////////////////////////////////////////////////////////////////
//
// Created:   March 2022
// Copyright: CCP 2022
//

#include "StdAfx.h"
#include "Tr2SSAO.h"

BLUE_DEFINE( Tr2SSAO );

const Be::VarChooser SSAOQualityChooser[] = {
	{ "Lowest",  BeCast( SSAOQuality::LOWEST  ), "Lowest quality"             },
	{ "Low",     BeCast( SSAOQuality::LOW     ), "Low quality"                },
	{ "Medium",  BeCast( SSAOQuality::MEDIUM  ), "Medium quality"             },
	{ "High",    BeCast( SSAOQuality::HIGH    ), "High quality"               },
	{ "Highest", BeCast( SSAOQuality::HIGHEST ), "Highest (adaptive) quality" },
	{}
};

BLUE_REGISTER_ENUM_EX( "SSAOQuality", SSAOQuality, SSAOQualityChooser, ENUM_REG_ENUM_OBJECT_ON_MODULE );

const Be::ClassInfo* Tr2SSAO::ExposeToBlue()
{
	EXPOSURE_BEGIN( Tr2SSAO, "" )
		MAP_INTERFACE( Tr2SSAO )
		MAP_INTERFACE( INotify )

		MAP_ATTRIBUTE( "enabled", m_enabled, "", Be::READWRITE )
		MAP_ATTRIBUTE_WITH_CHOOSER( "quality", m_ssaoQuality, "", Be::READWRITE | Be::NOTIFY | Be::ENUM, SSAOQualityChooser )
		MAP_ATTRIBUTE( "useDownsampledSSAO", m_downsampledSSAO, "Use lower resolution SSAO: low quality, but fast", Be::READWRITE | Be::NOTIFY )
		MAP_ATTRIBUTE( "zoomLevel", m_zoomLevel, "Defines the desired detail size", Be::READWRITE )
		MAP_ATTRIBUTE( "largeEffect", m_largeEffect, "Enables/disables large-scale SSAO effect\n:jessica-group: Settings (Large)", Be::READWRITE | Be::NOTIFY )
		MAP_ATTRIBUTE( "zoomLevelLarge", m_zoomLevelLarge, "Defines the desired detail size for large-scale effect\n:jessica-group: Settings (Large)", Be::READWRITE )

		MAP_ATTRIBUTE( "radius", m_settings.radius, "World (view) space size of the occlusion sphere. WARNING! LARGER VALUES AFFECTS PERFORMANCE!\n:jessica-group: Settings", Be::READWRITE )
		MAP_ATTRIBUTE( "shadowMultiplier", m_settings.shadowMultiplier, "Effect strength linear multiplier\n:jessica-group: Settings", Be::READWRITE )
		MAP_ATTRIBUTE( "shadowPower", m_settings.shadowPower, "Effect strength contrast\n:jessica-group: Settings", Be::READWRITE )
		MAP_ATTRIBUTE( "shadowClamp", m_settings.shadowClamp, "Effect max limit (applied after multiplier but before blur)\n:jessica-group: Settings", Be::READWRITE )
		MAP_ATTRIBUTE( "sharpness", m_settings.sharpness, "How much to bleed over edges (1: not at all, 0.5: half-half; 0.0: completely ignore edges).\n:jessica-group: Settings", Be::READWRITE )

		MAP_ATTRIBUTE( "radiusLarge", m_settingsLarge.radius, "World (view) space size of the occlusion sphere. WARNING! LARGER VALUES AFFECTS PERFORMANCE!\n:jessica-group: Settings (Large)", Be::READWRITE )
		MAP_ATTRIBUTE( "shadowMultiplierLarge", m_settingsLarge.shadowMultiplier, "Effect strength linear multiplier\n:jessica-group: Settings (Large)", Be::READWRITE )
		MAP_ATTRIBUTE( "shadowPowerLarge", m_settingsLarge.shadowPower, "Effect strength contrast\n:jessica-group: Settings (Large)", Be::READWRITE )
		MAP_ATTRIBUTE( "shadowClampLarge", m_settingsLarge.shadowClamp, "Effect max limit (applied after multiplier but before blur)\n:jessica-group: Settings (Large)", Be::READWRITE )
		MAP_ATTRIBUTE( "sharpnessLarge", m_settingsLarge.sharpness, "How much to bleed over edges (1: not at all, 0.5: half-half; 0.0: completely ignore edges).\n:jessica-group: Settings (Large)", Be::READWRITE )

		MAP_ATTRIBUTE( "deinterleavedDepthTarget", m_deinterleavedDepthTarget, "", Be::READ )
		MAP_ATTRIBUTE( "deinterleavedNormalTarget", m_deinterleavedNormalTarget, "", Be::READ )
		MAP_ATTRIBUTE( "importanceTargetA", m_importanceTargetA, "", Be::READ )
		MAP_ATTRIBUTE( "importanceTargetB", m_importanceTargetB, "", Be::READ )
		MAP_ATTRIBUTE( "ssaoWorkerTargetA", m_ssaoWorkerTargetA, "", Be::READ )
		MAP_ATTRIBUTE( "ssaoWorkerTargetB", m_ssaoWorkerTargetB, "", Be::READ )
		MAP_ATTRIBUTE( "outputTarget", m_outputTarget, "Final SSAO output", Be::READ )
	EXPOSURE_END()
}
