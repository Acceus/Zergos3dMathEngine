#include "3dvectorfilemanagement.h"
#include "vector.h"
#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include <vector>

std::vector<std::string> file_vector;
std::string uX;
std::string uY;
std::string uZ;
std::string uXuYuZ;

//splits text file line into 3 strings for each coordinate of vector
void split_file_vector(std::string vector_name)
{
	std::vector<std::string> copied_lines;
	int found_vector_name = 0;
	int found_vector = 0;

	uX.clear();
	uY.clear();
	uZ.clear();
	
	//open text file for reading
	std::fstream file;
	file.open("3dvectors.txt", std::fstream::in);

	//loop through text file to discover vector
	for (std::string line; std::getline(file, line);)
	{
		copied_lines.push_back(line);
		//if name is discovered set found_vector_name to 1 in order to have loop move one more line
		if (line == vector_name + ":")
		{
			found_vector_name = 1;
			std::cout << "\nFound vector: " << vector_name << "\n";
			continue;
		}

		//compute scaled vector and return it

		if (found_vector_name == 1 && found_vector == 0)
		{

			int change_coordinate = 0;
			found_vector = 1;
			//loop through line and place floats into string vector and locate floats by noticing space between them
			for (int i = 0; i <= line.size(); ++i)
			{
				if (line[i] == ' ')
				{
					++change_coordinate;
					continue;
				}

				if (line[i] != ' ' && change_coordinate == 0)
				{
					uX.push_back(line[i]);
					continue;
				}

				if (line[i] != ' ' && change_coordinate == 1)
				{
					uY.push_back(line[i]);
					continue;
				}

				if (line[i] != ' ' && change_coordinate == 2)
				{
					uZ.push_back(line[i]);
					continue;

				}

			}

		}

	}
	file.close();
}

//returns vector representation of file
void create_file_vector()
{
	file_vector.clear();
	std::ifstream file("3dvectors.txt");
	std::string line;

	while (std::getline(file, line))
	{
		file_vector.push_back(line);
	}
	file.close();
}

//replaces vector in text file
void replace_3d_vector(std::string vector_to_replace, std::string new_vector)
{
	create_file_vector();
	for (int i = 0; i < file_vector.size(); ++i)
	{
		if (file_vector.at(i) == vector_to_replace)
		{
			file_vector.at(i+1) = new_vector;
			break;
		}
	}

	std::fstream file;
	file.open("3dvectors.txt", std::ios_base::out);
	file.close();
	file.open("3dvectors.txt", std::ios_base::app);

	for (int j = 0; j < file_vector.size(); ++j)
	{
		file << file_vector[j] << "\n";
	}
	
	file.close();

}

//checks a string to see if it contains a float or an integer, if it contains an int it adds .0 to the string
std::string check_int_or_float_and_convert(std::string value)
{
	
	if (value.find('.') == std::string::npos)
	{
		value = value + ".0";
		return value;
	}
	else
	{
		if (value.back() == '.')
		{
			value = value + '0';
		}
		return value;
	}
}

//checks if string contains characters other than one .
bool is_Number(std::string value)
{
	int dot_count = 0;
	bool contains_Number = true;
	bool has_character = 0;
	int dot_at_end = 0;
	
	for (int i = 0; i < value.size(); ++i)
	{
		if (value[i] == '.')
		{
			++dot_count;
		}

		if (value[i] != '1' || value[i] != '2' || value[i] != '3' || value[i] != '4' || value[i] != '5' || value[i] != '6' || value[i] != '7' || value[i] != '8' || value[i] != '9')
		{
			if (value[i] == '1' || value[i] == '2' || value[i] == '3' || value[i] == '4' || value[i] == '5' || value[i] == '6' || value[i] == '7' || value[i] == '8' || value[i] == '9')
			{
				continue;
			}
			has_character = 1;
		}
	}

	if ((dot_count > 1 || dot_count == 0) && has_character == 1)
	{
		contains_Number = false;
	}

	return contains_Number;
}

//creates a 3d vector and stores in text file
void create_3d_vector()
{
	//declare variables
	std::string uX, uY, uZ;
	std::string vector_name;
	int stop = 0;
	int counter = 0;

	create_file_vector();

	//ask for vector name
	while (true)
	{
		std::cout << "Enter name of vector: ";
		std::cin >> vector_name;

		for (int i = 0; i < file_vector.size(); ++i)
		{
			if (file_vector[i] == vector_name + ":")
			{
				counter = 1;
			}
		}

		if (counter == 1)
		{
			std::cout << "---There is already a vector with this name---" << "\n\n";
		}
		else
		{
			break;
		}
	}
	
	//open file vectors.txt
	std::ofstream file;
	file.open("3dvectors.txt", std::ios_base::app);

	//write name of vector to file
	file << vector_name << ":" << "\n";

	//retrieve coordinate information for vector
	while (stop == 0)
	{
		std::cout << "Please enter x coordinate of vector: ";
		std::cin >> uX;
		if (is_Number(uX) == false)
		{
			continue;
		}
		if (is_Number(uX) == true)
		{
			++stop;
		}
	}
	while (stop == 1)
	{
		std::cout << "Please enter y coordinate of vector: ";
		std::cin >> uY;

		if (is_Number(uY) == false)
		{
			continue;
		}
		if (is_Number(uY) == true)
		{
			++stop;
		}
	}
	while (stop == 2)
	{
		std::cout << "Please enter z coordinate of vector: ";
		std::cin >> uZ;

		if (is_Number(uZ) == false)
		{
			continue;
		}
		if (is_Number(uZ) == true)
		{
			++stop;
		}
	}

	//append coordinate values to vectors.txt
	file << check_int_or_float_and_convert(uX) << " " << check_int_or_float_and_convert(uY) << " " << check_int_or_float_and_convert(uZ) << "\n";
	
	file.close();
}

//shows 3d vectors stored in text file
void show_3d_vectors()
{
	//declare variables
	int counter = 1;
	int vector_number = 1;
	
	
	//create ifstream to read file
	std::ifstream file;
	file.open("3dvectors.txt", std::fstream::in);
	
	//loop through file lines and organize data
	for (std::string line; std::getline(file, line); ++counter)
	{
		create_file_vector();
		int x_y_z = 0;
		int x_y_z_written = 0;
		int write_value = 0;

		if (counter % 2 != 0)
		{
			std::cout << "[" << vector_number << "]" << " ";
			std::cout << line << "\n";
			++vector_number;
		}
		
		if (counter % 2 == 0)
		{
			
			//loop through line string, capture required values and print them out to console
			for (int i = 0; i < line.size(); ++i)
			{
				if (line[i] != ' ' && x_y_z_written == 0 && write_value == 0)
				{
					std::cout << "x: ";
					x_y_z_written = 1;
				}
				if (line[i] != ' ' && x_y_z_written == 1 && write_value == 1)
				{
					std::cout << "y: ";
					x_y_z_written = 2;
				}
				if (line[i] != ' ' && x_y_z_written == 2 && write_value == 2)
				{
					std::cout << "z: ";
					x_y_z_written = 3;
				}
				std::cout << line[i];
				if (line[i] == ' ')
				{
					std::cout << "\n";
					++write_value;
				}
				
			}
			
			
			std::cout << "\n\n";
		}
	}
	
	file.close();
}

//scales a stored vector and updates text file to reflect changed vector
void scale_3d_vector()
{
	
	//declared variables
	std::string vector_name;
	float scalar_value;
	std::string uXuYuZ;
	int counter = 0;
	int counter2 = 0;
	
	create_file_vector();
	
	//ask for vector name and what to scale vector by
	while (counter == 0) 
	{
		std::cout << "Please enter the name of the vector you wish to scale: ";
		std::cin >> vector_name;

		for (int i = 0; i < file_vector.size(); ++i)
		{
			if (file_vector[i] == vector_name + ":")
			{
				counter = 1;
				break;
			}
		}

		if (counter == 0)
		{
			std::cout << "\n---You did not enter a valid name of a stored vector---\n\n";
		}
	}
	std::cout << "\n";
	
	while (counter2 == 0)
	{
		std::cout << "Please enter the value you wish to scale your vector with: ";
		std::cin >> scalar_value;

		if (is_Number(std::to_string(scalar_value)) == 1)
		{
			counter2 = 1;
		}
		
	}
	
	//get strings for vector coordinates
	split_file_vector(vector_name);

	//Create vector object and scale the object
	
	ZergosVectors::Vector vec(stof(uX), stof(uY), stof(uZ));
	vec.scale_3d_vector(scalar_value);
	
	uXuYuZ.clear();
	
	uX = check_int_or_float_and_convert(std::to_string(vec.x));
	uY = check_int_or_float_and_convert(std::to_string(vec.y));
	uZ = check_int_or_float_and_convert(std::to_string(vec.z));

	uXuYuZ = uX + " " + uY + " " + uZ;

	replace_3d_vector(vector_name + ":", uXuYuZ);

	std::cout << "Your new scaled vector values are: " << "\n";
	std::cout << "x: " << vec.x;
	std::cout << "y: " << vec.y;
	std::cout << "z: " << vec.z;
	std::cout << "\n\n";

}

//removes 3d vector from text file
void remove_3d_vector()
{
	create_file_vector();
	int counter = 0;
	std::string vector_name;
	int vector_position;
	
	while (counter == 0)
	{
		std::cout << "What Vector would you like to remove: ";
		std::cin >> vector_name;

		for (int i = 0; i < file_vector.size(); ++i)
		{
			if (file_vector[i] == vector_name + ":")
			{
				counter = 1;
				vector_position = i;
			}
		}

		if (counter == 0)
		{
			std::cout << "\n---You did not enter a valid name of a stored vector---\n\n";
		}
	}
	
	file_vector.erase(file_vector.begin() + vector_position);
	file_vector.erase(file_vector.begin() + vector_position);
	std::fstream file;
	
	file.open("3dvectors.txt", std::ios_base::out);
	file.close();
	file.open("3dvectors.txt", std::ios_base::app);

	for (int j = 0; j < file_vector.size(); ++j)
	{
		file << file_vector[j] << "\n";
	}

	file.close();
}

//adds two 3d vectors together producing a new vector
void add_3d_vectors()
{
	std::string vector1;
	std::string vector2;
	int found_vector1 = 0;
	int found_vector2 = 0;
	int found_vectors = 0;
	std::string uXuYuZ;

	create_file_vector();
	
	//get vector names and position in text file
	while (found_vectors == 0)
	{
		std::cout << "Please enter the name of the vector you want to add to: ";
		std::cin >> vector1;
		std::cout << "Please enter the name of the vector you wish to add to " << vector1 << ": ";
		std::cin >> vector2;

		for (int i = 0; i < file_vector.size(); ++i)
		{
			if (file_vector[i] == vector1 + ":")
			{
				found_vector1 = 1;
			}
			if (file_vector[i] == vector2 + ":")
			{
				found_vector2 = 1;
			}
			if (found_vector1 == 1 && found_vector2 == 1)
			{
				found_vectors = 1;
			}
		}

		if (found_vectors == 0)
		{
			std::cout << "Please enter valid vector names" << "\n";
		}
	}
	
	//get string representations of vector coordinates and create vector objects
	split_file_vector(vector1);
	ZergosVectors::Vector vec1(stof(uX), stof(uY), stof(uZ));
	split_file_vector(vector2);
	ZergosVectors::Vector vec2(stof(uX), stof(uY), stof(uZ));

	vec1.add_3d_vector(vec2);

	uXuYuZ.clear();

	uX = check_int_or_float_and_convert(std::to_string(vec1.x));
	uY = check_int_or_float_and_convert(std::to_string(vec1.y));
	uZ = check_int_or_float_and_convert(std::to_string(vec1.z));

	uXuYuZ = uX + " " + uY + " " + uZ;

	replace_3d_vector(vector1 + ":", uXuYuZ);

	std::cout << "New values for " << vector1 << "\n";
	std::cout << "x: " << vec1.x << "\n";
	std::cout << "y: " << vec1.y << "\n";
	std::cout << "z: " << vec1.z;
	std::cout << "\n\n";
}

void subtract_3d_vectors()
{
	std::string vector1;
	std::string vector2;
	int found_vector1 = 0;
	int found_vector2 = 0;
	int found_vectors = 0;
	std::string uXuYuZ;

	create_file_vector();

	//get vector names and position in text file
	while (found_vectors == 0)
	{
		std::cout << "Please enter the name of the vector you want to subtract from: ";
		std::cin >> vector1;
		std::cout << "Please enter the name of the vector you wish to " << vector1 << ": ";
		std::cin >> vector2;

		for (int i = 0; i < file_vector.size(); ++i)
		{
			if (file_vector[i] == vector1 + ":")
			{
				found_vector1 = 1;
			}
			if (file_vector[i] == vector2 + ":")
			{
				found_vector2 = 1;
			}
			if (found_vector1 == 1 && found_vector2 == 1)
			{
				found_vectors = 1;
			}
		}

		if (found_vectors == 0)
		{
			std::cout << "Please enter valid vector names" << "\n";
		}
	}

	//get string representations of vector coordinates and create vector objects
	split_file_vector(vector1);
	ZergosVectors::Vector vec1(stof(uX), stof(uY), stof(uZ));
	split_file_vector(vector2);
	ZergosVectors::Vector vec2(stof(uX), stof(uY), stof(uZ));

	vec1.subtract_3d_vector(vec2);

	uXuYuZ.clear();

	uX = check_int_or_float_and_convert(std::to_string(vec1.x));
	uY = check_int_or_float_and_convert(std::to_string(vec1.y));
	uZ = check_int_or_float_and_convert(std::to_string(vec1.z));

	uXuYuZ = uX + " " + uY + " " + uZ;

	replace_3d_vector(vector1 + ":", uXuYuZ);

	std::cout << "New values for " << vector1 << "\n";
	std::cout << "x: " << vec1.x << "\n";
	std::cout << "y: " << vec1.y << "\n";
	std::cout << "z: " << vec1.z;
	std::cout << "\n\n";
}

void find_3d_vector_magnitude()
{
	std::string vector1;
	std::string vector2;
	int found_vector1 = 0;
	std::string uXuYuZ;

	create_file_vector();

	//get vector names and position in text file
	while (found_vector1 == 0)
	{
		std::cout << "Please enter the name of the vector you wish to normalize: ";
		std::cin >> vector1;
	
		for (int i = 0; i < file_vector.size(); ++i)
		{
			if (file_vector[i] == vector1 + ":")
			{
				found_vector1 = 1;
			}

		}

		if (found_vector1 == 0)
		{
			std::cout << "Please enter valid vector name" << "\n";
		}
	}

	//get string representations of vector coordinates and create vector objects
	split_file_vector(vector1);
	ZergosVectors::Vector vec1(stof(uX), stof(uY), stof(uZ));
	
	std::cout << "\n" << "The magnitude of " << vector1 << " is " << vec1.find_3d_vector_magnitude() << "\n\n";
}