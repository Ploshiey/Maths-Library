#include "vector.h"
#include "matrix.h"
#pragma once

#pragma region Vector2
#pragma region Constructors
Vector2::Vector2() 
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float _x, float _y) 
{
	x = _x;
	y = _y;
}

Vector2::Vector2(const Vector2& other) 
{
	x = other.x;
	y = other.y;
}

#pragma endregion

#pragma region Assignment
Vector2& Vector2::operator = (const Vector2& other) 
{
	x = other.x;
	y = other.y;
	return *this;
}

#pragma endregion

#pragma region Index Operators
float Vector2::operator [] (int index) const 
{
	return data[index];
}

float& Vector2::operator [] (int index)
{
	return data[index];
}
#pragma endregion

#pragma region Dot Product
float Vector2::dot(const Vector2& other) const
{
	return 
	{
		x * other.x + y * other.y 
	};
}
#pragma endregion

#pragma region Angle Between
float Vector2::angleBetween(const Vector2& other) const
{
	return
	{
		acos((x * other.x + y * other.y) / (sqrt(pow(x, 2.0f) + pow(y, 2.0f)) * sqrt(pow(other.x, 2.0f) + pow(other.y, 2.0f))))
	};
}
#pragma endregion

#pragma region Magnitude
float Vector2::magnitude() const
{
	return
	{
		sqrt(pow(x, 2.0f) + pow(y, 2.0f))
	};
}

float Vector2::magnitudeSqr() const
{
	return
	{
		pow(x, 2.0f) + pow(y, 2.0f) 
	};
}
#pragma endregion

#pragma region Normalising

void Vector2::normalise()
{
	*this = this->normalised();
}

Vector2 Vector2::normalised() const
{
	return
	{
		*this / this->magnitude()
	};
}
#pragma endregion

#pragma region Vector Operations
Vector2 Vector2::operator + (const Vector2& other) const 
{
	return 
	{ 
		x + other.x, y + other.y 
	};
}

Vector2& Vector2::operator += (const Vector2& other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Vector2 Vector2::operator - (const Vector2& other) const 
{
	return 
	{
		x - other.x, y - other.y 
	};
}

Vector2& Vector2::operator -= (const Vector2& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

#pragma endregion

#pragma region Scalar Operations
Vector2 Vector2::operator * (float scalar) const 
{
	return 
	{
		x * scalar, y * scalar 
	};
}
Vector2& Vector2::operator *= (float scalar)
{
	x *= scalar;
	y *= scalar;
	return *this;
}
Vector2 Vector2::operator / (float scalar) const
{
	return 
	{ 
		x / scalar, y / scalar 
	};
}
Vector2& Vector2::operator /= (float scalar)
{
	x /= scalar;
	y /= scalar;
	return *this;
}

#pragma endregion

#pragma region Distances
float Vector2::distanceTo(const Vector2& other) const
{
	return
	{
		sqrt(pow(other.y - y, 2.0f) + pow(other.x - x, 2.0f))
	};
}

float Vector2::distanceToSqr(const Vector2& other) const
{
	return
	{
		pow(other.y - y, 2.0f) + pow(other.x - x, 2.0f)
	};
}
#pragma endregion

#pragma endregion

#pragma region Vector3
#pragma region Constructors
Vector3::Vector3() 
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float _x, float _y, float _z) 
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3::Vector3(const Vector3& other) 
{
	x = other.x;
	y = other.y;
	z = other.z;
}

#pragma endregion

#pragma region Assignment
Vector3& Vector3::operator = (const Vector3& other) 
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

#pragma endregion

#pragma region Index Operators
float Vector3::operator [] (int index) const 
{
	return data[index];
}

float& Vector3::operator [] (int index)
{
	return data[index];
}
#pragma endregion

#pragma region Dot Product
float Vector3::dot(const Vector3& other) const
{
	return 
	{
		x * other.x + y * other.y + z * other.z
	};
}
#pragma endregion

#pragma region Angle Between
float Vector3::angleBetween(const Vector3& other) const
{
	return
	{
		acos((x * other.x + y * other.y + z * other.z) / (sqrt(pow(x, 2.0f) + pow(y, 2.0f) + pow(z, 2.0f)) * sqrt(pow(other.x, 2.0f) + pow(other.y, 2.0f) + pow(other.z, 2.0f))))
	};
}
#pragma endregion

#pragma region Cross Product
Vector3 Vector3::cross(const Vector3& other) const
{
	return
	{
		y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x
	};
}
#pragma endregion

#pragma region Magnitude
float Vector3::magnitude() const
{
	return
	{
		sqrt(pow(x, 2.0f) + pow(y, 2.0f) + pow(z, 2.0f))
	};
}

float Vector3::magnitudeSqr() const
{
	return
	{
		pow(x, 2.0f) + pow(y, 2.0f) + pow(z, 2.0f) 
	};
}
#pragma endregion

#pragma region Normalising

void Vector3::normalise()
{
	*this = this->normalised();
}

Vector3 Vector3::normalised() const
{
	return
	{ 
		*this / this->magnitude()
	};
}
#pragma endregion

#pragma region Vector Operations
Vector3 Vector3::operator + (const Vector3& other) const 
{
	return 
	{ 
		x + other.x, y + other.y, z + other.z 
	};
}

Vector3& Vector3::operator += (const Vector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vector3 Vector3::operator - (const Vector3& other) const 
{
	return 
	{
		x - other.x, y - other.y , z - other.z
	};
}

Vector3& Vector3::operator -= (const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

#pragma endregion

#pragma region Scalar Operations
Vector3 Vector3::operator * (float scalar) const 
{
	return 
	{
		x * scalar, y * scalar, z * scalar
	};
}
Vector3& Vector3::operator *= (float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}
Vector3 Vector3::operator / (float scalar) const
{
	return 
	{ 
		x / scalar, y / scalar, z / scalar 
	};
}
Vector3& Vector3::operator /= (float scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
	return *this;
}

#pragma endregion

#pragma region Distances
float Vector3::distanceTo(const Vector3& other) const
{
	return
	{
		sqrt(pow(other.y - y, 2.0f) + pow(other.x - x, 2.0f) + pow(other.z - z, 2.0f))
	};
}

float Vector3::distanceToSqr(const Vector3& other) const
{
	return
	{
		pow(other.y - y, 2.0f) + pow(other.x - x, 2.0f) + pow(other.z - z, 2.0f)
	};
}
#pragma endregion

#pragma region Vector4
Vector3::operator Vector4() const
{
	return
	{
		x, y, z, 0
	};
}
#pragma endregion

#pragma endregion

#pragma region Vector4
#pragma region Constructors
Vector4::Vector4() 
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vector4::Vector4(float _x, float _y, float _z, float _w) 
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

Vector4::Vector4(const Vector4& other) 
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
}

#pragma endregion

#pragma region Assignment
Vector4& Vector4::operator = (const Vector4& other) 
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
	return *this;
}

#pragma endregion

#pragma region Index Operators
float Vector4::operator [] (int index) const 
{
	return data[index];
}

float& Vector4::operator [] (int index)
{
	return data[index];
}
#pragma endregion

#pragma region Dot Product
float Vector4::dot(const Vector4& other) const
{
	return 
	{
		x * other.x + y * other.y + z * other.z + w * other.w
	};
}
#pragma endregion

#pragma region Angle Between
float Vector4::angleBetween(const Vector4& other) const
{
	return
	{
		acos((x * other.x + y * other.y + z * other.z + w * other.w) / 
			(sqrt(pow(x, 2.0f) + pow(y, 2.0f) + pow(z, 2.0f) + pow(w, 2.0f)) * 
			sqrt(pow(other.x, 2.0f) + pow(other.y, 2.0f) + pow(other.z, 2.0f) + pow(other.w, 2.0f))))
	};
}
#pragma endregion

#pragma region Cross Product
Vector4 Vector4::cross(const Vector4& other) const
{
	return
	{
		y * other.z - z * other.y, 
		z * other.x - x * other.z,
		x * other.y - y * other.x, w
	};
}
#pragma endregion

#pragma region Magnitude
float Vector4::magnitude() const
{
	return
	{
		sqrt(pow(x, 2.0f) + pow(y, 2.0f) + pow(z, 2.0f) + pow(w, 2.0f))
	};
}

float Vector4::magnitudeSqr() const
{
	return
	{
		pow(x, 2.0f) + pow(y, 2.0f) + pow(z, 2.0f) + pow(w, 2.0f) 
	};
}
#pragma endregion

#pragma region Normalising

void Vector4::normalise()
{
	*this = this->normalised();
}

Vector4 Vector4::normalised() const
{
	return
	{ 
		*this / this->magnitude()
	};
}
#pragma endregion

#pragma region Vector Operations
Vector4 Vector4::operator + (const Vector4& other) const 
{
	return 
	{ 
		x + other.x, y + other.y, z + other.z, w + other.w 
	};
}

Vector4& Vector4::operator += (const Vector4& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}

Vector4 Vector4::operator - (const Vector4& other) const 
{
	return 
	{
		x - other.x, y - other.y, z - other.z, w - other.w
	};
}

Vector4& Vector4::operator -= (const Vector4& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

#pragma endregion

#pragma region Scalar Operations
Vector4 Vector4::operator * (float scalar) const 
{
	return 
	{
		x * scalar, y * scalar, z * scalar, w * scalar
	};
}
Vector4& Vector4::operator *= (float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
	return *this;
}
Vector4 Vector4::operator / (float scalar) const
{
	return 
	{ 
		x / scalar, y / scalar, z / scalar, w / scalar 
	};
}
Vector4& Vector4::operator /= (float scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
	w /= scalar;
	return *this;
}

#pragma endregion

#pragma region Distances
float Vector4::distanceTo(const Vector4& other) const
{
	return
	{
		sqrt(pow(other.y - y, 2.0f) + pow(other.x - x, 2.0f) + pow(other.z - z, 2.0f) + pow(other.w - w, 2.0f))
	};
}

float Vector4::distanceToSqr(const Vector4& other) const
{
	return
	{
		pow(other.y - y, 2.0f) + pow(other.x - x, 2.0f) + pow(other.z - z, 2.0f) + pow(other.w - w, 2.0f)
	};
}
#pragma endregion

#pragma region Vector3
Vector4::operator Vector3() const
{
	return
	{
		x, y, z
	};
}
#pragma endregion

#pragma endregion

#pragma region Thank You Beyonce
//All credit for this goes to Beyonce, I couldn't have done this without her. She is the light of my life. Taylor Swift is also so thankful for you Beyonce.
#pragma endregion