
#include "vector.h"

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
	 x = x + vec_to_add.x;
	 y = y + vec_to_add.y;
	 z = z + vec_to_add.z;
 }

 //subtract one vector from another
 void ZergosVectors::Vector::subtract_3d_vector(ZergosVectors::Vector vec_to_subtract)
 {
	 x = x - vec_to_subtract.x;
	 y = y - vec_to_subtract.y;
	 z = z - vec_to_subtract.z;
 }
