#pragma once
#include <emmintrin.h>


/**
* @brief Vec4f is a SIMD-accelerated vector class aligned to 16 bytes.
* 
* @details The Vector stores data in a 128-bit SSE register (__m128), allowing for fast
* SIMD operations. Compnents can be accessed via {@code x}, {@code y}, {@code z}
* and {@code w}.
* 
* @warning Values are not checked for infinity or NaN. Use with caution, 
* as invalid values may cause crashes or undefined behavior during SIMD operations. 
*/
class Vec4f
{
public:
	union
	{
		__m128 data;
		struct { float x, y, z, w; };
	};

/**
* Begin Constructors Group
* @name Constructors
* @brief Ways to initialize an instance of Vec4f.
* @{
*/

/// @brief Default constructor. Initializes all components to zero.
	Vec4f() : data(_mm_setzero_ps()) {};
/// @brief Copy constructor. Can use Vec4f or a __m128 to copy the data.
	Vec4f(const __m128& aSSEData) : data(aSSEData) {};
/// @brief Initialzes all components (x, y, z, w) to the same float value.
	Vec4f(float aScalar) : data(_mm_set1_ps(aScalar)) {};
/// @brief Initialzes Vec4f with individual x, y, z, w values.
	Vec4f(float aX, float aY, float aZ, float aW) : data(_mm_set_ps(aW, aZ, aY, aX)) {};
/// @} 
// End Constructors Group

/**
 * @brief Computes the squared length (magnitude) of the vector.
 *
 * @details This is more efficient than calculating the actual length since it avoids
 * the square root operation. Useful for comparisons where the exact length
 * is not required.
 *
 * @return The squared length as a float.
 */
	inline float LengthSqr(); 

/**
 * @brief Computes the length (magnitude) of the vector.
 *
 * @details Calculates the Euclidean norm by taking the square root of the sum of the squares
 * of the vector's components.
 *
 * @return The length (magnitude) as a float.
 */
	inline float Length(); 
	
/**
 * @brief Returns a normalized copy of the vector.
 *
 * @details This function returns a unit vector in the same direction as the original,
 * with a length of 1. If the original vector has zero length, the result is undefined.
 *
 * @return A new Vec4f representing the normalized vector.
 *
 * @note No check is performed for zero-length vectors. Normalizing a zero vector may produce invalid results.
 */
	inline Vec4f GetNormalized();
/**
 * @brief Normalizes the vector in place.
 *
 * @details Scales the vector so that its length becomes 1, preserving its direction.
 * If the vector has zero length, the result is undefined.
 *
 * @note No check is performed for zero-length vectors. Normalizing a zero vector may produce invalid results.
 */
	inline void Normalize();
/**
 * @brief Computes the dot product between this vector and another.
 *
 * @details The dot product is a scalar value equal to the sum of the products of corresponding components.
 * Useful for calculating angles between vectors or projecting one vector onto another.
 *
 * @param aVector The other vector to compute the dot product with.
 * @return The dot product as a float.
 */
	inline float Dot(const Vec4f& aVector);

};


/**
* @name Operators
* @brief Vec4f operators.
* @{
*/

/**
* @brief Equal for vector4s.
*
* @details This operator checks if X, Y, Z, W are equal between two vectors.
*
* @param aDataOne first vector operand.
* @param aDataTwo second vector operand.
* @return A bool depending if the two vectors are equal.
* @relatesalso Vec4f
*/
inline bool operator==(const Vec4f& aDataOne, const Vec4f& aDataTwo);
/**
* @brief Not equal for vector4s.
*
* @details This operator checks if X, Y, Z are not equal between two vectors.
*
* @param aDataOne first vector operand.
* @param aDataTwo second vector operand.
* @return A bool depending if the two vectors are equal.
* @relatesalso Vec4f
*/
inline bool operator!=(const Vec4f& aDataOne, const Vec4f& aDataTwo);
/**
* @brief Negates the given 3D vector.
*
* @param aDataOne The input vector to negate.
* @return A new Vec3f where each component is the negation of the corresponding component in {@code aDataOne}.
* @relatesalso Vec3f
*/
inline Vec4f operator-(const Vec4f& aDataOne);

/**
* @brief Add for vector4s.
*
* @details This operator returns a new Vec4f that is the result of adding
* each corresponding component of the two input Vec4f vectors.
*
* @param aDataOne first vector operand.
* @param aDataTwo second vector operand.
* @return A new Vec4f representing the sum of aDataOne and aDataTwo.
* @relatesalso Vec4f
*/
inline Vec4f operator+(const Vec4f& aDataOne, const Vec4f& aDataTwo);
/**
 * @brief Subtract for vector4s.
 *
 * @details This operator returns a new Vec4f that is the result of subtracting
 * each corresponding component from the first Vec4f by the second Vec4f.
 *
 * @param aDataOne vector to subtract from (minuend).
 * @param aDataTwo vector to subtract (subtrahend).
 * @return A new Vec4f representing the difference of aDataOne and aDataTwo.
 * @relatesalso Vec4f
*/
inline Vec4f operator-(const Vec4f& aDataOne, const Vec4f& aDataTwo);
/**
* @brief Multiplication for Vector4s.
*
* @details This operator return a new Vec4f that is the result of multiplying
* each corresponding component from the first Vec4f by the second Vec4f.
*
* @param aDataOne first vector.
* @param aDataTwo second vector.
* @return A new Vec4f representing the sum of aDataOne and aDataTwo.
* @relatesalso Vec4f
*/
inline Vec4f operator*(const Vec4f& aDataOne, const Vec4f& aDataTwo);
/**
* @brief Multiplication for Vector4s.
*
* @details This operator return a new Vec4f that is the result of multiplying
* each corresponding component with a scalar.
*
* @param aDataOne a Vector.
* @param aScalar float value.
* @return A new Vec4f representing the sum of aDataOne by aScalar;
* @relatesalso Vec4f
*/
inline Vec4f operator*(const Vec4f& aDataOne, const float& aScalar);
/**
* @brief Multiplication for Vector4s.
*
* @details This operator return a new Vec4f that is the result of multiplying
* each corresponding component with a scalar.
*
* @param aScalar float value.
* @param aDataOne a Vector.
* @return A new Vec4f representing the sum of aDataOne by aScalar;
* @relatesalso Vec4f
*/
inline Vec4f operator*(const float& aScalar, const Vec4f& aDataTwo);
/**
* @brief component-wise division for Vec4f.
*
* @details Performs element-wise division between two Vec4f vectors.
* Each component of the resulting vector is the result of dividing
* the corresponding components of {@code aDataOne} by {@code aDataTwo}.
*
* @param aDataOne The numerator vector.
* @param aDataTwo The denominator vector.
* @return A new Vec4f where each component is {@code aDataOne[i] / aDataTwo[i]}.
*
* @note No division-by-zero checks are performed; ensure {@code aDataTwo} components are non-zero.
* @relatesalso Vec4f
*/
inline Vec4f operator/(const Vec4f& aDataOne, const Vec4f& aDataTwo);
/**
* @brief SIMD scalar division for Vec4f.
*
* @details Divides each component of the given Vec4f by a scalar float value.
*
* @param aDataOne The vector whose components are to be divided.
* @param aScalar The scalar float divisor.
* @return A new Vec4f where each component is {@code aDataOne[i] / aScalar}.
*
* @note No division-by-zero checks are performed; ensure {@code aScalar} is non-zero.
* @relatesalso Vec4f
*/
inline Vec4f operator/(const Vec4f& aDataOne, const float& aScalar);

/**
* @brief Performs component-wise addition and assignment for Vec4f.
*
* @details Modifies @p aDataOne by adding each component of @p aDataTwo to it.
*
* @param aDataOne The left-hand Vec4f to be modified.
* @param aDataTwo The right-hand Vec4f to add.
* @relates Vec4f
*/
inline void operator+=(Vec4f& aDataOne, const Vec4f& aDataTwo); 
/**
* @brief Performs component-wise subtraction and assignment for Vec4f.
*
* @details Modifies @p aDataOne by subtracting each component of @p aDataTwo from it.
*
* @param aDataOne The left-hand Vec4f to be modified (minuend).
* @param aDataTwo The right-hand Vec4f to subtract (subtrahend).
* @relates Vec4f
*/
inline void operator-=(Vec4f& aDataOne, const Vec4f& aDataTwo); 
/**
* @brief Performs component-wise multiplication and assignment for Vec4f.
*
* @details Multiplies each component of @p aDataOne by the corresponding component of @p aDataTwo,
* and stores the result in @p aDataOne.
*
* @param aDataOne The vector to modify (left-hand side).
* @param aDataTwo The vector to multiply with (right-hand side).
* @relates Vec4f
*/
inline void operator*=(Vec4f& aDataOne, const Vec4f& aDataTwo); 
/**
* @brief Performs scalar multiplication and assignment for Vec3f.
*
* @details Multiplies each component of @p aDataOne by the scalar @p aScalar,
* and stores the result back in @p aDataOne.
*
* @param aDataOne The vector to modify.
* @param aScalar The scalar float multiplier.
* @relates Vec3f
*/
inline void operator*=(Vec4f& aDataOne, const float& aScalar);
/**
 * @brief Performs component-wise division and assignment for Vec4f.
 *
 * @details Divides each component of @p aDataOne by the corresponding component of @p aDataTwo,
 * and stores the result in @p aDataOne.
 *
 * @param aDataOne The vector to be modified (numerator).
 * @param aDataTwo The vector to divide by (denominator).
 * @relates Vec4f
 *
 * @note No division-by-zero checks are performed. Ensure components of @p aDataTwo are non-zero.
 */
inline void operator/=(Vec4f& aDataOne, const Vec4f& aDataTwo);   
/**
* @brief Performs scalar division and assignment for Vec3f.
*
* @details Divides each component of @p aDataOne by the scalar @p aScalar,
* and stores the result back in @p aDataOne.
*
* @param aDataOne The vector to modify.
* @param aScalar The scalar float divisor.
* @relates Vec3f
*
* @warning No division-by-zero checks are performed. Ensure @p aScalar is non-zero.
*/
inline void operator/=(Vec4f& aDataOne, const float& aScalar);

/** @} */
#include "Vector4f.inl" 