#pragma once
#include <string>
#include <vector>

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
		float dot(ZergosVectors::Vector vec);
		float angle_between(ZergosVectors::Vector vec);
		ZergosVectors::Vector cross(ZergosVectors::Vector vec);
		int find_dependence_2(ZergosVectors::Vector vec);
		int find_dependence_3(ZergosVectors::Vector vec1, ZergosVectors::Vector vec2);
	};

}

