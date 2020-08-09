#pragma once
#include <iostream>
#include <cassert>
using namespace std;


//Definition of the node
template <typename T>
struct node
{
	T data;
	node *link;
};

template <typename T>
class linkedQueue
{
public:
	bool isEmptyQueue() const;
	//Function to determine whether the queue is empty. 
	//Postcondition: Returns true if the queue is empty,
	//               otherwise returns false.

	void initializeQueue();
	//Function to initialize the queue to an empty state.
	//Postcondition: queueFront = nullptr; queueRear = nullptr

	T front() const;
	//Function to return the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program 
	//               terminates; otherwise, the first 
	//               element of the queue is returned. 

	T back() const;
	//Function to return the last element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program 
	//               terminates; otherwise, the last 
	//               element of the queue is returned.

	void addQueueBack(const T& queueElement);
	//Function to add queueElement to the queue at the end.
	//Precondition: The queue exists and is not full.
	//Postcondition: The queue is changed and queueElement
	//               is added to the queue.

	void addQueueFront(const T& queueElement);
	//Function to add queueElement to the queue at the begining.
	//Precondition: The queue exists and is not full.
	//Postcondition: The queue is changed and queueElement
	//               is added to the queue.

	void deleteQueue();
	//Function  to remove the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: The queue is changed and the first 
	//               element is removed from the queue.

	linkedQueue();
	//Default constructor

	const linkedQueue<T>& operator=(const linkedQueue<T>&) = delete;
	//assignment operator.

	linkedQueue(const linkedQueue<T>& otherQueue) = delete;
	//Copy constructor

	virtual ~linkedQueue();
	//Destructor
	template <typename T>
	friend ostream& operator<<(ostream& os, const linkedQueue<T>& q);

protected:
	node<T> *queueFront; //pointer to the front of 
								//the queue
	node<T> *queueRear;  //pointer to the rear of 
								//the queue
};

//Default constructor
template <typename T>
linkedQueue<T>::linkedQueue()
{
	queueFront = nullptr; //set front to null
	queueRear = nullptr;  //set rear to null
} //end default constructor

template <typename T>
bool linkedQueue<T>::isEmptyQueue() const
{
	return (queueFront == nullptr);
} //end isEmptyQueue

template <typename T>
void linkedQueue<T>::initializeQueue()
{
	node<T>* temp;

	while (queueFront != nullptr)  //while there are elements left
							   //in the queue
	{
		temp = queueFront;  //set temp to point to the 
							//current node
		queueFront = queueFront->link;  //advance first to  
										//the next node
		delete temp;    //deallocate memory occupied by temp
	}

	queueRear = nullptr;  //set rear to NULL
} //end initializeQueue

template <typename T>
void linkedQueue<T>::addQueueBack(const T& newElement)
{
	node<T>* newNode;

	newNode = new node<T>;   //create the node

	newNode->data = newElement; //store the data
	newNode->link = nullptr;  //initialize the link field to NULL

	if (queueFront == nullptr) //if initially the queue is empty
	{
		queueFront = newNode;
		queueRear = newNode;
	}
	else        //add newNode at the end
	{
		queueRear->link = newNode;
		queueRear = queueRear->link;
	}
}//end addQueueBack

template <typename T>
void linkedQueue<T>::addQueueFront(const T& newElement)
{
	node<T>* newNode;

	newNode = new node<T>;   //create the node

	newNode->data = newElement; //store the data
	newNode->link = nullptr;  //initialize the link field to NULL

	if (queueFront == nullptr) //if initially the queue is empty
	{
		queueFront = newNode;
		queueRear = newNode;
	}
	else        //add newNode at the begining
	{
		newNode->link = queueFront;
		queueFront = newNode;
	}
}//end addQueueFront

template <typename T>
T linkedQueue<T>::front() const
{
	assert(queueFront != nullptr);
	return queueFront->data;
} //end front

template <typename T>
T linkedQueue<T>::back() const
{
	assert(queueRear != nullptr);
	return queueRear->data;
} //end back

template <typename T>
void linkedQueue<T>::deleteQueue()
{
	node<T>* temp;

	if (!isEmptyQueue())
	{
		temp = queueFront;  //make temp point to the 
							//first node
		queueFront = queueFront->link; //advance queueFront 

		delete temp;    //delete the first node

		if (queueFront == nullptr) //if after deletion the 
								//queue is empty
			queueRear = nullptr;   //set queueRear to NULL
	}
	else
		cout << "Cannot remove from an empty queue" << endl;
}//end deleteQueue


//Destructor
template <typename T>
linkedQueue<T>::~linkedQueue()
{
	initializeQueue();
} //end destructor

template <typename T>
ostream& operator<<(ostream& out, const linkedQueue<T>& q)
{
	if (!q.isEmptyQueue())
	{
		node<T>* temp = q.queueFront;
		while (temp != nullptr)
		{
			out << temp->data << " ";
			temp = temp->link;
		}
	}
	else
		out << "Cannot print an empty queue";

	return out;
}