/*
 *
 * Instructions to students.
 * Use this file as the header to complete your matrix2, matrix3 and matrix4 classes.
 * You will have to fill out the data members for each class in this file, and then provide the function definitions in a separate cpp file.
 *
 */

#pragma once

#ifndef __MATRIX_HEADER
#define __MATRIX_HEADER

#include <iostream>
#include "vector.h"

 /*
  * MATRIX 2
  */
class Matrix2 
{
public:
	union
	{
		struct
		{
			Vector2 xAxis;
			Vector2 yAxis;
		};
		Vector2 axis[2];
		float data[2][2];
	};

	Matrix2();
	Matrix2(float _00, float _01, float _10, float _11);
	Matrix2(const Matrix2& other);

	Matrix2& operator = (const Matrix2& other);

	Vector2& operator[] (int index);

	const Vector2& operator[] (int index) const;

	void setIdentity();

	Matrix2 transposed() const;

	Matrix2 operator * (const Matrix2& other) const;

	Vector2 operator * (const Vector2& v) const;

	void setRotate(float radians);

	void rotate(float radians);

	void setScaled(float x, float y);
	void setScaled(const Vector2& v);

	void scale(float x, float y);
	void scale(const Vector2& v);
	// Convenience function declaration, provide implementation in the cpp file.
	friend std::ostream& operator<< (std::ostream& os, const Matrix2& m);
};



// END MATRIX2


/*
  * MATRIX 3
  */
class Matrix3 {
public:
	union 
	{
		struct 
		{
			Vector3 xAxis;
			Vector3 yAxis;
			Vector3 zAxis;
		};
		Vector3 axis[3];
		float data[3][3];
		Vector3 translation;
	};

	Matrix3();
	Matrix3(float _00, float _01, float _02,
			float _10, float _11, float _12,
			float _20, float _21, float _22);
	Matrix3(const Matrix3& other);

	Matrix3& operator = (const Matrix3& other);

	Vector3& operator[] (int index);

	const Vector3& operator[] (int index) const;

	void setIdentity();

	Matrix3 transposed() const;

	void setTranslate(float x, float y);
	void setTranslate(const Vector2& other);

	void translate(float x, float y);
	void translate(const Vector2& other);

	void setEuler(float pitch, float yaw, float roll);

	void setRotateX(float radians);
	void setRotateY(float radians);
	void setRotateZ(float radians);

	void rotateX(float radians);
	void rotateY(float radians);
	void rotateZ(float radians);

	void setScaled(float x, float y,float z);
	void setScaled(const Vector3& v);

	void scale(float x, float y,float z);
	void scale(const Vector3& v);

	Matrix3 operator * (const Matrix3& other) const;

	Vector3 operator * (const Vector3& v) const;

	// Convenience function declaration, provide implementation in the cpp file.
	friend std::ostream& operator<<(std::ostream& os,const Matrix3& m);
};



// END MATRIX3


/*
 * MATRIX 4
 */
class Matrix4 {
public:
	union
	{
		struct
		{
			Vector4 xAxis;
			Vector4 yAxis;
			Vector4 zAxis;
			Vector4 wAxis;
		};
		Vector4 axis[4];
		float data[4][4];
		Vector4 translation;
	};

	// Constructors
	Matrix4();
	Matrix4(const Matrix4& other);
	Matrix4(float _00, float _01, float _02, float _03,
		float _10, float _11, float _12, float _13,
		float _20, float _21, float _22, float _23,
		float _30, float _31, float _32, float _33);

	// Assignment
	Matrix4& operator = (const Matrix4& other);

	// Indexing operators to retrieve columns
	Vector4& operator[] (int index);

	// Indexing operators to retrieve columns
	const Vector4& operator[] (int index) const;

	void setIdentity();

	// Returns transpose of this matrix
	Matrix4 transposed() const;

	// Set the translation component
	void setTranslate(float x, float y, float z);
	void setTranslate(const Vector3& other);

	// Add to the translation component
	void translate(float x, float y, float z);
	void translate(const Vector3& other);

	// Set rotation using Euler representation
	void setEuler(float pitch, float yaw, float roll);

	// Set the rotation around X,Y and Z
	void setRotateX(float radians);
	void setRotateY(float radians);
	void setRotateZ(float radians);

	// Add to the rotation
	void rotateX(float radians);
	void rotateY(float radians);
	void rotateZ(float radians);

	// Set the scaled components
	void setScaled(float x, float y, float z);
	void setScaled(const Vector3& v);

	// Scale the scale components
	void scale(float x, float y, float z);
	void scale(const Vector3& v);

	// Returns this matrix multiplied by 'other'
	Matrix4 operator * (const Matrix4& other) const;

	// Multiplies Vector4 v by this matrix and returns the result
	Vector4 operator * (const Vector4& v) const;

	// Convenience function declaration, provide implementation in the cpp file.
	friend std::ostream& operator<< (std::ostream& os,const Matrix4& m);
};





//END MATRIX4

#endif