/*
 * cell.h
 */

#pragma once
#ifndef CELL_H
#define CELL_H

#include"world.h"
#include<iostream>
#include <string>
#include<ctype.h>

using namespace std;

class Life
{

private:
	//int** zelle;
	int *coordinate_x; int * coordinate_y;
	int *Area_x; int *Area_y;
	int world_x, world_y, area;
	int cell[402][402] = {0}; //must be changed when adjusting the size

public:
	Life(int x, int y);
	~Life();
	int CellPos(int x, int y);
	int coord_x_return(int x);
	int coord_y_return(int y);
	void setCells(int *x, int *y, int z, int worldLenght);
	void start(int i);
};

Life::Life(int x, int y)
{
	world_x = x;
	world_y = y;
	area = x * y;
	coordinate_x = new int[area]{ 0 };
	coordinate_y = new int[area]{ 0 };
	Area_x = new int[area]{ 0 };
	Area_y = new int[area]{ 0 };
}
Life::~Life()
{
	delete[] coordinate_x, coordinate_y, Area_x, Area_y;
}


void Life::start(int i)
{
	string s;
	int koord_x, koord_y;
	int len = world_x * world_y;
	bool korrekt = true;

	do
	{
		std::cout << "Type x coordinate from cell: " << endl;
		std::cin >> koord_x;
		std::cout << "Type y coordinate from cell: " << endl;
		std::cin >> koord_y;

		if (koord_x > world_x || koord_x < 1 || koord_y > world_y || koord_y < 1)
		{
			if (!isdigit(koord_x) || !isdigit(koord_y))
			{
				cin.clear();
				cin.ignore();

				cout << "Coordinates must be integers and may only be located within the playing field!" << endl;
			}
		}
		else
		{
			Area_x[i] = koord_x;
			Area_y[i] = koord_y;

			korrekt = false;
		}

	} while (korrekt);


	setCells(Area_x, Area_y, 1, area);


}


int Life::CellPos(int x, int y)
{
	return cell[x][y];
}

int Life::coord_x_return(int x)
{
	return coordinate_x[x];
}

int Life::coord_y_return(int y)
{
	return coordinate_y[y];
}

void Life::setCells(int *x, int *y, int z, int worldLenght)
{
	int k = 0;

	for (int l = 0; l < worldLenght; l++)
	{
		for (int m = 0; m < worldLenght; m++)
		{
			cell[l][m] = 0;
		}
	}

	for (int i = 1; i < worldLenght + 1; i++)
	{
		coordinate_x[i] = x[k];
		coordinate_y[i] = y[k];
		k++;
	}
	for (int j = 1; j < worldLenght + 1; j++)
	{
		cell[coordinate_x[j]][coordinate_y[j]] = z;
	}
}


#endif // CELL_H
