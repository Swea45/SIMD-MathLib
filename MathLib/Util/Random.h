#pragma once
#include <assert.h>
#include <random>


namespace BitBloom
{
/**
*  @defgroup RandomUtils Random Utilities
*  @brief Utility functions for generating random values.
*  @{
*/


/**
* @brief Global random number engine used by the BitBloom::Random functions.
*
* This engine is seeded once and reused to avoid the overhead of
* re-creating the engine each time a random value is generated.
*
* You may reseed this engine manually to produce deterministic results:
* @code
* BitBloom::GlobalRandomEngine.seed(1234);
* @endcode
*/
static std::mt19937 GlobalRandomEngine(std::random_device{}());   


/**
* @brief Generates a random integer between aMin and aMax (inclusive).
*
* @param aMin The minimum value of the range.
* @param aMax The maximum value of the range.
* @return A random integer in [aMin, aMax].
*/
int Random(int aMin, int aMax) 
{
	assert(aMin <= aMax);
	//std::mt19937 dev(std::random_device{}());
	std::uniform_int_distribution<int> dist(aMin, aMax);
	return dist(GlobalRandomEngine);
}

/**
 * @brief Generates a random float between aMin and aMax (inclusive).
 *
 * @param aMin The minimum float value.
 * @param aMax The maximum float value.
 * @return A random float in [aMin, aMax].
 */
float Random(float aMin, float aMax)
{
	assert(aMin <= aMax); 
	//std::mt19937 dev(std::random_device{}());
	std::uniform_real_distribution<float> dist(aMin, aMax);
	return dist(GlobalRandomEngine);
}

/**
 * @brief Generates a random double between aMin and aMax (inclusive).
 *
 * @param aMin The minimum double value.
 * @param aMax The maximum double value.
 * @return A random double in [aMin, aMax].
 */
double Random(double aMin, double aMax)
{
	assert(aMin <= aMax);
	//std::mt19937 dev(std::random_device{}());
	std::uniform_real_distribution<double> dist(aMin, aMax); 
	return dist(GlobalRandomEngine); 
}

/// @} 
}// namespace BitBloom 

/// @brief Namespace alias for BitBloom. 
namespace BB = BitBloom;