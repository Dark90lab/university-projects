//#include <iostream>
//#include <cassert>
//#include "linkedQueue.h"
//using namespace std;

////Default constructor
//linkedQueue::linkedQueue()
//{
//	queueFront = nullptr; //set front to null
//	queueRear = nullptr;  //set rear to null
//} //end default constructor
//
//
//bool linkedQueue::isEmptyQueue() const
//{
//	return(queueFront == nullptr);
//} //end isEmptyQueue
//
//
//void linkedQueue::initializeQueue()
//{
//	node *temp;
//
//	while (queueFront != nullptr)  //while there are elements left
//							   //in the queue
//	{
//		temp = queueFront;  //set temp to point to the 
//							//current node
//		queueFront = queueFront->link;  //advance first to  
//										//the next node
//		delete temp;    //deallocate memory occupied by temp
//	}
//
//	queueRear = nullptr;  //set rear to NULL
//} //end initializeQueue
//
//
//void linkedQueue::addQueueBack(const int& newElement)
//{
//	node *newNode;
//
//	newNode = new node;   //create the node
//
//	newNode->data = newElement; //store the data
//	newNode->link = nullptr;  //initialize the link field to NULL
//
//	if (queueFront == nullptr) //if initially the queue is empty
//	{
//		queueFront = newNode;
//		queueRear = newNode;
//	}
//	else        //add newNode at the end
//	{
//		queueRear->link = newNode;
//		queueRear = queueRear->link;
//	}
//}//end addQueueBack
//
//
//void linkedQueue::addQueueFront(const int& newElement)
//{
//	node *newNode;
//
//	newNode = new node;   //create the node
//
//	newNode->data = newElement; //store the data
//	newNode->link = nullptr;  //initialize the link field to NULL
//
//	if (queueFront == nullptr) //if initially the queue is empty
//	{
//		queueFront = newNode;
//		queueRear = newNode;
//	}
//	else        //add newNode at the begining
//	{
//		newNode->link = queueFront;
//		queueFront = newNode;
//	}
//}//end addQueueFront
//
//
//int linkedQueue::front() const
//{
//	assert(queueFront != nullptr);
//	return queueFront->data;
//} //end front
//
//
//int linkedQueue::back() const
//{
//	assert(queueRear != nullptr);
//	return queueRear->data;
//} //end back
//
//
//void linkedQueue::deleteQueue()
//{
//	node *temp;
//
//	if (!isEmptyQueue())
//	{
//		temp = queueFront;  //make temp point to the 
//							//first node
//		queueFront = queueFront->link; //advance queueFront 
//
//		delete temp;    //delete the first node
//
//		if (queueFront == nullptr) //if after deletion the 
//								//queue is empty
//			queueRear = nullptr;   //set queueRear to NULL
//	}
//	else
//		cout << "Cannot remove from an empty queue" << endl;
//}//end deleteQueue
//
//
//	//Destructor
//linkedQueue::~linkedQueue()
//{
//	initializeQueue();
//} //end destructor
//
//ostream& operator<<(ostream& out, const linkedQueue& q)
//{
//	if (!q.isEmptyQueue())
//	{
//		node* temp = q.queueFront;
//		while (temp != nullptr)
//		{
//			out << temp->data << " ";
//			temp = temp->link;
//		}
//	}
//	else
//		out << "Cannot print an empty queue";
//	
//	return out;
//}



