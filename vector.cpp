
#include "vector.h"
#include <cmath>

//initialize vector to 0.0
ZergosVectors::Vector::Vector()	
{
	ZergosVectors::Vector::x = 0.0f;
	ZergosVectors::Vector::y = 0.0f;
	ZergosVectors::Vector::z = 0.0f;
}

//initialize specific vector
ZergosVectors::Vector::Vector(float uX, float uY, float uZ)
{
	ZergosVectors::Vector::x = uX;
	ZergosVectors::Vector::y = uY;
	ZergosVectors::Vector::z = uZ;
}

//scale vector
 void ZergosVectors::Vector::scale_3d_vector(float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

 //add one vector to another
 void ZergosVectors::Vector::add_3d_vector (ZergosVectors::Vector vec_to_add)
 {
	 x += vec_to_add.x;
	 y += vec_to_add.y;
	 z += vec_to_add.z;
 }

 //subtract one vector from another
 void ZergosVectors::Vector::subtract_3d_vector(ZergosVectors::Vector vec_to_subtract)
 {
	 x -= vec_to_subtract.x;
	 y -= vec_to_subtract.y;
	 z -= vec_to_subtract.z;
 }

 float ZergosVectors::Vector::find_3d_vector_magnitude()
 {
	 return sqrt(x * x + y * y + z * z);
 }

 float ZergosVectors::Vector::dot(ZergosVectors::Vector vec)
 {
	 return x * vec.x + y * vec.y + z * vec.z;
 }

 float ZergosVectors::Vector::angle_between(ZergosVectors::Vector vec)
 {
     float dot_product = x * vec.x + y * vec.y + z * vec.z;
     float magnitude_a = sqrt(x * x + y * y + z * z);
     float magnitude_b = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
     float magnitude_ab = magnitude_a * magnitude_b;
     float value = acos(dot_product / magnitude_ab);
     return value;
 }

 ZergosVectors::Vector ZergosVectors::Vector::cross(ZergosVectors::Vector vec)
 {
     ZergosVectors::Vector vector;
     vector.x = y * vec.z - z * vec.y;
     vector.y = z * vec.x - x * vec.z;
     vector.z = x * vec.y - y * vec.x;

     return vector;
 }

