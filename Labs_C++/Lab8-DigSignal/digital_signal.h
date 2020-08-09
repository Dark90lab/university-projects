#pragma once
#include <iostream> 
using namespace std;

class Digital_signal
{
private:
	int* samples;
	int no_of_samples;

	friend class Signal_plot;

public:
	
	Digital_signal(int no_of_samples = 0, int* samples = nullptr);
	~Digital_signal();

	Digital_signal& operator=(const Digital_signal& ds);//copy constructor
	Digital_signal(const Digital_signal&);
	int min_val() const;
	int max_val() const;

	friend ostream& operator<<(ostream&, const Digital_signal&);
	friend Digital_signal operator+(const Digital_signal&, int c);

};