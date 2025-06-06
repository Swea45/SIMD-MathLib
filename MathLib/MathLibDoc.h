#pragma once
/**
* @mainpage SIMD Math Library
* 
* @section intro_sec Introduction
* 
* The SIMD Math Library is a high-performance math toolkit designed to accelerate
* math operations using SIMD (Single Instruction, Multiple Data). 
* By aligning data to 16-byte boundaries and utilizing low-level SSE intrinsics, this library
* provides efficient calculations suited for graphics, physics, and real-time applications.
* 
* @section usage_sec Usage Example
 *
 * @code
 * #include "Vector3.h"
 *
 * Vec3f a(1.0f, 2.0f, 3.0f);
 * Vec3f b(0.5f, 1.5f, -1.0f);
 * Vec3f result = a + b;
 * @endcode
 * 
 * 
 *
 * @section warning_sec Warnings
 *
 * - No automatic checks for division by zero or invalid float values (e.g., NaN).
 * - No checks for positive or negative infinity values.
 * - Ensure all memory used in SIMD operations is properly aligned (16-byte alignment required).
 *
 * @section license_sec License
 *
 * MIT License (or specify your own).
 *
 * @author
 * Simon Carlsson
 * @date 2025 - 06 -06
*/