#include "3dvectorfilemanagement.h"
#include "menus.h"
#include <iostream>


void display_menu()
{


	std::cout << "Here is your selection of options:" << "\n";
	std::cout << "1) Create a 3d vector" << "\n";
	std::cout << "2) Show 3d Vectors" << "\n";
	std::cout << "3) Scale 3d Vector" << "\n";
	std::cout << "4) Delete a 3d Vector" << "\n";
	std::cout << "5) Add one 3d vector to another" << "\n";
	std::cout << "6) Subtract one 3d vector from another" << "\n";
	std::cout << "7) Find vector magnitude" << "\n";
	std::cout << "8) Find dot product between two 3d vectors" << "\n";
	std::cout << "9) Find the angle between two 3d vectors" << "\n";
	std::cout << "10) Find the cross product between two 3d vectors" << "\n";
	std::cout << "11) Find out if vectors are linearly independent" << "\n";
	std::cout << "12) Display options" << "\n";
	std::cout << "13) Exit" << "\n";
}

void vector_operations_3d()
{
	display_menu();
	
	while (true)
	{
		std::string selection;

		while (true)
		{
			
			std::cout << "Enter option number here---> ";
			std::cin >> selection;

			if (selection == "1" || "2" || "3" || "4" || "5" || "6" || "7" || "8" || "9" || "10" || "11" || "12" || "13")
			{
				break;
			}
			std::cout << "---Please enter a valid option number---" << "\n\n";
		}

		switch (stoi(selection))
		{
		case 1: create_3d_vector(); continue;
		case 2: show_3d_vectors(); continue;
		case 3: scale_3d_vector(); continue;
		case 4: remove_3d_vector(); continue;
		case 5: add_3d_vectors(); continue;
		case 6: subtract_3d_vectors(); continue;
		case 7: find_3d_vector_magnitude(); continue;
		case 8: find_dot_product(); continue;
		case 9: find_angle(); continue;
		case 10: find_cross_product(); continue;
		case 11: 
			int option; 
			std::cout << "Are you wanting to check the dependence between 2 or 3 vectors?: ";
			std::cin >> option;
			std::cout << "\n";
			if (option != 2 && option != 3)
			{
				std::cout << "---You didnt enter 2 or 3";
				continue;
			}
			if (option == 2)
			{
				find_linear_dependence_2_vectors();
			}
			if (option == 3)
			{
				find_linear_dependence_3_vectors();
			}
			continue;
		case 12: display_menu(); continue;
		case 13: break;
		}
	}
}
