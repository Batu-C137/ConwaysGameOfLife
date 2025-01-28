/*
 * world.h
 */

#pragma once
#ifndef WORLD_H
#define WORLD_H

#include "cell.h"

using namespace std;

class GameWorld
{
private:
	int x = 0, y = 0, area = 0;
	int* tmp_pos_x;
	int* tmp_pos_y;
	Life* cell;

public:
	GameWorld(int x, int y, Life* z);
	~GameWorld(void);
	int width(void);
	int height(void);
	int draw();
	void reDraw(int eingabeFertig);
	void Rules();

};

GameWorld::GameWorld(int x, int y, Life* z)
{
	this->x = x;
	this->y = y;
	cell = z;
	area = this->x * this->y;
	tmp_pos_x = new int[area] { 0 };
	tmp_pos_y = new int[area] { 0 };
}

GameWorld::~GameWorld()
{
	delete[] tmp_pos_x, tmp_pos_y;
}

int GameWorld::width()
{
	return x;
}

int GameWorld::height()
{
	return y;
}


int GameWorld::draw()
{
	int koord_x = 21, koord_y = 21;
	int selected;
	int s = 0;

	for (;;)
	{
		do
		{
			system("cls");

			cout << "\t\tConways Game of Life\n" << endl;
			cout << "\t\tWorld area 20x20" << endl;

			for (int i = 1; i < koord_y; i++)
			{
				cout << ".";
				for (int j = 1; j < koord_x; j++)
				{
					cout << " | ";
				}
				cout << ".\n";
			}

			cout << "\n1. Custom input" << endl;
			cout << "2. Pre created" << endl;
			cout << "3. Exit" << endl;
			cout << "\nSelect: ";

			std::cin >> selected;

		} while (selected != 1 && selected != 2 && selected != 3);

		switch (selected)
		{
		case 2:
			do
			{
				system("cls");

				cout << "1.loop" << endl;
				cout << "2.diamond" << endl;
				cout << "3.blinker" << endl;
				cout << "4.glider" << endl;
				cout << "Auswahl: ";
				std::cin >> selected;

			} while (selected != 1 && selected != 2 && selected != 3 && selected != 4);

			switch (selected)
			{
			case 1:
				return 2;
			case 2:
				return 3;
			case 3:
				return 4;
			case 4:
				return 5;
			default:
				break;
			}
		case 1:
			return 1;
		case 3:
			return 0;
		default:
			break;
		}
	}
}

void GameWorld::reDraw(int input)
{
	int x = width() + 1, y = height() + 1;
	int z = 0;

	system("cls");

	cout << "\t\tConways Game of Life\n" << endl;
	cout << "\t\tWorld area 20x20" << endl;

	for (int i = 1; i < y; i++)
	{
		cout << ".";

		for (int j = 1; j < x; j++)
		{
			if (cell->CellPos(j, i))
			{
				cout << " X ";
			}
			else
			{
				cout << " | ";
			}
		}

		cout << ".\n";
	}

	if (input == 1)
	{
		Rules();
	}

}


void GameWorld::Rules()
{
	int tmp = 0;
	int nyy = 1, myy = 2, nxx = 1, mxx = 1, k = 0;
	int partner_xy = 0, tempy = 0, tempx = 0, birth = 1, count = 0;
	int world_x = width() + 1, world_y = height() + 1;
	int wall_y = 0, wall_x = 0;


	for (int i = 1; i <= area; i++)
	{
		tmp_pos_x[i] = 0;
		tmp_pos_y[i] = 0;
	}


	for (int h = 1; h < world_y + 2; h++)
	{
		for (int g = 1; g < world_x + 2; g++)
		{
			if (cell->CellPos(g, h) == 0)
			{
				count = 0;

				for (int yy = h - 1; yy <= h + 1; yy++)
				{
					for (int xx = g - 1; xx <= g + 1; xx++)
					{

						if (cell->CellPos(xx, yy))
						{
							count++;
						}
					}
				}
				if (count == 3)
				{
					tmp_pos_x[birth] = g;
					tmp_pos_y[birth] = h;
					birth++;
				}

			}


			if (cell->CellPos(g, h))
			{
				count = 0;

				for (int yyy = h - 1; yyy <= h + 1; yyy++)
				{
					for (int xxx = g - 1; xxx <= g + 1; xxx++)
					{

						if (cell->CellPos(xxx, yyy))
						{
							count++;
						}
					}
				}
				if (count == 3 || count == 4) // +1 wegen (0,0) == true
				{
					tmp_pos_x[birth] = g;
					tmp_pos_y[birth] = h;
					birth++;

				}
				else if (count < 3)
				{
					tmp_pos_x[birth] = 0;
					tmp_pos_y[birth] = 0;
					birth++;

				}
				else if (count > 4)
				{
					tmp_pos_x[birth] = 0;
					tmp_pos_y[birth] = 0;
					birth++;
				}
			}
		}
	}



	tmp = 0;

	for (int i = 1; i <= area; i++)
	{
		tmp_pos_x[tmp] = tmp_pos_x[i];
		tmp_pos_y[tmp] = tmp_pos_y[i];
		tmp++;
	}

	cell->setCells(tmp_pos_x, tmp_pos_y, 1, area);
}


#endif // !WELT_H
