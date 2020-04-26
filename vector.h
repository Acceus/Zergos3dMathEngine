#pragma once
#include <string>

namespace ZergosVectors
{
	class Vector
	{
	public:
		float x;
		float y;
		float z;
		
		Vector();
		Vector(float uX, float uY, float uZ);
		void scale_3d_vector(float scalar);
		void add_3d_vector(ZergosVectors::Vector vec_to_add);
		void subtract_3d_vector(ZergosVectors::Vector vec_to_subtract);
		float find_3d_vector_magnitude();
	};

}

