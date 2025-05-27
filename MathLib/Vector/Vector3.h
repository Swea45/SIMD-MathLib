#pragma once
#include <emmintrin.h>

class Vector3
{
public:
	union
	{
		struct { float x, y, z; };
		__m128 data;
	};

	Vector3() : data(_mm_setzero_ps()) {};
	Vector3(float aX, float aY, float aZ) : x(aX), y(aY), z(aZ) {};
};
