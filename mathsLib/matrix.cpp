#include "matrix.h"
#include <cmath>
#pragma once

#pragma region Matrix2
#pragma region Constructors
Matrix2::Matrix2()
{
	memset(this, 0, sizeof(float) * 4);
}
Matrix2::Matrix2(float _00, float _01, float _10, float _11)
{
	data[0][0] = _00;
	data[0][1] = _01;
	data[1][0] = _10;
	data[1][1] = _11;
}
Matrix2::Matrix2(const Matrix2& other)
{
	memcpy(this, &other, 4 * sizeof(float));
}
#pragma endregion

#pragma region Assignment
Matrix2& Matrix2::operator = (const Matrix2& other)
{
	memcpy(this, &other, 4 * sizeof(float));
	return *this;
}
#pragma endregion

#pragma region Index
Vector2& Matrix2::operator[] (int index)
{
	return axis[index];
}

const Vector2& Matrix2::operator[] (int index) const
{
	return axis[index];
}
#pragma endregion

#pragma region Identity
void Matrix2::setIdentity()
{
	memset(this, 0, sizeof(float) * 4);
	data[0][0] = 1;
	data[1][1] = 1;
}
#pragma endregion

#pragma region Transposed
Matrix2 Matrix2::transposed() const
{
	Matrix2 result;
	result.data[0][0] = data[0][0];
	result.data[0][1] = data[1][0];
	result.data[1][0] = data[0][1];
	result.data[1][1] = data[1][1];
	return result;
}
#pragma endregion

#pragma region Matrix Multiplication
Matrix2 Matrix2::operator * (const Matrix2& other) const
{
	Matrix2 result;
	result.data[0][0] += data[0][0] * other.data[0][0];
	result.data[0][0] += data[1][0] * other.data[0][1];
	result.data[1][0] += data[0][0] * other.data[1][0];
	result.data[1][0] += data[1][0] * other.data[1][1];
	result.data[0][1] += data[0][1] * other.data[0][0];
	result.data[0][1] += data[1][1] * other.data[0][1];
	result.data[1][1] += data[0][1] * other.data[1][0];
	result.data[1][1] += data[1][1] * other.data[1][1];
	return result;
}

Vector2 Matrix2::operator * (const Vector2& v) const
{
	Vector2 result;
	result[0] += data[0][0] * v[0];
	result[0] += data[1][0] * v[1];
	result[1] += data[0][1] * v[0];
	result[1] += data[1][1] * v[1];
	return result;
}
#pragma endregion

#pragma region Rotation
void Matrix2::setRotate(float radians)
{
	xAxis = {cos(radians), -sin(radians)};
	yAxis = {sin(radians), cos(radians)};
}

void Matrix2::rotate(float radians)
{
	Matrix2 result;
	result.setRotate(radians);
	*this = *this * result;
}
#pragma endregion

#pragma region Scale
void Matrix2::setScaled(float x, float y)
{
	xAxis = {x, 0};
	yAxis = {0, y};
}
void Matrix2::setScaled(const Vector2& v)
{
	xAxis = {v.x, 0};
	yAxis = {0, v.y};
}
void Matrix2::scale(float x, float y) 
{
	Matrix2 result;
	result.setScaled(x, y);

	*this = *this * result;
}
void Matrix2::scale(const Vector2& v)
{
	Matrix2 result;
	result.setScaled(v.x, v.y);

	*this = *this * result;
}
#pragma endregion

#pragma endregion

#pragma region Matrix3
#pragma region Constructors
Matrix3::Matrix3()
{
	memset(this, 0, sizeof(float) * 9);
}
Matrix3::Matrix3(float _00, float _01, float _02, float _10, float _11, float _12, float _20, float _21, float _22)
{
	data[0][0] = _00;
	data[0][1] = _01;
	data[0][2] = _02;
	data[1][0] = _10;
	data[1][1] = _11;
	data[1][2] = _12;
	data[2][0] = _20;
	data[2][1] = _21;
	data[2][2] = _22;
}
Matrix3::Matrix3(const Matrix3& other)
{
	memcpy(this, &other, 9 * sizeof(float));
}
#pragma endregion

#pragma region Assignment
Matrix3& Matrix3::operator = (const Matrix3& other)
{
	memcpy(this, &other, 9 * sizeof(float));
	return *this;
}
#pragma endregion

#pragma region Index
Vector3& Matrix3::operator[] (int index)
{
	return axis[index];
}

const Vector3& Matrix3::operator[] (int index) const
{
	return axis[index];
}
#pragma endregion

#pragma region Identity
void Matrix3::setIdentity()
{
	memset(this, 0, sizeof(float) * 9);
	data[0][0] = 1;
	data[1][1] = 1;
	data[2][2] = 1;
}
#pragma endregion

#pragma region Transposed
Matrix3 Matrix3::transposed() const
{
	Matrix3 result;
			result.data[0][0] = data[0][0];
			result.data[0][1] = data[1][0];
			result.data[0][2] = data[2][0];
			result.data[1][0] = data[0][1];
			result.data[1][1] = data[1][1];
			result.data[1][2] = data[2][1];
			result.data[2][0] = data[0][2];
			result.data[2][1] = data[1][2];
			result.data[2][2] = data[2][2];
	return result;
}
#pragma endregion

#pragma region Translate
void Matrix3::setTranslate(float x, float y)
{
	translation.x = x;
	translation.y = y;
}

void Matrix3::setTranslate(const Vector2& other)
{
	translation.x = other.x;
	translation.y = other.y;
}

void Matrix3::translate(float x, float y)
{
	translation.x += x;
	translation.y += y;
}
void Matrix3::translate(const Vector2& other)
{
	translation.x += other.x;
	translation.y += other.y;
}
#pragma endregion

#pragma region Matrix Multiplication
Matrix3 Matrix3::operator * (const Matrix3& other) const
{
	Matrix3 result;
	result.data[0][0] += data[0][0] * other.data[0][0];
	result.data[0][0] += data[1][0] * other.data[0][1];
	result.data[0][0] += data[2][0] * other.data[0][2];
	result.data[1][0] += data[0][0] * other.data[1][0];
	result.data[1][0] += data[1][0] * other.data[1][1];
	result.data[1][0] += data[2][0] * other.data[1][2];
	result.data[2][0] += data[0][0] * other.data[2][0];
	result.data[2][0] += data[1][0] * other.data[2][1];
	result.data[2][0] += data[2][0] * other.data[2][2];
	result.data[0][1] += data[0][1] * other.data[0][0];
	result.data[0][1] += data[1][1] * other.data[0][1];
	result.data[0][1] += data[2][1] * other.data[0][2];
	result.data[1][1] += data[0][1] * other.data[1][0];
	result.data[1][1] += data[1][1] * other.data[1][1];
	result.data[1][1] += data[2][1] * other.data[1][2];
	result.data[2][1] += data[0][1] * other.data[2][0];
	result.data[2][1] += data[1][1] * other.data[2][1];
	result.data[2][1] += data[2][1] * other.data[2][2];
	result.data[0][2] += data[0][2] * other.data[0][0];
	result.data[0][2] += data[1][2] * other.data[0][1];
	result.data[0][2] += data[2][2] * other.data[0][2];
	result.data[1][2] += data[0][2] * other.data[1][0];
	result.data[1][2] += data[1][2] * other.data[1][1];
	result.data[1][2] += data[2][2] * other.data[1][2];
	result.data[2][2] += data[0][2] * other.data[2][0];
	result.data[2][2] += data[1][2] * other.data[2][1];
	result.data[2][2] += data[2][2] * other.data[2][2];
	return result;
}

Vector3 Matrix3::operator * (const Vector3& v) const
{
	Vector3 result;
	result[0] += data[0][0] * v[0];
	result[0] += data[1][0] * v[1];
	result[0] += data[2][0] * v[2];
	result[1] += data[0][1] * v[0];
	result[1] += data[1][1] * v[1];
	result[1] += data[2][1] * v[2];
	result[2] += data[0][2] * v[0];
	result[2] += data[1][2] * v[1];
	result[2] += data[2][2] * v[2];
	return result;
}
#pragma endregion

#pragma region Rotation
void Matrix3::setEuler(float pitch, float yaw, float roll)
{
	setRotateZ(roll);
	rotateY(yaw);
	rotateX(pitch);
}

void Matrix3::setRotateX(float radians)
{
	xAxis = {1, 0, 0};
	yAxis = {0, cos(radians), -sin(radians)};
	zAxis = {0, sin(radians), cos(radians)};
}

void Matrix3::rotateX(float radians)
{
	Matrix3 result;
	result.setRotateX(radians);
	*this = *this * result;
}
void Matrix3::setRotateY(float radians)
{
	xAxis = {cos(radians), 0, sin(radians)};
	yAxis = {0, 1, 0};
	zAxis = {-sin(radians), 0, cos(radians)};
}

void Matrix3::rotateY(float radians)
{
	Matrix3 result;
	result.setRotateY(radians);
	*this = *this * result;
}

void Matrix3::setRotateZ(float radians)
{
	xAxis = {cos(radians), -sin(radians), 0};
	yAxis = {sin(radians), cos(radians), 0};
	zAxis = {0, 0, 1};
}

void Matrix3::rotateZ(float radians)
{
	Matrix3 result;
	result.setRotateZ(radians);
	*this = *this * result;
}
#pragma endregion

#pragma region Scale
void Matrix3::setScaled(float x, float y, float z)
{
	xAxis = { x, 0, 0};
	yAxis = { 0, y, 0};
	zAxis = { 0, 0, z};
}
void Matrix3::setScaled(const Vector3& v)
{
	xAxis = { v.x, 0, 0 };
	yAxis = { 0, v.y, 0 };
	zAxis = { 0, 0, v.z };
}
void Matrix3::scale(float x, float y, float z)
{
	Matrix3 result;
	result.setScaled(x, y, z);
	*this = *this * result;
}
void Matrix3::scale(const Vector3& v)
{
	Matrix3 result;
	result.setScaled(v.x, v.y, v.z);

	*this = *this * result;
}
#pragma endregion

#pragma endregion

#pragma region Matrix4
#pragma region Constructors
Matrix4::Matrix4()
{
	memset(this, 0, sizeof(float) * 16);
}
Matrix4::Matrix4(float _00, float _01, float _02, float _03
				,float _10, float _11, float _12, float _13
				,float _20, float _21, float _22, float _23
				,float _30, float _31, float _32, float _33)
{
	data[0][0] = _00;
	data[0][1] = _01;
	data[0][2] = _02;
	data[0][3] = _03;
	data[1][0] = _10;
	data[1][1] = _11;
	data[1][2] = _12;
	data[1][3] = _13;
	data[2][0] = _20;
	data[2][1] = _21;
	data[2][2] = _22;
	data[2][3] = _23;
	data[3][0] = _30;
	data[3][1] = _31;
	data[3][2] = _32;
	data[3][3] = _33;
}
Matrix4::Matrix4(const Matrix4& other)
{
	memcpy(this, &other, 16 * sizeof(float));
}
#pragma endregion

#pragma region Assignment
Matrix4& Matrix4::operator = (const Matrix4& other)
{
	memcpy(this, &other, 16 * sizeof(float));
	return *this;
}
#pragma endregion

#pragma region Index
Vector4& Matrix4::operator[] (int index)
{
	return axis[index];
}

const Vector4& Matrix4::operator[] (int index) const
{
	return axis[index];
}
#pragma endregion

#pragma region Identity
void Matrix4::setIdentity()
{
	memset(this, 0, sizeof(float) * 16);
	data[0][0] = 1;
	data[1][1] = 1;
	data[2][2] = 1;
	data[3][3] = 1;
}
#pragma endregion

#pragma region Transposed
Matrix4 Matrix4::transposed() const
{
	Matrix4 result;
	result.data[0][0] = data[0][0];
	result.data[0][1] = data[1][0];
	result.data[0][2] = data[2][0];
	result.data[0][3] = data[3][0];
	result.data[1][0] = data[0][1];
	result.data[1][1] = data[1][1];
	result.data[1][2] = data[2][1];
	result.data[1][3] = data[3][1];
	result.data[2][0] = data[0][2];
	result.data[2][1] = data[1][2];
	result.data[2][2] = data[2][2];
	result.data[2][3] = data[3][2];
	result.data[3][0] = data[0][3];
	result.data[3][1] = data[1][3];
	result.data[3][2] = data[2][3];
	result.data[3][3] = data[3][3];
	return result;
}
#pragma endregion

#pragma region Translate
void Matrix4::setTranslate(float x, float y, float z)
{
	translation.x = x;
	translation.y = y;
	translation.z = z;
}
void Matrix4::setTranslate(const Vector3& other)
{
	translation.x = other.x;
	translation.y = other.y;
	translation.z = other.z;
}

void Matrix4::translate(float x, float y, float z)
{
	translation.x += x;
	translation.y += y;
	translation.z += z;
}
void Matrix4::translate(const Vector3& other)
{
	translation.x += other.x;
	translation.y += other.y;
	translation.z += other.z;

}
#pragma endregion

#pragma region Matrix Multiplication
Matrix4 Matrix4::operator * (const Matrix4& other) const
{
	Matrix4 result;
	result.data[0][0] += data[0][0] * other.data[0][0];
	result.data[0][0] += data[1][0] * other.data[0][1];
	result.data[0][0] += data[2][0] * other.data[0][2];
	result.data[0][0] += data[3][0] * other.data[0][3];
	result.data[1][0] += data[0][0] * other.data[1][0];
	result.data[1][0] += data[1][0] * other.data[1][1];
	result.data[1][0] += data[2][0] * other.data[1][2];
	result.data[1][0] += data[3][0] * other.data[1][3];
	result.data[2][0] += data[0][0] * other.data[2][0];
	result.data[2][0] += data[1][0] * other.data[2][1];
	result.data[2][0] += data[2][0] * other.data[2][2];
	result.data[2][0] += data[3][0] * other.data[2][3];
	result.data[3][0] += data[0][0] * other.data[3][0];
	result.data[3][0] += data[1][0] * other.data[3][1];
	result.data[3][0] += data[2][0] * other.data[3][2];
	result.data[3][0] += data[3][0] * other.data[3][3];
	result.data[0][1] += data[0][1] * other.data[0][0];
	result.data[0][1] += data[1][1] * other.data[0][1];
	result.data[0][1] += data[2][1] * other.data[0][2];
	result.data[0][1] += data[3][1] * other.data[0][3];
	result.data[1][1] += data[0][1] * other.data[1][0];
	result.data[1][1] += data[1][1] * other.data[1][1];
	result.data[1][1] += data[2][1] * other.data[1][2];
	result.data[1][1] += data[3][1] * other.data[1][3];
	result.data[2][1] += data[0][1] * other.data[2][0];
	result.data[2][1] += data[1][1] * other.data[2][1];
	result.data[2][1] += data[2][1] * other.data[2][2];
	result.data[2][1] += data[3][1] * other.data[2][3];
	result.data[3][1] += data[0][1] * other.data[3][0];
	result.data[3][1] += data[1][1] * other.data[3][1];
	result.data[3][1] += data[2][1] * other.data[3][2];
	result.data[3][1] += data[3][1] * other.data[3][3];
	result.data[0][2] += data[0][2] * other.data[0][0];
	result.data[0][2] += data[1][2] * other.data[0][1];
	result.data[0][2] += data[2][2] * other.data[0][2];
	result.data[0][2] += data[3][2] * other.data[0][3];
	result.data[1][2] += data[0][2] * other.data[1][0];
	result.data[1][2] += data[1][2] * other.data[1][1];
	result.data[1][2] += data[2][2] * other.data[1][2];
	result.data[1][2] += data[3][2] * other.data[1][3];
	result.data[2][2] += data[0][2] * other.data[2][0];
	result.data[2][2] += data[1][2] * other.data[2][1];
	result.data[2][2] += data[2][2] * other.data[2][2];
	result.data[2][2] += data[3][2] * other.data[2][3];
	result.data[3][2] += data[0][2] * other.data[3][0];
	result.data[3][2] += data[1][2] * other.data[3][1];
	result.data[3][2] += data[2][2] * other.data[3][2];
	result.data[3][2] += data[3][2] * other.data[3][3];
	result.data[0][3] += data[0][3] * other.data[0][0];
	result.data[0][3] += data[1][3] * other.data[0][1];
	result.data[0][3] += data[2][3] * other.data[0][2];
	result.data[0][3] += data[3][3] * other.data[0][3];
	result.data[1][3] += data[0][3] * other.data[1][0];
	result.data[1][3] += data[1][3] * other.data[1][1];
	result.data[1][3] += data[2][3] * other.data[1][2];
	result.data[1][3] += data[3][3] * other.data[1][3];
	result.data[2][3] += data[0][3] * other.data[2][0];
	result.data[2][3] += data[1][3] * other.data[2][1];
	result.data[2][3] += data[2][3] * other.data[2][2];
	result.data[2][3] += data[3][3] * other.data[2][3];
	result.data[3][3] += data[0][3] * other.data[3][0];
	result.data[3][3] += data[1][3] * other.data[3][1];
	result.data[3][3] += data[2][3] * other.data[3][2];
	result.data[3][3] += data[3][3] * other.data[3][3];
	//For your own sanity PLEASE Trust me that it works perfectly as intended.
	return result;
}

Vector4 Matrix4::operator * (const Vector4& v) const
{
	Vector4 result;
	result[0] += data[0][0] * v[0];
	result[0] += data[1][0] * v[1];
	result[0] += data[2][0] * v[2];
	result[0] += data[3][0] * v[3];
	result[1] += data[0][1] * v[0];
	result[1] += data[1][1] * v[1];
	result[1] += data[2][1] * v[2];
	result[1] += data[3][1] * v[3];
	result[2] += data[0][2] * v[0];
	result[2] += data[1][2] * v[1];
	result[2] += data[2][2] * v[2];
	result[2] += data[3][2] * v[3];
	result[3] += data[0][3] * v[0];
	result[3] += data[1][3] * v[1];
	result[3] += data[2][3] * v[2];
	result[3] += data[3][3] * v[3];
	return result;
}
#pragma endregion

#pragma region Rotation
void Matrix4::setEuler(float pitch, float yaw, float roll)
{
	setRotateZ(roll);
	rotateY(yaw);
	rotateX(pitch);
}

void Matrix4::setRotateX(float radians)
{
	xAxis = {1, 0, 0, 0};
	yAxis = {0, cos(radians), -sin(radians), 0};
	zAxis = {0, sin(radians), cos(radians), 0};
	wAxis = {0, 0, 0, 1};
}

void Matrix4::rotateX(float radians)
{
	Matrix4 result;
	result.setRotateX(radians);
	*this = *this * result;
}
void Matrix4::setRotateY(float radians)
{
	xAxis = {cos(radians), 0, sin(radians), 0};
	yAxis = {0, 1, 0, 0};
	zAxis = {-sin(radians), 0, cos(radians), 0};
	wAxis = {0, 0, 0, 1};
}

void Matrix4::rotateY(float radians)
{
	Matrix4 result;
	result.setRotateY(radians);
	*this = *this * result;
}

void Matrix4::setRotateZ(float radians)
{
	xAxis = {cos(radians), -sin(radians), 0, 0};
	yAxis = {sin(radians), cos(radians), 0, 0};
	zAxis = {0, 0, 1, 0};
	wAxis = {0, 0, 0, 1};
}

void Matrix4::rotateZ(float radians)
{
	Matrix4 result;
	result.setRotateZ(radians);
	*this = *this * result;
}
#pragma endregion

#pragma region Scale
void Matrix4::setScaled(float x, float y, float z)
{
	xAxis = { x, 0, 0, 0 };
	yAxis = { 0, y, 0, 0 };
	zAxis = { 0, 0, z, 0 };
	wAxis = { 0, 0, 0, 1 };
}
void Matrix4::setScaled(const Vector3& v)
{
	xAxis = { v.x, 0, 0, 0 };
	yAxis = { 0, v.y, 0, 0 };
	zAxis = { 0, 0, v.z, 0 };
	wAxis = { 0, 0, 0, 1 };
}
void Matrix4::scale(float x, float y, float z)
{
	Matrix4 result;
	result.setScaled(x, y, z);
	*this = *this * result;
}
void Matrix4::scale(const Vector3& v)
{
	Matrix4 result;
	result.setScaled(v.x, v.y, v.z);

	*this = *this * result;
}
#pragma endregion


#pragma endregion

