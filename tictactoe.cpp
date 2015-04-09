// tictactoe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<glut.h>
#include<freeglut.h>
#include<ctime>
#include"game.h"

using namespace std;

void initialize();
void draw();
void drawBoard();
void drawX();
void drawO();
void drawScore();
void drawCircle(float radius);
void mouse(int button, int state, int x, int y);
void Timer(int value);

void piece(int place);

int points_x = 0, points_o = 0;
char *score = { "Score = " };
char *numbers = { "0123456789" };

game match;
bool win = false;
int winPlayer;
int temp;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tic-Tac-Toe");

	initialize();

	glutDisplayFunc(draw);
	glutMouseFunc(mouse);
	glutTimerFunc(0, Timer, 0);

	glutMainLoop();

	return 0;
}

void initialize()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, 6, 0, 4);
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	drawBoard();

	if(win == false)
	{
		for (int i = 0; i < 9; i++)
		{
			if (match.board[0][i] == 1)
			{
				glPushMatrix();
				if (match.board[1][i] == 0)  //Player - X
				{
					if (i < 3)
					{
						glTranslatef(i % 3 + 3.25, 0.25, 0);
					}
					else if (i < 6)
					{
						glTranslatef(i % 3 + 3.25, 1.25, 0);
					}
					else
					{
						glTranslatef(i % 3 + 3.25, 2.25, 0);
					}
					drawX();
				}
				else  //AI - O
				{
					if (i < 3)
					{
						glTranslatef(i % 3 + 3, 0, 0);
					}
					else if (i < 6)
					{
						glTranslatef(i % 3 + 3, 1, 0);
					}
					else
					{
						glTranslatef(i % 3 + 3, 2, 0);
					}
					drawO();
				}
				glPopMatrix();
			}
		}
	}

	glutPostRedisplay();
	glFlush();
}

void drawBoard()
{
	glColor3f(0, 0, 0);

	glLineWidth(5);

	glBegin(GL_LINES);
	glVertex2f(6, 2);
	glVertex2f(3, 2);
	glVertex2f(6, 1);
	glVertex2f(3, 1);
	glVertex2f(5, 0);
	glVertex2f(5, 3);
	glVertex2f(4, 0);
	glVertex2f(4, 3);
	glEnd();

	drawScore();
}

void drawX()
{
	glColor3f(0, 0, 0);

	glBegin(GL_LINES);
	glVertex2f(0, 0.5);
	glVertex2f(0.5, 0);
	glVertex2f(0, 0);
	glVertex2f(0.5, 0.5);
	glEnd();
}

void drawO()
{
	glColor3f(0, 0, 0);

	glPushMatrix();
	glTranslatef(0.5, 0.5, 0);
	drawCircle(0.3);
	glPopMatrix();
}

void drawScore()
{
	glColor3f(0, 0, 0);
	glRasterPos2f(0.5, 3.5);

	for (int i = 0; i < 5; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, score[i]);
	}

	glPushMatrix();
	glTranslatef(0.6, 2.5, 0);
	drawX();
	glPopMatrix();

	glRasterPos2f(1.3, 2.7);

	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, score[6]);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, score[7]);

	if (points_x < 10)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[points_x]);
	}
	else
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[points_x / 10]);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[points_x % 10]);
	}

	glPushMatrix();
	glTranslatef(0.35, 1.4, 0);
	drawO();
	glPopMatrix();

	glRasterPos2f(1.3, 1.7);

	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, score[6]);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, score[7]);

	if (points_o < 10)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[points_o]);
	}
	else
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[points_o / 10]);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[points_o % 10]);
	}
}

void drawCircle(float radius)
{
	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < 360; i++)
	{
		float degInRad = i*3.14/180;
		glVertex2f(cos(degInRad)*radius, sin(degInRad)*radius);
	}

	glEnd();
}

void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			if (y > 300)
			{
				if (x > 500)
				{
					piece(2);
				}
				else if (x > 400)
				{
					piece(1);
				}
				else if (x > 300)
				{
					piece(0);
				}
			}
			else if (y > 200)
			{
				if (x > 500)
				{
					piece(5);
				}
				else if (x > 400)
				{
					piece(4);
				}
				else if (x > 300)
				{
					piece(3);
				}
			}
			else if (y > 100)
			{
				if (x > 500)
				{
					piece(8);
				}
				else if (x > 400)
				{
					piece(7);
				}
				else if (x > 300)
				{
					piece(6);
				}
			}
		}
	}
}

void Timer(int value)
{
	if (win)
	{
		if (winPlayer == 0)  //Player
		{
			points_x++;
		}
		else if (winPlayer == 1)  //AI
		{
			points_o++;
		}
		for (int i = 0; i < 9; i++)
		{
			match.board[0][i] = 0;
		}
		match.player = rand() % 2;
		win = false;
	}
	
	winPlayer = match.check();
	if (winPlayer != -1)
	{
		win = true;
	}
	else if (match.player == 1)
	{
		temp = match.pick();
		match.board[0][temp] = 1;
		match.board[1][temp] = 1;
		match.player = 0;
	}
	glutTimerFunc(100, Timer, 0);
}

void piece(int place)
{
	if (match.board[0][place] == false)
	{
		if (match.player == 0)
		{
			//draw X
			match.board[0][place] = 1;
			match.board[1][place] = 0;
			match.player = 1;
			glutPostRedisplay();
			glutTimerFunc(0, Timer, 0);
		}
	}
}
