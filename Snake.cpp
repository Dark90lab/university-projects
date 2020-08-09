#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;
bool gameOver, gameMode;
const int width = 20;
const int height = 20;
int x, y,fruitX,fruitY,score;
int tailX[100], tailY[100];
int lenTail;
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;

void Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void Setup()
{
	cout << "Chose game Mode :" << endl << "With walls - [0], Without Wals - [1]"<<endl;
	cin >> gameMode;
	gameOver = false;
	dir = STOP;
	x = width / 2;// centring the snake;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
	
}

void Draw()
{
	system("cls");
	Color(13);
	for (int i = 0; i < width + 2; i++)// top wall
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)//side wall
				cout << "#";
			if (i == y && j == x)//printing head
				cout << "O";
			else if (i == fruitY && j == fruitX)//printing fruit
				cout << "@";
			else
			{
				bool print = false;
				for (int k = 0; k < lenTail; k++)//printing tail
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
			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)//bottom wall
		cout << "#";
	cout << endl;
	cout << "Score: " << score << endl;
	cout << "FX: " << fruitX << " FY: " << fruitY<<endl;
	cout << "headX: " << x << " headY: " << y<<endl;

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
	for (int i = lenTail-1; i >0; i--) //generating tail
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
	if (!gameMode)//with walls
	{
		if (x > width-1 || x < 0||y>height-1 || y<0) // checkig whether head collides with walls 
			gameOver=true;
	}
	else//without walls
	{
		if (x >= width) x = 0; else if (x < 0) x = width - 1;
		if (y >= height) y = 0; else if (y < 0) y = height - 1;
	}

	for (int i = 0; i < lenTail; i++) //check if head collides with tail
		if (tailX[i]==x && tailY[i]==y)
			gameOver = true;

	if (x == fruitX && y == fruitY)//generating new fruit
	{
		score++;
		fruitX = rand() % (width-1)+1;
		fruitY = rand() % (height-2);
		lenTail++;
	}
	
}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(15);
	}
	
}