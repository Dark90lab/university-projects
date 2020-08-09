#include <iostream> 
#include <iomanip> 
#include <cmath>
#include "digital_signal.h"
using namespace std;

Digital_signal::Digital_signal(int no_of_samples, int* samples)
{
	this->no_of_samples = no_of_samples;
	if (no_of_samples != 0)
	{
		this->samples = new int[this->no_of_samples];
		if (samples != nullptr)
			for (int i = 0; i < this->no_of_samples; i++)
				this->samples[i] = samples[i];
		else
			for (int i = 0; i < no_of_samples; i++)
				this->samples[i] = 0;
	}
	else
		this->samples = nullptr;
}

Digital_signal::~Digital_signal()
{
	delete[] this->samples;
	samples = nullptr;
	no_of_samples = 0;
}

int  Digital_signal::min_val() const
{
	int min = 0;
	for (int i = 0; i < this->no_of_samples; i++)
	{
		if (samples[i] < min)
			min = samples[i];
	}
	return min;
}
int Digital_signal:: max_val() const
{
	int max= 0;
	for (int i = 0; i < this->no_of_samples; i++)
	{
		if (samples[i] >max)
			max = samples[i];
	}
	return max;
}


ostream& operator<<(ostream& out, const Digital_signal& ds)
{
	out << "[";
	for (int i = 0; i < ds.no_of_samples; i++)
	{
		out << " " << ds.samples[i];
	}
	out << "]" << endl;
	out << "Signal min: " << ds.min_val() << "  Signal max: " << ds.max_val();
	return out;
}

Digital_signal operator+(const Digital_signal& ds, int c)
{
	if (c == 0)
		return ds;
	for (int i = 0; i < ds.no_of_samples; i++)
		ds.samples[i] += c;
	return ds;
}

Digital_signal& Digital_signal::operator=(const Digital_signal& ds)
{
	if (this == &ds)
		return *this;

	this->no_of_samples = ds.no_of_samples;
	if (ds.no_of_samples == 0)
	{
		this->no_of_samples = 0;
		this->samples = nullptr;
		return *this;
	}
	delete[] this->samples;
	this->samples = new int[this->no_of_samples];
	for (int i = 0; i < this->no_of_samples; i++)
		this->samples[i] = ds.samples[i];
	return *this;
}

Digital_signal::Digital_signal(const Digital_signal& ds)
{
	this->no_of_samples = ds.no_of_samples;
	if (ds.no_of_samples == 0)
	{
		this->no_of_samples = 0;
		this->samples = nullptr;
		return;
	}

		this->samples = new int[this->no_of_samples];
		for (int i = 0; i < this->no_of_samples; i++)
			this->samples[i] = ds.samples[i];
}