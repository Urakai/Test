#include "Player.h"


//Default constructor
Player::Player()
{
	xCoord = 0;
	yCoord = 0;
	mark = 'P';
	health = 25;
	attack = 3;
}

//Construcctor: Set location
Player::Player(int x, int y)
{
	xCoord = x;
	yCoord = y;
}

//Constructor: Set location, health, attack
Player::Player(int x, int y, int hp, int atk)
{
	xCoord = x;
	yCoord = y;
	health = hp;
	attack = atk;
}
//Default decnstrucctor
Player::~Player()
{
}

//Set Attack
void Player::setAttack(int atk)
{
	attack = atk;
}

//Get Attack
int Player::getAttack()
{
	return attack;
}

//Set HP
void Player::setHealth(int hp)
{
	health = hp;
}

//Get HP
int Player::getHealth()
{
	return health;
}

bool operator ==(const Player &p1, const Player &p2)
{
	if (p1.xCoord == p2.xCoord && p1.yCoord == p2.yCoord)
		return true;
	else
		return false;
}