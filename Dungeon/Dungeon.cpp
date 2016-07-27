#include<iostream>
#include<string>
#include "Player.h"
#include <ctime>
/*
const int WIDTH = 10; //Width of the grid
const int HEIGHT = 10; //Height of the grid

void createGrid(std::string [][WIDTH]);
void printGrid(std::string[][WIDTH]);
void movement(Player &, char);
void updateGrid(std::string[][WIDTH], Player&, Player []);
void enemyMove(Player[]);

int main()
{
	srand(time(NULL));

	//Grid
	std::string grid[HEIGHT][WIDTH];

	//Player
	Player p1;
	Player enemy[2];
	p1.xCoord = 5;
	p1.yCoord = 3;

	//Initialize the enemy
	for (int i = 0; i < 2; i++)
	{
		enemy[i].xCoord = i + 1;
		enemy[i].yCoord = i + 2;
		enemy[i].mark = 'E';
	}

	//Create the grid and placye the player
	createGrid(grid);
	grid[p1.xCoord][p1.yCoord] = p1.mark;

	
	//Input for movement;
	char input = 'w';

	while (true)
	{
		printGrid(grid);
		std::cout << "Enter the direction you want to move (WASD): ";
		std::cin >> input;
		movement(p1, input);
		enemyMove(enemy);
		updateGrid(grid, p1, enemy);
		system("CLS");
		
	}
		
	return 0;
}

//Create an empty grid
void createGrid(std::string grid[][WIDTH])
{
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++)
			grid[i][j] = "*";
}


//Print the grid
void printGrid(std::string grid[][WIDTH])
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			std::cout << grid[i][j] << " ";
		std::cout << std::endl;
	}
}

//Move the player based on the input
void movement(Player &p1, char move)
{
	switch (move)
	{
	case 'w':
		if(p1.xCoord != 0)
			p1.xCoord -= 1;
		break;
	case 'a':
		if(p1.yCoord != 0)
			p1.yCoord -= 1;
		break;
	case 's':
		if(p1.xCoord != (WIDTH-1))
			p1.xCoord += 1;
		break;
	case 'd':
		if(p1.yCoord != (HEIGHT-1))
			p1.yCoord += 1;
		break;
	}
}

//update grid with new positions of the enemy and player
void updateGrid(std::string grid[][WIDTH], Player &p1, Player enemy[])
{
	createGrid(grid);
	grid[p1.xCoord][p1.yCoord] = p1.mark;
	grid[enemy[0].xCoord][enemy[0].yCoord] = enemy[0].mark;
	grid[enemy[1].xCoord][enemy[1].yCoord] = enemy[1].mark;
}

//Move enemy around grid. No collision detection
void enemyMove(Player enemy[])
{
	char input = 'w';
	int max = 5;
	int min = 0;
	int randomDirection = 0;
	
	for (int i = 0; i < 2; i++)
	{
		randomDirection = (rand() % (max - min)) + min;

		switch (randomDirection)
		{
		case 1:
			input = 'w';
			break;
		case 2:
			input = 'a';
			break;
		case 3:
			input = 's';
			break;
		case 4:
			input = 'd';
			break;
		}

		movement(enemy[i], input);
	}
}

*/