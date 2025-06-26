#pragma once
/**
* @brief Vec22fScalar is a scalar vector class aligned to 8 bytes.
*
* @details The Vector stores data in two seperate floats. Components can be accessed via {@code x} and {@code y}.
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
/// @brief Initialzes all components (x, y) to the same float value.
	Vector2fScalar(float aScalar) : x(aScalar), y(aScalar) {};
/// @brief Initialzes Vector2fScalar with individual x, y values.
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

	inline float Length();

	inline Vector2fScalar GetNormalized();

	inline void Normalize();

	inline float Dot(const Vector2fScalar& aVector);

	inline Vector2fScalar DistanceTo(const Vector2fScalar& aVector);

	inline Vector2fScalar GetRotated(float aAngle);

	inline void Rotated();

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

