/*
 * main.cpp
 */

#include <iostream>
#include "world.h"

using namespace std;

int main(int argc, char* argv[])
{
	int gen = 1, selected = 0, eingabe = 0, i = 0;
	string finished;
	char c;

	//loop
	int option1_x[18] = { 7, 8, 6, 7, 7, 9, 9, 8, 9, 11, 11, 11, 12, 13, 13, 14, 13, 12 };
	int option1_y[18] = { 6, 6, 7, 8, 9, 10, 11, 11, 12, 8, 9, 10, 9, 11, 12, 13, 14, 14 };

	//diamond
	int option2_x[26] = { 9, 10, 7, 8, 9, 10, 11, 12, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 7, 8, 9, 10, 11, 12, 9, 10 };
	int option2_y[26] = { 6, 6, 8, 8, 8, 8, 8, 8, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 12, 12, 12, 12, 12, 12, 14, 14 };

	//blinker
	int option3_x[9] = { 3, 4, 5, 5, 5, 5, 8, 9, 10 };
	int option3_y[9] = { 3, 3, 3, 7, 8, 9, 5, 5, 5 };


	//glider
	int option4_x[5] = { 3, 4, 4, 3, 2 };
	int option4_y[5] = { 3, 4, 5, 5, 5 };

	Life* cell = new Life(20, 20);
	GameWorld* world = new GameWorld(20, 20, cell);


	selected = world->draw();

	switch (selected)
	{
	case 1:

		do
		{
			cell->start(i);
			world->reDraw(2);
			i++;

			std::cout << "Finished? (y/n): ";
			std::cin >> finished;

			if (finished == "y")
			{
				eingabe = 1;
			}

		} while (eingabe != 1);
		break;

	case 2: cell->setCells(option1_x, option1_y, 1, 18);
		break;
	case 3: cell->setCells(option2_x, option2_y, 1, 26);
		break;
	case 4: cell->setCells(option3_x, option3_y, 1, 9);
		break;
	case 5: cell->setCells(option4_x, option4_y, 1, 5);
		break;
	case 0:
		exit(-1);
	default:
		break;
	}

	world->reDraw(1);

	//std::cin.get();

	for (;;)
	{
		cout << "Press 'ENTER' for next generation\tGen = " << gen << "\nType 'e' to exit" << endl;

		if (std::cin.get() == '\n')
		{
			world->reDraw(1);
			gen++;
		}
		else if (std::cin.get(c))
		{
			if (c == 'e')
			{
				exit(-1);
			}
		}
	}

}