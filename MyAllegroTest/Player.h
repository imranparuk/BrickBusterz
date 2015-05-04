#pragma once
#include <stdio.h>
#include"allegro5/allegro.h"
#include <iostream>

class Player
{
	const int SCREEN_W = 640;
	const int SCREEN_H = 480;

private:
	int locationX = SCREEN_W / 2.0 - sizeX / 2.0;
	int locationY = SCREEN_H - 70;

	int sizeX;
	int sizeY;

	int centre = sizeX / 2;

	ALLEGRO_BITMAP *player = NULL;
	
public:
	Player(int sX, int sY)
	{ 
		sizeX = sX; 
		sizeY = sY; 

		player = al_create_bitmap(sizeX, sizeY);//actual player made
		if (!player)
		{
			fprintf(stderr, "Failed to create player bitmap!\n");
		}
	};
	~Player();

	int getLocX();
	int getLocY();
	int getSizeX();
	int getSizeY();


};

