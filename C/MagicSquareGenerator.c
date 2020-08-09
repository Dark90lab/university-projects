#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <math.h>
#define N 49
//Functions for generting  square
typedef struct {
	int size;
	int* blocks;
}Square;

typedef struct {
	int size;
	int* frame;
}Frame;

void free_square(Square* p)
{
	p->size = 0;
	free(p->blocks);
	p->blocks = NULL;

}

void square_generator_algo(Square* p)
{
	//first of all generate good coefficients
first:srand(time(NULL));
	int a = rand() % 10;
	int b = rand() % 10;
	int c = rand() % 10;
	int result = 3 * a;
	if ((a < 3) || (b+c>a))
		goto first;
	//create square
	p->size = 9;
	p->blocks = (int*)malloc(p->size * sizeof(int));
	//value assigment
	p->blocks[0] = a+b;
	p->blocks[1] = a-b-c;
	p->blocks[2] = a+c;
	p->blocks[3] = a+c-b;
	p->blocks[4] = a;
	p->blocks[5] = a+b-c;
	p->blocks[6] = a-c;
	p->blocks[7] = a+b+c;
	p->blocks[8] = a-b;
	
}

void square_generator_robotic(Square* p)
{
	//first of all generate good coefficients
first:srand(time(NULL));
	int a = rand() % 10;
	int b = rand() % 10;
	int c = rand() % 10;
	int result = 3 * a;
	if ((a < 3) || (b + c > a))
		goto first;
	//create square
	p->size = 9;
	p->blocks = (int*)malloc(p->size * sizeof(int));
	//value assigment
	p->blocks[0] = a + b;
	p->blocks[1] = a - b - c;
	p->blocks[2] = a + c;
	p->blocks[3] = a + c - b;
	p->blocks[4] = a;
	p->blocks[5] = a + b - c;
	p->blocks[6] = a - c;
	p->blocks[7] = a + b + c;
	p->blocks[8] = a - b;

}
//Functions for graphical representation (frame) - curiosity(nie wysz³o)
void create_frame(Frame* p)
{
	int k = 0;
	p->size = N;
	p->frame = (char*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i += 7)
	{
		k += 7;
		for (int j = i; j < k; j += 2)
		{
			p->frame[j] = '|';

		}
		for (int j = i + 1; j < k; j += 2)
		{
			p->frame[j] = '-';

		}
	}
	
	/*
	int count_for_frame = 0;
	int count_for_blocks = 0;
	for (int i = 7; i < N; i += 7)
	{
	count_for_frame+=7;
		count_for_frame += 7;
		for (int j = i + 1; j < count_for_frame; j += 2)
		{
			p->frame[j] = '0'+ q->blocks[count_for_blocks];
			count_for_blocks++;
		}

	}*/
}

void print_square(Square q)
{
	printf("\n");
	int k = 0;
	for (int i = 0; i < q.size; i+=3)
	{
		k += 3;
		for (int j = i; j < k; j++)
			printf("%d ", q.blocks[j]);

		printf("\n");
	}

}
int main()
{
	Square square;
	printf("* RANDOM 3X3 MAGIC SQUARE GENERATOR *\n");
	square_generator_algo(&square);
	print_square(square);
	free_square(&square);
}


