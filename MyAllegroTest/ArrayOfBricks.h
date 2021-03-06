#pragma once
#include"Brick.h"

class ArrayOfBricks
{
	const int num;
	const int startX;
	const int startY;


public:
	Brick *arr[9];//max number of bricks that can fit in a screen

	ArrayOfBricks(int n, int sX, int sY,int pU = 0,bool super = false) :startX(sX), startY(sY),num(n)
	{
		int j = sX;
		for (int i = 0; i < n; i++)
		{
			arr[i] = new Brick(j,sY,pU,super);//each brick created and stored in an array
			j += arr[i]->getSizeX() + 13;
			if (!arr[i]->getBitMap())
				fprintf(stderr, "Failed to create brick!\n");
		}
		
		for (int i = n; i < 9; i++)
		{
			arr[i] = NULL;//rest of the nodes in an array store NULL
		}
	};

	int getNum()
	{
		return num;
	}

	~ArrayOfBricks()
	{

	}

};

