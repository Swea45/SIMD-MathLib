#pragma once
#include "Vector2fScalar.h"

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
