
#include "vector.h"
#include <cmath>
#include <array>
#include <iostream>
#include <iomanip>

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

 //finds magnitude of vector
 float ZergosVectors::Vector::find_3d_vector_magnitude()
 {
	 return sqrt(x * x + y * y + z * z);
 }

 //finds dot product between vectors
 float ZergosVectors::Vector::dot(ZergosVectors::Vector vec)
 {
	 return x * vec.x + y * vec.y + z * vec.z;
 }

 //finds the angle between vectors
 float ZergosVectors::Vector::angle_between(ZergosVectors::Vector vec)
 {
     float dot_product = x * vec.x + y * vec.y + z * vec.z;
     float magnitude_a = sqrt(x * x + y * y + z * z);
     float magnitude_b = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
     float magnitude_ab = magnitude_a * magnitude_b;
     float value = acos(dot_product / magnitude_ab);
     return value;
 }

 //finds the cross product between vectors
 ZergosVectors::Vector ZergosVectors::Vector::cross(ZergosVectors::Vector vec)
 {
     ZergosVectors::Vector vector;
     vector.x = y * vec.z - z * vec.y;
     vector.y = z * vec.x - x * vec.z;
     vector.z = x * vec.y - y * vec.x;

     return vector;
 }

 //find out if 2 3d vectors are linearly dependent or independent
 int ZergosVectors::Vector::find_dependence_2(ZergosVectors::Vector vec)
 {
     int is_dependent = 0;
      
     if (vec.x && vec.y && vec.z && x && y && z > 0)
     {
         float ratio = vec.x / x;
         x *= ratio;
         y *= ratio;
         z *= ratio;

         vec.x -= x;
         vec.y -= y;
         vec.z -= z;
     }

     if (vec.y && vec.z && y && z > 0 && vec.x == 0 && x == 0)
     {
         float ratio = vec.y / y;
         y *= ratio;
         z *= ratio;

         vec.y -= y;
         vec.z -= z;
     }

     if (vec.z && z > 0 && vec.x == 0 && x == 0 && vec.y == 0 && y ==0)
     {
         float ratio = vec.z / z;
         z *= ratio;

         vec.z -= z;
     }

     if ((vec.z == 0 && vec.x == 0 && vec.y == 0) || (z == 0 && y == 0 && x == 0))
     {
         is_dependent = 1;
     }

     return is_dependent;
 }

 //find out if 3 3d vectors are linearly dependent or independent
 int ZergosVectors::Vector::find_dependence_3(ZergosVectors::Vector vec_2, ZergosVectors::Vector vec_3)
 {
     int is_dependent{ 0 };
     int is_all_zeroes { 0 };
     size_t nonzero_coordinate { 0 };
     std::array<float, 3> vec1{x, y, z};
     std::array<float, 3> vec2{vec_2.x, vec_2.y, vec_2.z};
     std::array<float, 3> vec3{vec_3.x, vec_3.y, vec_3.z};
     float ratio;

     //find nonzero vector coordinate
     for (size_t i = 0; i < vec1.size(); ++i)
     {
         if (vec1[i] > 0)
         {
             nonzero_coordinate = i;
             is_all_zeroes = 1;
             break;
         }
     }

     
     if (is_all_zeroes == 1)
     {
         //set row 0 to contain the found nonzero float
         float temp = vec1[0];
         vec1[0] = vec1[nonzero_coordinate];
         vec1[nonzero_coordinate] = temp;

         temp = vec2[0];
         vec2[0] = vec2[nonzero_coordinate];
         vec2[nonzero_coordinate] = temp;

         temp = vec3[0];
         vec3[0] = vec3[nonzero_coordinate];
         vec3[nonzero_coordinate] = temp;
         
         for (size_t i = 1; i < vec1.size(); ++i)
         {
             if (vec1[i] > 0)
             {
                 nonzero_coordinate = i;
                 is_all_zeroes = 1;
                 break;
             }
             is_all_zeroes = 0;
         }
     
         if (is_all_zeroes == 1)
         {
             temp = vec1[1];
             vec1[1] = vec1[nonzero_coordinate];
             vec1[nonzero_coordinate] = temp;

             temp = vec2[1];
             vec2[1] = vec2[nonzero_coordinate];
             vec2[nonzero_coordinate] = temp;

             temp = vec3[1];
             vec3[1] = vec3[nonzero_coordinate];
             vec3[nonzero_coordinate] = temp;

             ratio = vec1[0] / vec1[1];
             vec1[1] *= ratio;
             vec2[1] *= ratio;
             vec3[1] *= ratio;

             vec1[1] -= vec1[0];
             vec2[1] -= vec2[0];
             vec3[1] -= vec3[0];

             if (vec1[2] != 0)
             {
                 ratio = vec1[0] / vec1[2];
                 vec1[2] *= ratio;
                 vec2[2] *= ratio;
                 vec3[2] *= ratio;

                 vec1[2] -= vec1[0];
                 vec2[2] -= vec2[0];
                 vec3[2] -= vec3[0];
             }
         }
         
         for (size_t i = 1; i < vec2.size(); ++i)
         {
             if (vec2[i] > 0)
             {
                 nonzero_coordinate = i;
                 is_all_zeroes = 1;
                 break;
             }
             is_all_zeroes = 0;
         }

         if (is_all_zeroes == 1)
         {
             temp = vec2[1];
             vec2[1] = vec2[nonzero_coordinate];
             vec2[nonzero_coordinate] = temp;

             temp = vec3[1];
             vec3[1] = vec3[nonzero_coordinate];
             vec3[nonzero_coordinate] = temp;

             if (vec2[2] != 0)
             {
                 float ratio = vec2[1] / vec2[2];
                 vec2[2] *= ratio;
                 vec3[2] *= ratio;

                 vec2[2] -= vec2[1];
                 vec3[2] -= vec3[1];
             }
         }

         if (is_all_zeroes == 0 && vec3[2] != 0)
         {

             ratio = vec3[1] / vec3[2];
             vec3[2] *= ratio;

             vec3[2] -= vec3[1];
         }

     }

     if (vec1[2] == 0 && vec2[2] == 0 && vec3[2] == 0)
     {
         is_dependent = 1;
     }

     if (vec1[0] == 0 && vec1[1] == 0 && vec1[2] == 0)
     {
         is_dependent = 1;
     }

     if (vec2[0] == 0 && vec2[1] == 0 && vec2[2] == 0)
     {
         is_dependent = 1;
     }

     if (vec3[0] == 0 && vec3[1] == 0 && vec3[2] == 0)
     {
         is_dependent = 1;
     }
     return is_dependent;
 }

