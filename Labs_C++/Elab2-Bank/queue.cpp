#include <iostream>
using namespace std;
#include "queue.h"

Queue::Queue(int qs): front(nullptr),rear(nullptr),qsize(qs),clients(0){}

Queue::~Queue()
{
	if (isempty())
		return;
	Node* tmp = front;
	while (tmp != nullptr)
	{
		front = front->next;
		delete tmp;
		tmp = front;
	}
	front = nullptr;
	rear = nullptr;
}

bool Queue::isempty() const
{
	if (front)
		return false;
	else
		return true;
}

bool Queue::isfull() const
{
	if (clients == qsize)
		return true;
	else
		return false;
}

int Queue::size() const
{
	int count=0;
	if (isempty())
		return 0;
	Node* tmp = front;
	while (tmp != nullptr)
	{
		count++;
		tmp = tmp->next;
	}
	return count;
}

bool Queue::enqueue(const Client& client)
{
	if(isfull())
		return false;
	Node* tmp = new Node{ client,nullptr };
	if (isempty())
		front = rear = tmp;
	else
	{
		rear->next = tmp;
		rear = tmp;
	}
	this->clients++;
	return true;
}

bool Queue::dequeue(Client& client)
{
	if (isempty())
		return false;
	Node* tmp = new Node{client,nullptr};
	if (front == rear)
	{
		this->clients--;
		client = front->item;
		rear=front = nullptr;
		return true;
	}
	tmp = front;
	client = front->item;
	front = front->next;
	this->clients--;
	delete tmp;
}

ostream& Queue::print(ostream& out) const
{
	if (isempty())
	{
		
		out << "Queue:" << endl << "Empty queue!" << endl;
		return out;
	}
	else
	{
		out << "Queue:" << endl;
		Node* tmp = new Node;
		tmp->item = front->item;
		tmp->next = front->next;
		for (int i = 0; i < this->size(); i++)
		{
			out << tmp->item << endl;
			tmp = tmp->next;
		}
		return out;
	}
}

ostream& operator<<(ostream& out, const Queue& q)
{
	q.print(out);
	return out;
}
