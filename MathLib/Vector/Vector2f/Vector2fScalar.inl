#pragma once
#include "Vector2fScalar.h"
#include <cmath>

#pragma region ClassFunctions
inline float Vector2fScalar::LengthSqr()
{
    return (x * x) + (y * y); 
}

inline float Vector2fScalar::Length()
{
    return std::sqrtf((x*x) + (y * y));
}

inline Vector2fScalar Vector2fScalar::GetNormalized()
{
    return Vector2fScalar(x, y) / Length(); 
}

inline void Vector2fScalar::Normalize()
{
    float length = Length();
    x /= length; 
    y /= length; 
}

inline float Vector2fScalar::Dot(const Vector2fScalar& aVector)
{
    return (x * aVector.x) + (y * aVector.y);
}

inline Vector2fScalar Vector2fScalar::DistanceTo(const Vector2fScalar& aVector)
{
    return { aVector.x - x, aVector.y - y };
}

inline Vector2fScalar Vector2fScalar::GetRotated(float aAngle)
{
    float cosTheta = std::cos(aAngle);
    float sinTheta = std::sin(aAngle);

    return { cosTheta * x - sinTheta * y, sinTheta * x + cosTheta * y };
}

inline void Vector2fScalar::Rotate(float aAngle)
{
    float cosTheta = std::cos(aAngle);
    float sinTheta = std::sin(aAngle);
    
    float newX = cosTheta * x - sinTheta * y;
    
    y = sinTheta * x + cosTheta * y;
    x = newX;
}

#pragma endregion

#pragma region OperatorDefinitions


inline bool operator==(const Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo)
{
    return aDataOne.x == aDataTwo.x && aDataOne.y == aDataTwo.y; 
}

inline bool operator!=(const Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo)
{
    return aDataOne.x != aDataTwo.x || aDataOne.y != aDataTwo.y; 
}

inline Vector2fScalar operator-(const Vector2fScalar& aDataOne)
{
    return { -aDataOne.x, -aDataOne.y }; 
}

inline Vector2fScalar operator+(const Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo)
{
    return { aDataOne.x + aDataTwo.x, aDataOne.y + aDataTwo.y };
}

inline Vector2fScalar operator-(const Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo)
{
    return { aDataOne.x - aDataTwo.x, aDataOne.y - aDataTwo.y };
}

inline Vector2fScalar operator*(const Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo)
{
    return { aDataOne.x * aDataTwo.x, aDataOne.y * aDataTwo.y };
}

inline Vector2fScalar operator*(const Vector2fScalar& aDataOne, const float& aScalar)
{
    return { aDataOne.x * aScalar, aDataOne.y * aScalar };
}

inline Vector2fScalar operator*(const float& aScalar, const Vector2fScalar& aDataOne)
{
    return { aDataOne.x * aScalar, aDataOne.y * aScalar };
}

inline Vector2fScalar operator/(const Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo)
{
    return { aDataOne.x / aDataTwo.x, aDataOne.y / aDataTwo.y };
}

inline Vector2fScalar operator/(const Vector2fScalar& aDataOne, const float& aScalar)
{
    return { aDataOne.x / aScalar, aDataOne.y / aScalar }; 
}

inline void operator+=(Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo)
{
    aDataOne = { aDataOne.x + aDataTwo.x, aDataOne.y + aDataTwo.y };
}

inline void operator-=(Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo)
{
    aDataOne = { aDataOne.x - aDataTwo.x, aDataOne.y - aDataTwo.y };
}

inline void operator*=(Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo)
{
    aDataOne = { aDataOne.x * aDataTwo.x, aDataOne.y * aDataTwo.y };
}

inline void operator*=(Vector2fScalar& aDataOne, const float& aScalar)
{
    aDataOne = { aDataOne.x * aScalar, aDataOne.y * aScalar };
}

inline void operator/=(Vector2fScalar& aDataOne, const Vector2fScalar& aDataTwo)
{
    aDataOne = { aDataOne.x / aDataTwo.x, aDataOne.y / aDataTwo.y };
}

inline void operator/=(Vector2fScalar& aDataOne, const float& aScalar)
{
    aDataOne = { aDataOne.x / aScalar, aDataOne.y / aScalar };
}

#pragma endregion