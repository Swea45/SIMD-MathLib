#pragma once


/**
 * @file Vec2f.h
 * @brief Alias configuration for 2D vector type used throughout the codebase.
 *
 * @details
 * ### Why this approach?
 * - Improves code maintainability: logic only needs to be written once.
 * - Allows easy switching between scalar and SIMD implementations depending on use.
 * - Enables platform-specific optimization (e.g., fall back to scalar on non-SIMD platforms).
 *
 * ### How to switch:
 * - Comment out the define `Vec2fBasic` to switch to using SIMD vector 2 implementation.
 * - To use the SIMD implementation: ensure `Vec2fBasic` is *not* defined anywhere else.
 *
 * 
 * @warning
 * Using sizeof on 'Vec2f' will give different results depending if Vec2fBasic is defined or not.
 * - Vector2fScalar is aligned to 8 bytes.
 * - Vector2fSIMD is aligned to 16 bytes.
 *
 * 
 * @see Vector2fScalar  The basic float-based implementation.
 * @see Vector2fSIMD  The SIMD-accelerated implementation.
 */


#define Vec2fBasic
#ifdef Vec2fBasic
#include "Vector2f\Vector2fScalar.h"
using Vec2f = Vector2fScalar;
#else
#include "Vector2f\Vector2fSIMD" //Not created yet
using Vec2f = Vector2fSIMD;
#endif