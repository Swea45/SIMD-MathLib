#pragma once
#include "Vector3f.h"
#include <intrin.h>
#include <cmath>

#pragma region ClassFunctions


inline float Vec3f::LengthSqr()
{ 
	__m128 result = _mm_mul_ps(data, data);
	//Adds each pair togeter
	result = _mm_hadd_ps(result, result);   
	result = _mm_hadd_ps(result, result);   
	return _mm_cvtss_f32(result);  
}

inline float Vec3f::Length()
{
	__m128 result = _mm_mul_ps(data, data); 
	//Adds each pair togeter 
	result = _mm_hadd_ps(result, result);
	result = _mm_hadd_ps(result, result); 
	return _mm_cvtss_f32(_mm_sqrt_ss(result)); 
}

inline Vec3f Vec3f::GetNormalized() 
{
	return _mm_div_ps(data, _mm_set1_ps(Length())); 
}

inline void Vec3f::Normalize()
{
	data = _mm_div_ps(data, _mm_set1_ps(Length()));
}

inline float Vec3f::Dot(const Vec3f& aVector)
{
	return _mm_cvtss_f32(_mm_dp_ps(data, aVector.data, 0x71));
}

inline Vec3f Vec3f::Cross(const Vec3f& aVector)
{ 
	__m128 result = _mm_sub_ps( 
		_mm_mul_ps(data, _mm_shuffle_ps(aVector.data, aVector.data, _MM_SHUFFLE(3, 0, 2, 1))), 
		_mm_mul_ps(_mm_shuffle_ps(data, data, _MM_SHUFFLE(3, 0, 2, 1)), aVector.data));      
	return _mm_shuffle_ps(result, result, _MM_SHUFFLE(3, 0, 2, 1)); 
}
inline Vec3f Vec3f::DistanceTo(const Vec3f& aVector)
{
	return _mm_sub_ps(aVector.data, data);   
}

inline Vec3f Vec3f::GetRotatedAroundAxis(Vec3f aAxis, float aAngle)
{
	aAxis = aAxis.GetNormalized(); 
	float cosA = std::cos(aAngle);
	float sinA = std::sin(aAngle);

	float dot = Dot(aAxis);

	float newX = x * cosA + (aAxis.y * z - aAxis.z * y) * sinA + aAxis.x * dot * (1 - cosA);
	float newY = y * cosA + (aAxis.z * x - aAxis.x * z) * sinA + aAxis.y * dot * (1 - cosA);

	return *this * cosA + aAxis.Cross(*this) * sinA + aAxis * (aAxis.Dot(*this) * (1.0f - cosA));  
}

inline Vec3f Vec3f::GetRotatedX(float aAngle)
{
	float cosA = std::cos(aAngle);
	float sinA = std::sin(aAngle);

	return Vec3f(
		x,
		(y * cosA) - (z * sinA),
		(y * sinA) + (z * cosA));

}

inline Vec3f Vec3f::GetRotatedY(float aAngle)
{
	float cosA = std::cos(aAngle); 
	float sinA = std::sin(aAngle); 
	return Vec3f(
		(z * sinA) + (x * cosA),
		y, 
		(z * cosA) - (x * sinA));
}

inline Vec3f Vec3f::GetRotatedZ(float aAngle)
{
	float cosA = std::cos(aAngle); 
	float sinA = std::sin(aAngle); 
	return Vec3f(
		(x * cosA) - (y * sinA), 
		(x * sinA) + (y * cosA), 
		z); 
}

inline void Vec3f::RotateAroundAxis(Vec3f aAxis, float aAngle) 
{
	aAxis = aAxis.GetNormalized();
	float cosA = std::cos(aAngle);
	float sinA = std::sin(aAngle);

	float dot = Dot(aAxis);

	float newX = x * cosA + (aAxis.y * z - aAxis.z * y) * sinA + aAxis.x * dot * (1 - cosA); 
	float newY = y * cosA + (aAxis.z * x - aAxis.x * z) * sinA + aAxis.y * dot * (1 - cosA); 

	z = z * cosA + (aAxis.x * y - aAxis.y * x) * sinA + aAxis.z * dot * (1 - cosA); 
	x = newX;
	y = newY;

}

inline void Vec3f::RotateX(float aAngle)
{
	float cosA = std::cos(aAngle); 
	float sinA = std::sin(aAngle);

	float newY = (y * cosA) - (z * sinA);
	
	z = (y * sinA) + (z * sinA);
	y = newY;
}

inline void Vec3f::RotateY(float aAngle)
{
	float cosA = std::cos(aAngle);
	float sinA = std::sin(aAngle);

	float newZ = (z * cosA) - (x * sinA);
	x = (z * sinA) + (x * cosA);
	z = newZ;
}

inline void Vec3f::RotateZ(float aAngle)
{
	float cosA = std::cos(aAngle);
	float sinA = std::sin(aAngle);

	float newX = (x * cosA) - (y * sinA);
	
	y = (x * sinA) + (y * cosA);
	x = newX;

}


#pragma endregion ClassFunctions

#pragma region OperatorDefinitions


bool operator==(const Vec3f& aDataOne, const Vec3f& aDataTwo)
{
	return _mm_movemask_ps(_mm_cmpeq_ps(aDataOne.data, aDataTwo.data)) == 0xF;
}

bool operator!=(const Vec3f& aDataOne, const Vec3f& aDataTwo)
{
	return _mm_movemask_ps(_mm_cmpeq_ps(aDataOne.data, aDataTwo.data)) != 0xF;
}
Vec3f operator-(const Vec3f& aDataOne)
{
	return _mm_xor_ps(aDataOne.data, _mm_set1_ps(-0.0f)); 
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
	return _mm_mul_ps(aDataOne.data, _mm_set1_ps(aScalar)); 
}

Vec3f operator*(const float& aScalar, const Vec3f& aDataOne)
{
	return _mm_mul_ps(_mm_set1_ps(aScalar), aDataOne.data);
}

inline Vec3f operator/(const Vec3f& aDataOne, const Vec3f& aDataTwo)
{
	__m128 result = _mm_div_ps(aDataOne.data, aDataTwo.data);
	__m128 mask = _mm_castsi128_ps(_mm_set_epi32(0, -1, -1, -1));
	return _mm_and_ps(result, mask);
}

inline Vec3f operator/(const Vec3f& aDataOne, const float& aScalar)
{
	return _mm_div_ps(aDataOne.data, _mm_set1_ps(aScalar));
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

inline void operator*=(Vec3f& aDataOne, const float& aScalar)
{
	aDataOne.data = _mm_mul_ps(aDataOne.data, _mm_set1_ps(aScalar)); 
}

inline void operator/=(Vec3f& aDataOne, const Vec3f& aDataTwo)
{
	__m128 result = _mm_div_ps(aDataOne.data, aDataTwo.data);
	__m128 mask = _mm_castsi128_ps(_mm_set_epi32(0, -1, -1, -1));
	aDataOne.data = _mm_and_ps(result, mask);
}

inline void operator/=(Vec3f& aDataOne, const float& aScalar)
{
	aDataOne.data = _mm_div_ps(aDataOne.data, _mm_set1_ps(aScalar)); 
}

#pragma endregion OperatorDefinitions
