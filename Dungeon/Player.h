#pragma once
class Player
{
public:

	//Constructors
	Player();
	Player(int, int);
	Player(int, int, int, int);
	~Player();

	//Variables
	int xCoord;
	int yCoord;
	char mark;

	//Mutators
	int getHealth();
	void setHealth(int);

	int getAttack();
	void setAttack(int);

private:
	int health;
	int attack;

	friend bool operator ==(const Player &p1, const Player &p2);
};

