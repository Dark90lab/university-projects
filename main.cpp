#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>  

using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y,fruitX,fruitY,score;
int tailX[100], tailY[100];
int nTail;
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;


void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;// centre the snake;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw()
{
	system("cls");
	system("color 0");
	for (int i = 0; i < width+1; i++)
		cout << "#"; //top wall
	cout << endl;
	for (int i = 0; i < height-2 ;i++)
	{
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == (width - 1))
				cout << "#";
			if (j == x && i == y)//head of sneak
				cout << "O";
			else if (i == fruitY && j == fruitX)//printing fruit
				cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)//printing tail
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
					
				}
				if (!print)
					cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width+1; i++)
		cout << "#"; // bottom wall
	cout << endl;
	cout << "Score: " << score << endl;
	cout << "FX: " << fruitX << " FY: " << fruitY<<endl;
	cout << "headX: " << x << " headY: " << y<<endl;
	cout << "tailX: " << tailX[2] << " tailY: " << tailY[2];
}

void Input()
{
	if (_kbhit()) //check if button is pushed
	{
		switch (_getch()) //which button is pushed
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic()
{
	for (int i = nTail-1; i >0; i--) //generating tail
	{
		tailX[i] = tailX[i - 1];
		tailY[i] = tailY[i - 1];
	}
	tailX[0] = x;//setting cordinates of head
	tailY[0] = y;
	switch (dir) //changing position of head
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	//if (x > width-1 || x < 0||y>height-1 || y<0) // checkig whether head collides with walls 
	//	gameOver=true;
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;
	for (int i = 0; i < nTail; i++) //check if head collides with tail
		if (tailX[i]==x && tailY[i]==y)
			gameOver == true;
	if (x == fruitX && y == fruitY)//generating new fruit
	{
		score++;
		fruitX = rand() % (width-2)+1;
		fruitY = rand() % (height-2);
		nTail++;
	}
	
}

int main()
{
	srand(time(NULL));
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(15);
	}

	
}