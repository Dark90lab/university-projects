#include <iostream> 
#include <iomanip> 
#include <cmath>
#include "signal_plot.h"
using namespace std;


Signal_plot::Signal_plot(int no_of_samples, int* samples )
{
	this->signal.no_of_samples = no_of_samples;
	if (no_of_samples != 0)
	{
		this->signal.samples = new int[this->signal.no_of_samples];
		if (samples != nullptr)
			for (int i = 0; i < this->signal.no_of_samples; i++)
				this->signal.samples[i] = samples[i];
		else
			for (int i = 0; i < no_of_samples; i++)
				this->signal.samples[i] = 0;
	}
	else
		this->signal.samples = nullptr;
	this->init_plot();
	this->update_plot();

}

Signal_plot::~Signal_plot()
{
	clean_plot();
}


void Signal_plot::init_plot()
{
	if (signal.min_val() >= 0)
	{
		if (signal.max_val() == 0)
		{
			plot = new char* [1];
			no_of_rows = 1;
		}
		else
		{
			plot = new char* [signal.max_val() + 1];
			no_of_rows = signal.max_val() + 1;
		}
		no_of_columns = signal.no_of_samples;
		for (int i = 0; i < no_of_rows; i++)
			plot[i] = new char[no_of_columns];
	}
	else
	{
		no_of_rows = signal.max_val() + 1 + ((-1) *signal.min_val());
		no_of_columns = signal.no_of_samples;
		plot = new char* [no_of_rows];
		for (int i = 0; i < no_of_rows; i++)
			plot[i] = new char[no_of_columns];
	}
}

void Signal_plot::update_plot()
{
	if (this->signal.no_of_samples == 0)
		return;
	Digital_signal tmp=this->signal;

	if (signal.min_val() < 0)
	{
		for (int i = 0; i < signal.no_of_samples; i++)
			tmp.samples[i] += abs(signal.min_val());
	}
	tmp.min_val();
	tmp.max_val();
	for (int i = 0; i < no_of_rows; i++)
	{
		for (int j = 0; j < no_of_columns; j++)
			plot[i][j] = ' ';
	}
	for (int i = 0; i < this->no_of_rows; i++)
	{
		for (int j = 0; j < this->no_of_columns; j++)
		{
			if (tmp.samples[j] == i)
				plot[tmp.max_val() - tmp.samples[j]][j] = '*';
		}
	}

}

void Signal_plot::clean_plot()
{
	for (int i = 0; i < this->no_of_rows; i++)
		delete[] plot[i];
	delete[] plot;
	plot = nullptr;
	this->no_of_columns = 0;
	this->no_of_rows = 0;
}



ostream& operator<<(ostream& out, const Signal_plot& s)
{
	for (int j = 0; j < s.no_of_columns; j++)
		out << '-';
	out << endl;

	for (int i = 0; i < s.no_of_rows; i++)
	{
		for (int j = 0; j < s.no_of_columns; j++)
		{
			out << s.plot[i][j];
		}
		out << endl;
	}

	for (int j = 0; j < s.no_of_columns; j++)
		out << '-';
	out << endl;

	return out;
}

Signal_plot& Signal_plot::operator=(const Signal_plot&s)
{
	this->clean_plot();
	this->signal = s.signal;
	this->init_plot();
	this->update_plot();
	return *this;
}

Signal_plot::Signal_plot(const Digital_signal&ds)
{
	this->clean_plot();
	this->signal = ds;
	this->init_plot();
	this->update_plot();
}


Signal_plot::Signal_plot(const Signal_plot&s)
{
	this->clean_plot();
	this->signal = s.signal;
	this->init_plot();
	this->update_plot();
}



















