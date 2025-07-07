#pragma once
#include <emmintrin.h>
#include "../../Vector/Vector3f/Vector3f.h"

constexpr int MATRIX4X4_ROW_AMOUNT = 4;

class Mat4x4f
{
public:
	union
	{
		__m128 row[MATRIX4X4_ROW_AMOUNT];
		float data[16];
		struct
		{
			float p00, p01, p02, p03,
				  p10, p11, p12, p13,
				  p20, p21, p22, p23,
				  p30, p31, p32, p33;
		};
	};

	Mat4x4f();
	Mat4x4f(const Mat4x4f& aMatrix) = default;
	Mat4x4f(const Vec3f& aPosition);
	Mat4x4f(const __m128& aRowOne, const __m128& aRowTwo, const __m128& aRowThree, const __m128& aRowFour);
	//Need to implement Quaternion class
	//Mat4x4f(const Vec3f& aPosition, const Quat& aRotation, const Vec3f& aScale);
	
	inline void SetTranslation(float aX, float aY, float aZ);
	inline void SetTranslation(const Vec3f& aPosition);
	//void SetRotation(const Mat3x3f& aRotationMatrix);
	//void SetRotation(const Quat& aRotation);
	inline void SetScale(const Vec3f& aScale);

	inline Mat4x4f GetRotationX(float aAngleRadians);
	inline Mat4x4f GetRotationY(float aAngleRadians);
	inline Mat4x4f GetRotationZ(float aAngleRadians);
	inline Mat4x4f GetRotation(const Vec3f& aAxis, float aAngleRadians);

	inline void RotateX(float aAngleRadians);
	inline void RotateY(float aAngleRadians);
	inline void RotateZ(float aAngleRadians);
	inline void Rotate(const Vec3f& aAxis, float aAngleRadians); 

	inline Mat4x4f GetRotationMatrix4x4();
	//Mat3x3f GetRotationMatrix3x3();

	inline Mat4x4f GetTransposed();
	inline void Transpose();

	inline Mat4x4f GetInverted();
	inline void Invert();


private:
};

inline bool operator==(const Mat4x4f& aMatrixOne, const Mat4x4f& aMatrixTwo);
inline bool operator!=(const Mat4x4f& aMatrixOne, const Mat4x4f& aMatrixTwo);

inline Mat4x4f operator+(const Mat4x4f& __restrict aMatrixOne, const Mat4x4f& __restrict aMatrixTwo);
inline Mat4x4f operator-(const Mat4x4f& __restrict aMatrixOne, const Mat4x4f& __restrict aMatrixTwo);


inline Mat4x4f operator*(const Mat4x4f& aMatrixOne, Mat4x4f aMatrixTwo);
inline Mat4x4f operator*(const Mat4x4f& aMatrixOne, float aScalar);  
inline Mat4x4f operator*(float aScalar, const Mat4x4f& aMatrixOne); 

inline Mat4x4f operator/(const Mat4x4f& aMatrixOne, float aScalar);  

inline void operator+=(Mat4x4f& __restrict aMatrixOne, const Mat4x4f& __restrict aMatrixTwo);
inline void operator-=(Mat4x4f& __restrict aMatrixOne, const Mat4x4f& __restrict aMatrixTwo);

#include "Matrix4x4f.inl"
