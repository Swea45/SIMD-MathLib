#pragma once
#include <emmintrin.h>
#include <string.h>
/**
 * @brief Vec3f is a SIMD-accelerated 3D vector class aligned to 16 bytes.
 *
 * The vector stores data in a 128-bit SSE register (__m128), allowing for fast
 * SIMD operations. Components can be accessed via {@code x}, {@code y}, and {@code z}.
 * The fourth (unused) component is set to 0.0f to maintain 16-byte alignment.
 *
 * @warning Values are not checked for infinity or NaN. Use with caution,
 * as invalid values may cause crashes or undefined behavior during SIMD operations.
 */
class Vec3f
{
public:
	union
	{
		__m128 data;
		struct { float x, y, z; };
	};

/**
* Begin Constructors Group
* @name Constructors
* @brief Ways to initialize an instance of Vec3f.
* @{
*/

	/// @brief Default constructor. Initializes all components to zero.
	Vec3f() : data(_mm_setzero_ps()) {};
	/// @brief Copy constructor. Can use Vec3f or a __m128 to copy the data.
	Vec3f(__m128 aSIMDdata) : data(aSIMDdata) {};
	/// @brief Initialzes all componets (x, y, z) to the same float value.
	Vec3f(float aScalar) : data(_mm_set_ps(0.0f, aScalar, aScalar, aScalar)) {};
	/// @brief Initializes Vec3f with individual x, y, z values.
	Vec3f(float aX, float aY, float aZ) : data(_mm_set_ps(0.0f, aZ, aY, aX)) {};
/** @} */ 
// End Constructors Group

	//LengthSqr()
	//Length()

	//Normalized
	//Normalize

	//Dot
	//Cross

	//DistanceTo
};

/**
* @name Operators
* @brief Vec3f operators.
* @{
*/
/**
* @brief Equal for vector3s.
* 
* This operator checks if X, Y, Z are equal between two vectors.
* 
* @param aDataOne first vector operand.
* @param aDataTwo second vector operand.
* @return A bool depending if the two vectors are equal.
* @relatesalso Vec3f
*/
inline bool operator==(const Vec3f& aDataOne, const Vec3f& aDataTwo);
/**
* @brief Not equal for vector3s.
*
* This operator checks if X, Y, Z are not equal between two vectors.
*
* @param aDataOne first vector operand.
* @param aDataTwo second vector operand.
* @return A bool depending if the two vectors are equal.
* @relatesalso Vec3f
*/
inline bool operator!=(const Vec3f& aDataOne, const Vec3f& aDataTwo);
/**
* @brief Negates the given 3D vector.
 * 
 * @param aDataOne The input vector to negate.
 * @return A new Vec3f where each component is the negation of the corresponding component in {@code aDataOne}.
 * @relatesalso Vec3f
 */
inline Vec3f operator-(const Vec3f& aDataOne); 

/**
 * @brief Add for vector3s.
 * 
 * This operator returns a new Vec3f that is the result of adding
 * each corresponding component of the two input Vec3f vectors.
 *
 * @param aDataOne first vector operand.
 * @param aDataTwo second vector operand.
 * @return A new Vec3f representing the sum of aDataOne and aDataTwo.
 * @relatesalso Vec3f
*/
inline Vec3f operator+(const Vec3f& aDataOne, const Vec3f& aDataTwo);
/**
 * @brief Subtract for vector3s.
 *
 * This operator returns a new Vec3f that is the result of subtracting
 * each corresponding component from the first Vec3f by the second Vec3f.
 *
 * @param aDataOne vector to subtract from (minuend).
 * @param aDataTwo vector to subtract (subtrahend).
 * @return A new Vec3f representing the difference of aDataOne and aDataTwo.
 * @relatesalso Vec3f
*/
inline Vec3f operator-(const Vec3f& aDataOne, const Vec3f& aDataTwo);
/**
* @brief Multiplication for Vector3s.
* 
* This operator return a new Vec3f that is the result of multiplying 
* each corresponding component from the first Vec3f by the second Vec3f.
* 
* @param aDataOne first vector.
* @param aDataTwo second vector.
* @return A new Vec3f representing the sum of aDataOne and aDataTwo.
* @relatesalso Vec3f
*/
inline Vec3f operator*(const Vec3f& aDataOne, const Vec3f& aDataTwo);
/**
* @brief Multiplication for Vector3s.
* 
* This operator return a new Vec3f that is the result of multiplying
* each corresponding component with a scalar.
* 
* @param aDataOne a Vector.
* @param aScalar float value.
* @return A new Vec3f representing the sum of aDataOne by aScalar;
* @relatesalso Vec3f
*/
inline Vec3f operator*(const Vec3f& aDataOne, const float& aScalar); 
/**
* @brief Multiplication for Vector3s.
*
* This operator return a new Vec3f that is the result of multiplying
* each corresponding component with a scalar.
*
* @param aScalar float value.
* @param aDataOne a Vector.
* @return A new Vec3f representing the sum of aDataOne by aScalar;
* @relatesalso Vec3f
*/
inline Vec3f operator*(const float& aScalar, const Vec3f& aDataOne); 
/**
 * @brief component-wise division for Vec3f.
 *
 * Performs element-wise division between two Vec3f vectors.
 * Each component of the resulting vector is the result of dividing
 * the corresponding components of {@code aDataOne} by {@code aDataTwo}.
 *
 * @param aDataOne The numerator vector.
 * @param aDataTwo The denominator vector.
 * @return A new Vec3f where each component is {@code aDataOne[i] / aDataTwo[i]}.
 *
 * @note No division-by-zero checks are performed; ensure {@code aDataTwo} components are non-zero.
 * @relatesalso Vec3f
 */
inline Vec3f operator/(const Vec3f& aDataOne, const Vec3f& aDataTwo);
/**
 * @brief SIMD scalar division for Vec3f.
 *
 * Divides each component of the given Vec3f by a scalar float value.
 *
 * @param aDataOne The vector whose components are to be divided.
 * @param aScalar The scalar float divisor.
 * @return A new Vec3f where each component is {@code aDataOne[i] / aScalar}.
 *
 * @note No division-by-zero checks are performed; ensure {@code aScalar} is non-zero.
 * @relatesalso Vec3f
 */
inline Vec3f operator/(const Vec3f& aDataOne, const float& aScalar);

/**
 * @brief Performs component-wise addition and assignment for Vec3f.
 *
 * Modifies @p aDataOne by adding each component of @p aDataTwo to it.
 *
 * @param aDataOne The left-hand Vec3f to be modified.
 * @param aDataTwo The right-hand Vec3f to add.
 * @relates Vec3f
 */
inline void operator+=(Vec3f& aDataOne, const Vec3f& aDataTwo);
/**
 * @brief Performs component-wise subtraction and assignment for Vec3f.
 *
 * Modifies @p aDataOne by subtracting each component of @p aDataTwo from it.
 *
 * @param aDataOne The left-hand Vec3f to be modified (minuend).
 * @param aDataTwo The right-hand Vec3f to subtract (subtrahend).
 * @relates Vec3f
 */
inline void operator-=(Vec3f& aDataOne, const Vec3f& aDataTwo);
/**
 * @brief Performs component-wise multiplication and assignment for Vec3f.
 *
 * Multiplies each component of @p aDataOne by the corresponding component of @p aDataTwo,
 * and stores the result in @p aDataOne.
 *
 * @param aDataOne The vector to modify (left-hand side).
 * @param aDataTwo The vector to multiply with (right-hand side).
 * @relates Vec3f
 */
inline void operator*=(Vec3f& aDataOne, const Vec3f& aDataTwo);  

/**
 * @brief Performs scalar multiplication and assignment for Vec3f.
 *
 * Multiplies each component of @p aDataOne by the scalar @p aScalar,
 * and stores the result back in @p aDataOne.
 *
 * @param aDataOne The vector to modify.
 * @param aScalar The scalar float multiplier.
 * @relates Vec3f
 */
inline void operator*=(Vec3f& aDataOne, const float& aScalar);   

/**
 * @brief Performs component-wise division and assignment for Vec3f.
 *
 * Divides each component of @p aDataOne by the corresponding component of @p aDataTwo,
 * and stores the result in @p aDataOne.
 *
 * @param aDataOne The vector to be modified (numerator).
 * @param aDataTwo The vector to divide by (denominator).
 * @relates Vec3f
 *
 * @note No division-by-zero checks are performed. Ensure components of @p aDataTwo are non-zero.
 */
inline void operator/=(Vec3f& aDataOne, const Vec3f& aDataTwo);  
/**
 * @brief Performs scalar division and assignment for Vec3f.
 *
 * Divides each component of @p aDataOne by the scalar @p aScalar,
 * and stores the result back in @p aDataOne.
 *
 * @param aDataOne The vector to modify.
 * @param aScalar The scalar float divisor.
 * @relates Vec3f
 *
 * @warning No division-by-zero checks are performed. Ensure @p aScalar is non-zero.
 */
inline void operator/=(Vec3f& aDataOne, const float& aScalar);  

/** @} */

#include "Vector3.inl"

