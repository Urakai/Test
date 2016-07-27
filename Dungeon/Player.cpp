#include "Player.h"



Player::Player()
{
	xCoord = 0;
	yCoord = 0;
	mark = 'P';
}

Player::Player(int x, int y)
{
	xCoord = x;
	yCoord = y;
}


Player::~Player()
{
}
