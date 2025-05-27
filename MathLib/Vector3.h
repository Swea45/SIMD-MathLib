#pragma once
#include <emmintrin.h>

class Vec3f
{
public:
	union
	{
		__m128 data;
		struct { float x, y, z; };
	};

//[Constuctors]
	Vec3f() : data(_mm_setzero_ps()) {};
	Vec3f(__m128 aSIMDdata) : data(aSIMDdata) {};
	Vec3f(float aScalar) : data(_mm_set_ps(0.0f, aScalar, aScalar, aScalar)) {};
	Vec3f(float aX, float aY, float aZ) : data(_mm_set_ps(0.0f, aZ, aY, aX)) {};



//[Handle other vectors]
	void CopyDataFromMemory(const void* someData);
	static Vec3f ConstructFromMemory(const void* someData); 


};

#pragma region Operators
inline bool operator==(const Vec3f& aDataOne, const Vec3f& aDataTwo);
inline bool operator!=(const Vec3f& aDataOne, const Vec3f& aDataTwo);
inline Vec3f operator-(const Vec3f& aDataOne); 

inline Vec3f operator+(const Vec3f& aDataOne, const Vec3f& aDataTwo);
inline Vec3f operator-(const Vec3f& aDataOne, const Vec3f& aDataTwo);
inline Vec3f operator*(const Vec3f& aDataOne, const Vec3f& aDataTwo);
inline Vec3f operator*(const Vec3f& aDataOne, const float& aScalar); 
inline Vec3f operator*(const float& aScalar, const Vec3f& aDataOne); 
inline Vec3f operator/(const Vec3f& aDataOne, const Vec3f& aDataTwo);

inline void operator+=(Vec3f& aDataOne, const Vec3f& aDataTwo);
inline void operator-=(Vec3f& aDataOne, const Vec3f& aDataTwo);
inline void operator*=(Vec3f& aDataOne, const Vec3f& aDataTwo);  
inline void operator/=(Vec3f& aDataOne, const Vec3f& aDataTwo);  


#pragma endregion Operators

#pragma region OperatorDefinitions


bool operator==(const Vec3f& aDataOne, const Vec3f& aDataTwo)
{
	__m128 cmp = _mm_cmpeq_ps(aDataOne.data, aDataTwo.data);
	return _mm_movemask_ps(cmp) == 0xF;
}

bool operator!=(const Vec3f& aDataOne, const Vec3f& aDataTwo)
{
	__m128 cmp = _mm_cmpeq_ps(aDataOne.data, aDataTwo.data);
	return _mm_movemask_ps(cmp) != 0xF;
}
Vec3f operator-(const Vec3f& aDataOne) 
{
	__m128 mask = _mm_set1_ps(-0.0f);
	return _mm_xor_ps(aDataOne.data, mask);
}

Vec3f operator+(const Vec3f& aDataOne, const Vec3f& aDataTwo)
{
	return _mm_add_ps(aDataOne.data, aDataTwo.data);
}

Vec3f operator-(const Vec3f& aDataOne, const Vec3f& aDataTwo)
{
	return _mm_sub_ps(aDataOne.data, aDataTwo.data);
}

Vec3f operator*(const Vec3f& aDataOne, const Vec3f& aDataTwo)
{
	return _mm_mul_ps(aDataOne.data, aDataTwo.data); 
}

Vec3f operator*(const Vec3f& aDataOne, const float& aScalar)
{
	__m128 scalarData = _mm_set1_ps(aScalar); 
	return _mm_mul_ps(aDataOne.data, scalarData); 
}

Vec3f operator*(const float& aScalar, const Vec3f& aDataOne) 
{
	__m128 scalarData = _mm_set1_ps(aScalar);
	return _mm_mul_ps(scalarData, aDataOne.data);
}

inline Vec3f operator/(const Vec3f& aDataOne, const Vec3f& aDataTwo)
{
	__m128 result = _mm_div_ps(aDataOne.data, aDataTwo.data); 
	__m128 mask = _mm_castsi128_ps(_mm_set_epi32(0, -1, -1, -1)); 
	return _mm_and_ps(result, mask); 
}

void operator+=(Vec3f& aDataOne, const Vec3f& aDataTwo)
{
	aDataOne.data = _mm_add_ps(aDataOne.data, aDataTwo.data); 
}

void operator-=(Vec3f& aDataOne, const Vec3f& aDataTwo)
{
	aDataOne.data = _mm_sub_ps(aDataOne.data, aDataTwo.data);
}

void operator*=(Vec3f& aDataOne, const Vec3f& aDataTwo)
{
	aDataOne.data = _mm_mul_ps(aDataOne.data, aDataTwo.data);
}

inline void operator/=(Vec3f& aDataOne, const Vec3f& aDataTwo)
{
	__m128 result = _mm_div_ps(aDataOne.data, aDataTwo.data);
	__m128 mask = _mm_castsi128_ps(_mm_set_epi32(0, -1, -1, -1));
	aDataOne.data = _mm_and_ps(result, mask);
}

#pragma endregion OperatorDefinitions


