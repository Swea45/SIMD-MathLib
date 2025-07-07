#pragma once
/**
* @brief Vec22fScalar is a scalar vector class aligned to 8 bytes.
*
* @details The Vector stores data in two separate floats. Components can be accessed via {@code x} and {@code y}.
*
* @warning Values are not checked for infinity or NaN. Use with caution,
* as invalid values may cause crashes or undefined behavior during operations. 
*/
class Vector2fScalar
{
public:
	float x, y;
	
/**
* Begin Constructors Group
* @name Constructors
* @brief Ways to initialize an instance of Vector2fScalar
* @{
*/

/// @brief Default constructor. Initializes all components to zero.
	Vector2fScalar() : x(0.0f), y(0.0f) {};
/// @brief Copy constructor. Use another Vector2fScalar to copy data.
	Vector2fScalar(const Vector2fScalar& aVector) : x(aVector.x), y(aVector.y) {};
/// @brief Initializes all components (x, y) to the same float value.
	Vector2fScalar(float aScalar) : x(aScalar), y(aScalar) {};
/// @brief Initializes Vector2fScalar with individual x, y values.
	Vector2fScalar(float aX, float aY) : x(aX), y(aY) {}; 
/// @}
// End Constructors Group

/**
* @brief Computes the squared length (magnitude) of the vector.
* 
* @details This is more efficient than calculating the actual length since it avoids
* the square root operation. Useful for comparisons where the exact length is not 
* required.
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
	inline Vector2fScalar GetNormalized();
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
	inline float Dot(const Vector2fScalar& aVector);
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
	inline Vector2fScalar DistanceTo(const Vector2fScalar& aVector);
	/**
* @brief Returns a copy of this vector rotated around a specified angle.
*
* @details Performs a 2D rotation of the vector using the right-hand rule.
*
* @param aAngle The angle of rotation in radians.
* @return A new Vector2fScalar representing the rotated vector.
*/
	inline Vector2fScalar GetRotated(float aAngle);
/**
 * @brief Rotates this vector in place around by a given angle.
 *
 * @details The rotation is performed in the XY plane, using the right-hand rule.
 *
 * @param aAngle The angle of rotation in radians.
 */
	inline void Rotate(float aAngle);

};

/**
* @name Operators
* @brief Vector2fScalar operators.
* @{
*/
/**
* @brief Equal for vector2s.
* 
* @details This operator checks if X, Y are equal between two vectors.
* 
* @param aDataOne first vector operand.
* @param aDataTwo second vector operand.
* @return A bool depending if the two vectors are equal.
* @relatesalso Vector2fScalar
*/
inline bool operator==(const Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo);
/**
* @brief Not equal for vector2s.
*
* @details This operator checks if X, Y are not equal between two vectors.
*
* @param aDataOne first vector operand.
* @param aDataTwo second vector operand.
* @return A bool depending if the two vectors are equal.
* @relatesalso Vector2fScalar 
*/
inline bool operator!=(const Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo);
/**
* @brief Negates the given 2D vector.
*
* @param aDataOne The input vector to negate.
* @return A new Vector2fScalar where each component is the negation of the corresponding component in {@code aDataOne}.
* @relatesalso Vector2fScalar
*/
inline Vector2fScalar operator-(const Vector2fScalar& aDataOne);  

/**
* @brief Add for vector2s.
*
* @details This operator returns a new Vector2fScalar that is the result of adding
* each corresponding component of the two input Vector2fScalar vectors.
*
* @param aDataOne first vector operand.
* @param aDataTwo second vector operand.
* @return A new Vector2fScalar representing the sum of aDataOne and aDataTwo.
* @relatesalso Vector2fScalar
*/
inline Vector2fScalar operator+(const Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo);
/**
* @brief Subtract for vector2s.
*
* @details This operator returns a new Vector2fScalar that is the result of subtracting
* each corresponding component from the first Vector2fScalar by the second Vector2fScalar.
*
* @param aDataOne vector to subtract from (minuend).
* @param aDataTwo vector to subtract (subtrahend).
* @return A new Vector2fScalar representing the difference of aDataOne and aDataTwo.
* @relatesalso Vector2fScalar
*/
inline Vector2fScalar operator-(const Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo);
/**
* @brief Multiplication for Vector2s.
*
* @details This operator return a new Vector2fScalar that is the result of multiplying
* each corresponding component from the first Vector2fScalar by the second Vector2fScalar.
*
* @param aDataOne first vector.
* @param aDataTwo second vector.
* @return A new Vector2fScalar representing the sum of aDataOne and aDataTwo.
* @relatesalso Vector2fScalar
*/
inline Vector2fScalar operator*(const Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo);
/**
* @brief Multiplication for Vector2s.
*
* @details This operator return a new Vector2fScalar that is the result of multiplying
* each corresponding component with a scalar.
*
* @param aDataOne a Vector.
* @param aScalar float value.
* @return A new Vector2fScalar representing the sum of aDataOne by aScalar;
* @relatesalso Vector2fScalar
*/
inline Vector2fScalar operator*(const Vector2fScalar& aDataOne, const float& aScalar);
/**
* @brief Multiplication for Vector2s.
*
* @details This operator return a new Vector2fScalar that is the result of multiplying
* each corresponding component with a scalar.
*
* @param aScalar float value.
* @param aDataOne a Vector.
* @return A new Vector2fScalar representing the sum of aDataOne by aScalar;
* @relatesalso Vector2fScalar
*/
inline Vector2fScalar operator*(const float& aScalar, const Vector2fScalar& aDataOne); 
/**
 * @brief Division for Vector2s.
 *
 * @details Performs element-wise division between two Vector2fScalar vectors.
 * Each component of the resulting vector is the result of dividing
 * the corresponding components of {@code aDataOne} by {@code aDataTwo}.
 *
 * @param aDataOne The numerator vector.
 * @param aDataTwo The denominator vector.
 * @return A new Vector2fScalar where each component is {@code aDataOne[i] / aDataTwo[i]}.
 *
 * @note No division-by-zero checks are performed; ensure {@code aDataTwo} components are non-zero.
 * @relatesalso Vector2fScalar
 */
inline Vector2fScalar operator/(const Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo);
/**
 * @brief Division for Vector2s.
 *
 * @details Divides each component of the given Vector2fScalar by a scalar float value.
 *
 * @param aDataOne The vector whose components are to be divided.
 * @param aScalar The scalar float divisor.
 * @return A new Vector2fScalar where each component is {@code aDataOne[i] / aScalar}.
 *
 * @note No division-by-zero checks are performed; ensure {@code aScalar} is non-zero.
 * @relatesalso Vector2fScalar
 */
inline Vector2fScalar operator/(const Vector2fScalar& aDataOne, const float& aScalar);

/**
* @brief Performs component-wise addition and assignment for Vector2s.
*
* @details Modifies @p aDataOne by adding each component of @p aDataTwo to it.
*
* @param aDataOne The left-hand Vector2fScalar to be modified. 
* @param aDataTwo The right-hand Vector2fScalar to add.
* @relates Vector2fScalar
*/
inline void operator+=(Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo);
/**
* @brief Performs component-wise subtraction and assignment for Vector2s.
*
* @details Modifies @p aDataOne by subtracting each component of @p aDataTwo from it.
*
* @param aDataOne The left-hand Vector2fScalar to be modified (minuend).
* @param aDataTwo The right-hand Vector2fScalar to subtract (subtrahend).
* @relates Vector2fScalar
*/
inline void operator-=(Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo);
/**
* @brief Performs component-wise multiplication and assignment for Vector2s.
*
* @details Multiplies each component of @p aDataOne by the corresponding component of @p aDataTwo,
* and stores the result in @p aDataOne.
*
* @param aDataOne The Vector2fScalar to modify (left-hand side).
* @param aDataTwo The Vector2fScalar to multiply with (right-hand side).
* @relates Vector2fScalar
*/
inline void operator*=(Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo);
/**
 * @brief Performs scalar multiplication and assignment for Vector2s.
 *
 * @details Multiplies each component of @p aDataOne by the scalar @p aScalar,
 * and stores the result back in @p aDataOne.
 *
 * @param aDataOne The Vector2fScalar to modify.
 * @param aScalar The scalar float multiplier.
 * @relates Vector2fScalar
 */
inline void operator*=(Vector2fScalar& aDataOne, const float& aScalar);
/**
 * @brief Performs component-wise division and assignment for Vector2s.
 *
 * @details Divides each component of @p aDataOne by the corresponding component of @p aDataTwo,
 * and stores the result in @p aDataOne.
 *
 * @param aDataOne The Vector2fScalar to be modified (numerator).
 * @param aDataTwo The Vector2fScalar to divide by (denominator).
 * @relates Vector2fScalar
 *
 * @note No division-by-zero checks are performed. Ensure components of @p aDataTwo are non-zero.
 */
inline void operator/=(Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo);
/**
 * @brief Performs scalar division and assignment for Vector2s.
 *
 * @details Divides each component of @p aDataOne by the scalar @p aScalar,
 * and stores the result back in @p aDataOne.
 *
 * @param aDataOne The Vector2fScalar to modify.
 * @param aScalar The scalar float divisor.
 * @relates Vector2fScalar
 *
 * @warning No division-by-zero checks are performed. Ensure @p aScalar is non-zero.
 */
inline void operator/=(Vector2fScalar& aDataOne, const float& aScalar); 
/** @} */
#include "Vector2fScalar.inl"

