#pragma once
#include <emmintrin.h>
/**
 * @brief Vec3f is a SIMD-accelerated 3D vector class aligned to 16 bytes.
 *
 * @details The vector stores data in a 128-bit SSE register (__m128), allowing for fast
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
	Vec3f(const __m128& aSSEData) : data(aSSEData) {};
/// @brief Initialzes all componets (x, y, z) to the same float value.
	Vec3f(float aScalar) : data(_mm_set_ps(0.0f, aScalar, aScalar, aScalar)) {};
/// @brief Initializes Vec3f with individual x, y, z values.
	Vec3f(float aX, float aY, float aZ) : data(_mm_set_ps(0.0f, aZ, aY, aX)) {};
/** @} */ 
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
 * @return A new Vec3f representing the normalized vector.
 *
 * @note No check is performed for zero-length vectors. Normalizing a zero vector may produce invalid results.
 */
	inline Vec3f GetNormalized();  
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
	inline float Dot(const Vec3f& aVector); 
/**
 * @brief Computes the cross product between this vector and another.
 *
 * @details The cross product results in a vector that is perpendicular to both input vectors,
 * following the right-hand rule. Only valid and meaningful in 3D space.
 *
 * @param aVector The other vector to compute the cross product with.
 * @return A new Vec3f representing the cross product.
 */
	inline Vec3f Cross(const Vec3f& aVector);

/**
 * @brief Computes the distance from this vector to another.
 *
 * @details Calculates the Euclidean distance between the current vector and the specified vector.
 *
 * @param aVector The target vector to measure distance to.
 * @return A Vec3f representing the vector difference (not the scalar distance).
 *
 * @note If you want the scalar distance (i.e., the length of the vector between the two points),
 * consider using {@code (a - b).Length()} instead.
 */
	inline Vec3f DistanceTo(const Vec3f& aVector);


/**
* @brief Returns a copy of this vector rotated around a given axis by a specified angle.
*
* @details Performs a 3D rotation of the vector around the provided axis using the right-hand rule.
* 
* @param aAxis The axis to rotate around.
* @param aAngle The angle of rotation in radians.
* @return A new Vec3f representing the rotated vector.
*/
	inline Vec3f GetRotatedAroundAxis(Vec3f aAxis, float aAngle);
/**
 * @brief Returns a copy of this vector rotated around the X-axis by a given angle.
 *
 * @details Rotates the vector in the YZ plane using the right-hand rule.
 *
 * @param aAngle The angle of rotation in radians.
 * @return A new Vec3f representing the rotated vector.
 */
	inline Vec3f GetRotatedX(float aAngle); 
/**
 * @brief Returns a copy of this vector rotated around the Y-axis by a given angle.
 *
 * @details Rotates the vector in the XZ plane using the right-hand rule.
 *
 * @param aAngle The angle of rotation in radians.
 * @return A new Vec3f representing the rotated vector.
 */
	inline Vec3f GetRotatedY(float aAngle); 
/**
 * @brief Returns a copy of this vector rotated around the Z-axis by a given angle.
 *
 * @details Rotates the vector in the XY plane using the right-hand rule.
 *
 * @param aAngle The angle of rotation in radians.
 * @return A new Vec3f representing the rotated vector.
 */
	inline Vec3f GetRotatedZ(float aAngle); 


/**
* @brief Rotates the Vector around a given axis by a specified angle.
*
* @details Performs a 3D rotation of the vector around the provided axis using the right-hand rule.
*
* @param aAxis The axis to rotate around.
* @param aAngle The angle of rotation in radians.
*/
	inline void RotateAroundAxis(Vec3f aAxis, float aAngle);
/**
 * @brief Rotates this vector in place around the X-axis by a given angle.
 *
 * @details The rotation is performed in the YZ plane, using the right-hand rule.
 *
 * @param aAngle The angle of rotation in radians.
 */
	inline void RotateX(float aAngle); 
/**
 * @brief Rotates this vector in place around the Y-axis by a given angle.
 *
 * @details The rotation is performed in the XZ plane, using the right-hand rule.
 *
 * @param aAngle The angle of rotation in radians.
 */
	inline void RotateY(float aAngle);  
/**
 * @brief Rotates this vector in place around the Z-axis by a given angle.
 *
 * @details The rotation is performed in the XY plane, using the right-hand rule.
 *
 * @param aAngle The angle of rotation in radians.
 */
	inline void RotateZ(float aAngle);
};

/**
* @name Operators
* @brief Vec3f operators.
* @{
*/
/**
* @brief Equal for vector3s.
* 
* @details This operator checks if X, Y, Z are equal between two vectors.
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
* @details This operator checks if X, Y, Z are not equal between two vectors.
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
* @details This operator returns a new Vec3f that is the result of adding
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
 * @details This operator returns a new Vec3f that is the result of subtracting
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
* @details This operator return a new Vec3f that is the result of multiplying 
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
* @details This operator return a new Vec3f that is the result of multiplying
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
* @details This operator return a new Vec3f that is the result of multiplying
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
 * @details Performs element-wise division between two Vec3f vectors.
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
 * @details Divides each component of the given Vec3f by a scalar float value.
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
* @details Modifies @p aDataOne by adding each component of @p aDataTwo to it.
*
* @param aDataOne The left-hand Vec3f to be modified.
* @param aDataTwo The right-hand Vec3f to add.
* @relates Vec3f
*/
inline void operator+=(Vec3f& aDataOne, const Vec3f& aDataTwo);
/**
* @brief Performs component-wise subtraction and assignment for Vec3f.
*
* @details Modifies @p aDataOne by subtracting each component of @p aDataTwo from it.
*
* @param aDataOne The left-hand Vec3f to be modified (minuend).
* @param aDataTwo The right-hand Vec3f to subtract (subtrahend).
* @relates Vec3f
*/
inline void operator-=(Vec3f& aDataOne, const Vec3f& aDataTwo);
/**
* @brief Performs component-wise multiplication and assignment for Vec3f.
*
* @details Multiplies each component of @p aDataOne by the corresponding component of @p aDataTwo,
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
 * @details Multiplies each component of @p aDataOne by the scalar @p aScalar,
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
 * @details Divides each component of @p aDataOne by the corresponding component of @p aDataTwo,
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
 * @details Divides each component of @p aDataOne by the scalar @p aScalar,
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

#include "Vector3f.inl"

