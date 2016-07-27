#include  <iostream>
#include <string>
#include "Player.h"
#include <fstream>
#include <vector>


const int WIDTH = 20;
const int HEIGHT = 20;

void newMaze(int[][WIDTH]);
void printMaze(int [][WIDTH], Player &, std::vector<Player>&);
void displayTile(int mazeIndex);
void movement(Player &p1, char move, int[][WIDTH]);
void getFromFile(int[][WIDTH]);

int main()
{
	Player player = Player(18,16);
	std::vector<Player> enemy;
	int maze[HEIGHT][WIDTH];
	getFromFile(maze);
	char input = ' ';

	enemy.push_back(Player(2, 12));
	//Main Game Loop
	while (true)
	{
		printMaze(maze, player, enemy);
		std::cout << "Please enter where you want to move WASD: ";
		std::cin >> input;
		movement(player, input, maze);
		system("CLS");
	}


	return 0;
}


//Print the maze
void printMaze(int maze[][WIDTH], Player &p1, std::vector<Player> &enemy)
{
	for (int row = 0; row < HEIGHT; row++)
	{
		for (int column = 0; column < WIDTH; column++)
		{
			if (row == p1.xCoord && column == p1.yCoord)
				std::cout << "P"; //Display the player
			else if (enemy.at(0).xCoord == row && enemy.at(0).yCoord == column)
				std::cout << "E";//Display the enemy
			else
				displayTile(maze[row][column]);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

//Display an individual tile 
void displayTile(int mazeIndex)
{
	switch (mazeIndex)
	{
		case 0:
			std::cout << '*';
			break;
		case 1:
			std::cout << ' ';
			break;
		case 2:
			std::cout << 'E';
			break;
	}
}


//Create a temp version of the maze
//Return a copy of the maze by reference
void newMaze(int maze[][WIDTH])
{
	int tempMaze[HEIGHT][WIDTH] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	for (int row = 0; row < HEIGHT; row++)
	{
		for (int column = 0; column < WIDTH; column++)
		{
			maze[row][column] = tempMaze[row][column];
		}
	}
}

//Move the player based on the input
void movement(Player &p1, char move, int maze[][WIDTH])
{
	switch (move)
	{
	case 'w':
		if (p1.xCoord != 0 && (maze[p1.xCoord-1][p1.yCoord] != 0))
			p1.xCoord -= 1;
		break;
	case 'a':
		if (p1.yCoord != 0 && (maze[p1.xCoord][p1.yCoord-1] != 0))
			p1.yCoord -= 1;
		break;
	case 's':
		if ((p1.xCoord != (WIDTH - 1)) && (maze[p1.xCoord+1][p1.yCoord] != 0))
			p1.xCoord += 1;
		break;
	case 'd':
		if ((p1.yCoord != (HEIGHT - 1)) && (maze[p1.xCoord][p1.yCoord+1] != 0))
			p1.yCoord += 1;
		break;
	}
}

//Read a Map from a file and store it locally.
void getFromFile(int maze[][WIDTH])
{
	std::ifstream myFile("map.txt");  //open the file map.txt
	if (myFile.is_open())
	{
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
				myFile >> maze[i][j];
		}
	}

	myFile.close();
}