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
	std::cout << "5) Add one vector to another" << "\n";
	std::cout << "6) Subtract one vector from another" << "\n";
	std::cout << "7) Find vector magnitude" << "\n";
	std::cout << "8) Display options" << "\n";
	std::cout << "9) Exit" << "\n";
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

			if (selection == "1" || "2" || "3" || "4" || "5" || "6" || "7" || "8")
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
		case 8: display_menu(); continue;
		case 9: break;
		}
	}
}
