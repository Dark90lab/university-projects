#include <iostream>
using namespace std;
#include "client.h"

Client::Client()
{
	this->arrival_time = 0;
	this->service_time = 0;
}

void Client::set(long arrival_time)
{
	this->arrival_time = arrival_time;
	this->service_time = 10;
}

ostream& operator<<(ostream& out, const Client& c)
{
	out << "Arrival Time: " << c.arrival_time << " " << "Service time: " << c.service_time;
	return out;

}
