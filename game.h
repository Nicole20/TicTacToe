#pragma once
#include<iostream>
#include<glut.h>
#include<freeglut.h>
#include<ctime>

using namespace std;

class game
{
public:
	game();

	//0 - Player, 1 - AI
	bool player;
	int count;
	int board[2][9];

	int pick();
	int check();

	~game();
};
