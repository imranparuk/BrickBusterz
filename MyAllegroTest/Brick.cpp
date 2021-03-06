#include "Brick.h"

int Brick::getLocX()
{
	return locationX;
}

int Brick::getLocY()
{
	return locationY;
}

ALLEGRO_BITMAP *Brick::getBitMap()
{
	return brick;
}

int Brick::getSizeX()
{
	return sizeX;
};
int Brick::getSizeY()
{
	return sizeY;
};

int Brick::getSuperLevel()
{
	return superLevel;
}

bool Brick::isPowerUp()
{
	if (puBrick == 1)
		return true;
	return false;
}

bool Brick::isSuper()
{
	if (super == 1)
		return true;
	return false;
}



bool Brick::detectCollisionVertical(const int ball_x, const int ball_y, const int ball_dx, const int ball_dy, const int BALL_SIZE_RADIUS)
{
   int temp_dy = abs(ball_dy);

   if ((ball_dy > 0) && (ball_y + BALL_SIZE_RADIUS >= locationY) && (ball_y + BALL_SIZE_RADIUS <= locationY + temp_dy) && (ball_x + BALL_SIZE_RADIUS > locationX) && (ball_x - BALL_SIZE_RADIUS < locationX + sizeX))
   {
	   if (super)
		   superLevel--;

		return true;
   }
   else if ((ball_dy < 0) && (ball_y - BALL_SIZE_RADIUS <= locationY + sizeY) && (ball_y - BALL_SIZE_RADIUS >= locationY + sizeY - temp_dy) && (ball_x + BALL_SIZE_RADIUS > locationX) && (ball_x - BALL_SIZE_RADIUS < locationX + sizeX))
   {
	   if (super)
		   superLevel--;

		return true;
   }
   else
		return false;
};

bool Brick::detectCollisionHorizontal(const int ball_x, const int ball_y, const int ball_dx, const int ball_dy, const int BALL_SIZE_RADIUS)
{
	int temp_dx = abs(ball_dx);
	int temp_dy = abs(ball_dy);

	if ((ball_dx > 0) && (ball_x + BALL_SIZE_RADIUS >= locationX) && (ball_x + BALL_SIZE_RADIUS <= locationX + temp_dx) && (ball_y >= locationY) && (ball_y  <= locationY + sizeY))
	{
		if (super)
			superLevel--;

	   return true;
	}
	else if ((ball_dx < 0) && (ball_x - BALL_SIZE_RADIUS <= locationX + sizeX) && (ball_x + BALL_SIZE_RADIUS >= locationX + sizeX - temp_dx) && (ball_y >= locationY) && (ball_y <= locationY + sizeY))
	{
		if (super)
			superLevel--;

	   return true;
	}
	else
	   return false;
};


bool Brick::isDestroyed()
{
	return destroyed;
};

void Brick::destroy(bool result)
{
	this->destroyed = result;
}

void Brick::setSuperLevel(int level)
{
	superLevel = level;
}

