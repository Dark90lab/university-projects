#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <math.h>
#include <ctype.h>

typedef struct _ListElem
{
	int data;
	struct _ListElem* next;
}ListElem;

typedef struct _CircularList
{
	ListElem* head;
	ListElem* tail;
}CircularList;

ListElem* create_elem(int data)
{
	ListElem* m = malloc(sizeof(ListElem));
	m->data = data;
	m->next = NULL;
	return m;
}

void insert_last(CircularList* l, ListElem* m)
{

	if (l->head == NULL)
	{
		l->head = m;
		l->head->next = l->head;
	}
	else
	{
		ListElem* last = l->head;
		while (last->next != l->head)
			last = last->next;

		last->next = m;
		m->next = l->head;
	}

}
void insert_begin(CircularList* l, ListElem* m)
{
	if (l->head == NULL)
	{
		l->head = m;
		l->head->next = l->head;
	}
	else
	{
		ListElem* last = l->head;
		while (last->next != l->head)
			last = last->next;

		last->next = m;
		m->next = l->head;
		m = l->head;
	}
}

void insert_sorted(CircularList* l, ListElem* m)
{
	if (l->head == NULL)
	{
		l->head = l->tail = m;
		l->tail->next = l->head;
	}
	if (l->head == l->tail)
	{
		if (l->head->data > m->data)
		{
			l->tail->next = m;
			m->next = l->head;
			l->head = m;
		}
		else
		{
			l->head->next = m;
			l->tail = m;
			l->tail->next = l->head;
		}
	}
	else
	{
		if (l->tail->data < m->data)
		{
			l->tail->next = m;
			l->tail = m;
			l->tail->next = l->head;
		}
		if (m->data < l->head->data)
		{
			l->tail->next = m;
			m->next = l->head;
			l->head = m;
		}
		if ((m->data > l->head->data) && (m->data < l->tail->data))
		{
			ListElem* last = l->head;
			ListElem* prev = l->head;
			while (last->next != l->head)
			{
				if (last->data > m->data)
					break;
				last = last->next;
			}
			while (prev->next != last)
				prev = prev->next;

			prev->next = m;
			m->next = last;
		}
	}
}

void delete_list(CircularList* l)
{
	ListElem* last = l->head;
	while (last->next != l->head)
	{
		ListElem* tmp = last;
		last = last->next;
		free(tmp);
	}
	l->head = NULL;

}
void delete_begin(CircularList* l)
{
	if (l->head != NULL)
	{
		ListElem* last = l->head;
		while (last->next != l->head)
			last = last->next;
		last->next = l->head->next;
		ListElem* tmp = l->head;
		l->head = l->head->next;
		free(tmp);
	}

}

void delete_last(CircularList* l)
{
	if (l->head != NULL)
	{
		ListElem* last = l->head;
		while (last->next != l->head)
			last = last->next;
		ListElem* prev = l->head;
		while (prev->next != last)
			prev = prev->next;
		prev->next = l->head;
		ListElem* tmp = last;
		free(tmp);

	}

}

void print_list(CircularList* l)
{
	if (l->head == NULL)
	{
		printf("\nList is empty!\n");
	}
	else {
		ListElem* tmp = l->head;
		do
		{
			printf("%d ", tmp->data);
			tmp = tmp->next;
		} while (tmp->next != l->head);
		printf("%d ", tmp->data);
		printf("\n");
	}
}
int main()
{
	CircularList l = { NULL };
	insert_sorted(&l, create_elem(15));
	insert_sorted(&l, create_elem(10));
	insert_sorted(&l, create_elem(17));
	insert_sorted(&l, create_elem(13));
	insert_sorted(&l, create_elem(25));
	insert_sorted(&l, create_elem(9));
	print_list(&l);
	delete_list(&l);
	print_list(&l);
}