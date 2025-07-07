#pragma once
#include "Matrix4x4f.h"
#pragma region Constructors
inline Mat4x4f::Mat4x4f()
{
	row[0] = _mm_set_ps(0, 0, 0, 1);
	row[1] = _mm_set_ps(0, 0, 1, 0);
	row[2] = _mm_set_ps(0, 1, 0, 0);
	row[3] = _mm_set_ps(1, 0, 0, 0);
}

inline Mat4x4f::Mat4x4f(const Vec3f& aPosition)
{
	row[0] = _mm_set_ps(0, 0, 0, 1);
	row[1] = _mm_set_ps(0, 0, 1, 0);
	row[2] = _mm_set_ps(0, 1, 0, 0);
	row[3] = _mm_set_ps(1, aPosition.z, aPosition.y, aPosition.x);
}

inline Mat4x4f::Mat4x4f(const __m128& aRowOne, const __m128& aRowTwo, const __m128& aRowThree, const __m128& aRowFour)
{
	row[0] = aRowOne;
	row[1] = aRowTwo;
	row[2] = aRowThree;
	row[3] = aRowFour;
}

inline void Mat4x4f::SetTranslation(float aX, float aY, float aZ)
{
	p30 = aX;
	p31 = aY;
	p32 = aZ;
}

inline void Mat4x4f::SetTranslation(const Vec3f & aPosition)
{
	p30 = aPosition.x;
	p31 = aPosition.y;
	p32 = aPosition.z;
}

#pragma endregion

#pragma region ClassFunctions

inline Mat4x4f Mat4x4f::GetTransposed()
{
	Mat4x4f result = *this;
	_MM_TRANSPOSE4_PS(result.row[0], result.row[1], result.row[2], result.row[3]);
	return result; 
}

inline void Mat4x4f::Transpose()
{
	_MM_TRANSPOSE4_PS(row[0], row[1], row[2], row[3]);
}

#pragma endregion


#pragma region OperatorDefinitions

inline bool operator==(const Mat4x4f& aMatrixOne, const Mat4x4f& aMatrixTwo)
{
	int result = 0xF;
	for (int i = 0; i < MATRIX4X4_ROW_AMOUNT; i++)
	{
		result &= _mm_movemask_ps(_mm_cmpeq_ps(aMatrixOne.row[i], aMatrixTwo.row[i]));
	}
	return result == 0xF;
}

inline bool operator!=(const Mat4x4f& aMatrixOne, const Mat4x4f& aMatrixTwo)
{
	int result = 0xF;
	for (int i = 0; i < MATRIX4X4_ROW_AMOUNT; i++)
	{
		result &= _mm_movemask_ps(_mm_cmpeq_ps(aMatrixOne.row[i], aMatrixTwo.row[i]));
	}
	return result != 0xF;
}

inline Mat4x4f operator+(const Mat4x4f& aMatrixOne, const Mat4x4f& aMatrixTwo)
{
	return { _mm_add_ps(aMatrixOne.row[0], aMatrixTwo.row[0]),
			 _mm_add_ps(aMatrixOne.row[1], aMatrixTwo.row[1]),
			 _mm_add_ps(aMatrixOne.row[2], aMatrixTwo.row[2]),
			 _mm_add_ps(aMatrixOne.row[3], aMatrixTwo.row[3]), };
}

inline Mat4x4f operator-(const Mat4x4f& aMatrixOne, const Mat4x4f& aMatrixTwo)
{
	return { _mm_sub_ps(aMatrixOne.row[0], aMatrixTwo.row[0]),
			 _mm_sub_ps(aMatrixOne.row[1], aMatrixTwo.row[1]),
			 _mm_sub_ps(aMatrixOne.row[2], aMatrixTwo.row[2]),
			 _mm_sub_ps(aMatrixOne.row[3], aMatrixTwo.row[3]), };
}

inline Mat4x4f operator*(const Mat4x4f& aMatrixOne, Mat4x4f aMatrixTwo)
{
	Mat4x4f result; 

	aMatrixTwo.Transpose();

	for (int i = 0; i < 4; ++i)
	{
		// Broadcast each element of the row
	/*	__m128 e0 = _mm_shuffle_ps(aMatrixOne.row[i], aMatrixOne.row[i], _MM_SHUFFLE(0, 0, 0, 0));
		__m128 e1 = _mm_shuffle_ps(aMatrixOne.row[i], aMatrixOne.row[i], _MM_SHUFFLE(1, 1, 1, 1));
		__m128 e2 = _mm_shuffle_ps(aMatrixOne.row[i], aMatrixOne.row[i], _MM_SHUFFLE(2, 2, 2, 2));
		__m128 e3 = _mm_shuffle_ps(aMatrixOne.row[i], aMatrixOne.row[i], _MM_SHUFFLE(3, 3, 3, 3));*/

		// Multiply each with corresponding column vector and sum
		__m128 mul0 = _mm_mul_ps(_mm_shuffle_ps(aMatrixOne.row[i], aMatrixOne.row[i], _MM_SHUFFLE(0, 0, 0, 0)), aMatrixTwo.row[0]);
		__m128 mul1 = _mm_mul_ps(_mm_shuffle_ps(aMatrixOne.row[i], aMatrixOne.row[i], _MM_SHUFFLE(1, 1, 1, 1)), aMatrixTwo.row[1]);
		__m128 mul2 = _mm_mul_ps(_mm_shuffle_ps(aMatrixOne.row[i], aMatrixOne.row[i], _MM_SHUFFLE(2, 2, 2, 2)), aMatrixTwo.row[2]);
		__m128 mul3 = _mm_mul_ps(_mm_shuffle_ps(aMatrixOne.row[i], aMatrixOne.row[i], _MM_SHUFFLE(3, 3, 3, 3)), aMatrixTwo.row[3]);

		result.row[i] = _mm_add_ps(_mm_add_ps(mul0, mul1), _mm_add_ps(mul2, mul3));
	}

	return result;
}

inline Mat4x4f operator*(const Mat4x4f& aMatrixOne, float aScalar)
{
	__m128 scalar = _mm_set1_ps(aScalar);
	return { _mm_mul_ps(aMatrixOne.row[0], scalar), 
			 _mm_mul_ps(aMatrixOne.row[1], scalar), 
			 _mm_mul_ps(aMatrixOne.row[2], scalar), 
			 _mm_mul_ps(aMatrixOne.row[3], scalar), };
}

inline Mat4x4f operator*(float aScalar, const Mat4x4f& aMatrixOne)
{
	__m128 scalar = _mm_set1_ps(aScalar);
	return { _mm_mul_ps(aMatrixOne.row[0], scalar),
			 _mm_mul_ps(aMatrixOne.row[1], scalar),
			 _mm_mul_ps(aMatrixOne.row[2], scalar),
			 _mm_mul_ps(aMatrixOne.row[3], scalar), };
}

inline Mat4x4f operator/(const Mat4x4f& aMatrixOne, float aScalar)
{
	__m128 scalar = _mm_set1_ps(aScalar);
	return { _mm_div_ps(aMatrixOne.row[0], scalar),
			 _mm_div_ps(aMatrixOne.row[1], scalar),
			 _mm_div_ps(aMatrixOne.row[2], scalar),
			 _mm_div_ps(aMatrixOne.row[3], scalar), };
}


#pragma endregion

