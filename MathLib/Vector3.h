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
	//[Warning] Use this memory to create a vector ONLY if the data is stored as three consecutive floats in the exact order: x, y, z.
	// The memory must contain exactly 3 float values (not doubles, ints, or structs), tightly packed with no padding.
	// Using memory with a different layout, data type, or extra components (e.g., a 'w' value) may lead to incorrect results or undefined behavior.
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

#include "Vector3.inl"

