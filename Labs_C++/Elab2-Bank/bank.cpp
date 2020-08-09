#include <iostream>
using namespace std;
#include "bank.h"

BankWindow::BankWindow(int queue_size, int working_time)  : queue_to_window(queue_size)  //by constructor of queue
{
	this->working_time = working_time;
}

ostream& operator<<(ostream& out, const BankWindow& w)
{
	out << "The number of customrs acepted into the queqe: " << w.number_accepted << endl;
	out << "The number of customrs served by window: " << w.number_served << endl;
	out << "The number of clients returned from the queue: " << w.number_returned<<endl;
	return out;
}


