#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#define BORROWED 0
#define AVAILABLE 1

typedef struct Book {
	char title[80];
	int year;
	int status;
}Book;

void printBook(Book *p)
{
	if (p->status == BORROWED) {
		printf("%s %d %s\n", p->title, p->year, "BORROWED");
	}
	else {
		printf("%s %d %s\n", p->title, p->year, "AVAILABLE");
	}

}
void readBook(Book *p)
{
	scanf("%s%d%d", p->title,&p->year,&p->status);
}
void copyBook(Book *p,Book *q)
{
	strcpy(p->title, q->title);
	p->year = q->year;
	p->status = q->status;
}
int compareBooks(Book *p,Book *q)
{
	if(p->status!=q->status)
	{
		return p->status - q->status;
	}
	if(p->year<q->year)
	{
		return -1;
	}
	if (p->year > q->year)
	{
		return 1;
	}
	return strcmp(p->title, q->title);


}

void swap(Book* p, Book* q)
{
	Book tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}
void sortBooks(Book books[],int size)
{

	for (int m = 0; m < size; m++) {
		for (int i = m; i < size; i++)
		{
			if (compareBooks(&books[i], &books[m]) > 0)
			{
				swap(&books[m], &books[i]);

			}
		
		}
	}
}


int main() {
	printf("*********** Part 1 ***********\n");
	
	Book a;
	//Test readBook, printBook on variable a
	readBook(&a);
	printBook(&a);

	printf("\n*********** Part 2 ***********\n");
	
	Book b;
	readBook(&b);
	printBook(&b);
	puts("\nCopy Book (a to b)");
	copyBook(&b, &a);
	printBook(&b);
	//Test function copyBook using a and b, and use printBook to demonstrate the result
	

	printf("*********** Part 3 ***********\n");
	
	//read new data into b, then print and compare the two books
    readBook(&b);
	puts("Comparing Books:");
	printBook(&a);
	printf("state (a&b)%d (b&a )%d (b&b)%d\n", compareBooks(&a,&b),compareBooks(&b,&a), compareBooks(&b,&b));
	
	
	printf("*********** Part 4 ***********\n");
	
	Book list[] = {
			{ "The Lord of the Rings", 1955, BORROWED },
			{ "Tristes Tropiques", 1955, BORROWED },
			{ "The Great Gatsby", 1925, BORROWED },
			{ "Waiting for Godot", 1952, AVAILABLE },
			{ "Midnight's Children", 1981, AVAILABLE },
			{ "1984", 1949, AVAILABLE },
			{ "For Whom the Bell Tolls", 1940,BORROWED },
			{ "Il nome della rosa", 1981, AVAILABLE }
		};
	int i, size;
	size = sizeof(list) / sizeof(Book);
	puts("\nUnsorted list");
	//Print the array list
	for (i=0; i < size; i++)
	{
		printBook(&list[i]);
	}
	sortBooks(list, size);
	//Sort it using sortBooks

	puts("\nSorted list");
	//Print the array again
	for (i=0; i<size; i++)
	{
		printBook(&list[i]);
	}
	
	return 0;

}