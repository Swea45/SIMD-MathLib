#pragma once
#include "Defines.h"
#include "cmath"
namespace BitBloom
{

	inline bool AlmostZero(float aValue, float aThreshold = EPSILON)
	{
		return std::fabs(aValue) < aThreshold; 
	}

	inline bool AlmostEqual(float aFValue, float aSValue, float aThreshold = EPSILON)
	{
		return std::fabs(aFValue - aSValue) < aThreshold;
	}

}

namespace BB = BitBloom;