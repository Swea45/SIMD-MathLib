
#include"pch.h"
#include "Vector3.h"

//[Create a Vec3f from memory address]
Vec3f Vec3f::ConstructFromMemory(const void* someData) 
{
	Vec3f result;
	result.CopyDataFromMemory(someData);
	return result;
}

//[Copy a Vec3f from memory address]
void Vec3f::CopyDataFromMemory(const void* someData)
{
	const float* data = reinterpret_cast<const float*>(someData);
	x = data[0];
	y = data[1];
	z = data[2];
}

