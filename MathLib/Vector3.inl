#pragma once
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
