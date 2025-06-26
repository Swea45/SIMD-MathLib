#pragma once
#include <intrin.h>
#include <cmath>
#include "Vector4f.h"

#pragma region ClassFunctions

inline float Vec4f::LengthSqr()
{
	__m128 result = _mm_mul_ps(data, data);
	//Adds each pair togeter
	result = _mm_hadd_ps(result, result);
	result = _mm_hadd_ps(result, result);
	return _mm_cvtss_f32(result);
}

inline float Vec4f::Length()
{
	__m128 result = _mm_mul_ps(data, data);
	//Adds each pair togeter
	result = _mm_hadd_ps(result, result);
	result = _mm_hadd_ps(result, result);
	return _mm_cvtss_f32(_mm_sqrt_ss(result));  
}

inline Vec4f Vec4f::GetNormalized() 
{
	return _mm_div_ps(data, _mm_set1_ps(Length()));  
}

inline void Vec4f::Normalize()
{
	data = _mm_div_ps(data, _mm_set1_ps(Length())); 
}

inline float Vec4f::Dot(const Vec4f& aVector)
{
	return _mm_cvtss_f32(_mm_dp_ps(data, aVector.data, 0xF1));  
}

#pragma endregion ClassFunctions
#pragma region OperatorDefinitions

inline bool operator==(const Vec4f& aDataOne, const Vec4f& aDataTwo)
{
	return _mm_movemask_ps(_mm_cmpeq_ps(aDataOne.data, aDataTwo.data)) == 0xF; 
}

inline bool operator!=(const Vec4f& aDataOne, const Vec4f& aDataTwo)
{
	return _mm_movemask_ps(_mm_cmpeq_ps(aDataOne.data, aDataTwo.data)) != 0xF; 
}

inline Vec4f operator-(const Vec4f& aDataOne)
{
	return _mm_xor_ps(aDataOne.data, _mm_set1_ps(-0.0f)); 
}
inline Vec4f operator+(const Vec4f& aDataOne, const Vec4f& aDataTwo)
{
	return _mm_add_ps(aDataOne.data, aDataTwo.data);
}
inline Vec4f operator-(const Vec4f& aDataOne, const Vec4f& aDataTwo)
{
	return _mm_sub_ps(aDataOne.data, aDataTwo.data);
}
inline Vec4f operator*(const Vec4f& aDataOne, const Vec4f& aDataTwo)
{
	return _mm_mul_ps(aDataOne.data, aDataTwo.data);
}
inline Vec4f operator*(const Vec4f& aDataOne, const float& aScalar)
{
	return _mm_mul_ps(aDataOne.data, _mm_set1_ps(aScalar)); 
}
inline Vec4f operator*(const float& aScalar, const Vec4f& aDataTwo)
{
	return _mm_mul_ps(_mm_set1_ps(aScalar), aDataTwo.data);
}

inline Vec4f operator/(const Vec4f& aDataOne, const Vec4f& aDataTwo)
{
	return _mm_div_ps(aDataOne.data, aDataTwo.data);
}

inline Vec4f operator/(const Vec4f& aDataOne, const float& aScalar)
{
	return _mm_div_ps(aDataOne.data, _mm_set1_ps(aScalar));
}

inline void operator+=(Vec4f& aDataOne, const Vec4f& aDataTwo)
{
	aDataOne.data = _mm_add_ps(aDataOne.data, aDataTwo.data);
}

inline void operator-=(Vec4f& aDataOne, const Vec4f& aDataTwo)
{
	aDataOne.data = _mm_sub_ps(aDataOne.data, aDataTwo.data);
}

inline void operator*=(Vec4f& aDataOne, const Vec4f& aDataTwo)
{
	aDataOne.data = _mm_mul_ps(aDataOne.data, aDataTwo.data);
}

inline void operator*=(Vec4f& aDataOne, const float& aScalar)
{
	aDataOne.data = _mm_mul_ps(aDataOne.data, _mm_set1_ps(aScalar));
}

inline void operator/=(Vec4f& aDataOne, const Vec4f& aDataTwo)
{
	aDataOne.data = _mm_div_ps(aDataOne.data, aDataTwo.data);
}

inline void operator/=(Vec4f& aDataOne, const float& aScalar)
{
	aDataOne.data = _mm_div_ps(aDataOne.data, _mm_set1_ps(aScalar));
}

#pragma endregion OperatorDefinitions