#pragma once
#include <iostream>
using namespace std;
const int N = 3;


class Snack
{
private:
	const char* names[N] = { "Water","Bar","Candy" };
	const double prices[N] = { 2.60,3.20,1.50 };
	const double calories[N] = { 0,487,78 };
	char *s_name;
	double s_price;
	double s_amount;
	double s_calories;
	static bool state;
public:
	//Constructors:
	Snack();//default constructor
	Snack(const char*, double);//parametrized constructor
	Snack(const Snack& p);//copy constructor
	~Snack(); //destructor
	Snack& operator=(const Snack& p);//assignment operator
	//Methods:
	void check() const;//printig the most /least caloric snack and the cheapest/ the most expensive snack in Vending Machine
	void turn_on() { state = true; };//turn on V_machine
	void turn_off() { state = false; };//turn off V_machine
	void print() const;//printing content
	static void snacks_info();// Vending machine info
	//operators
	friend istream& operator>>(istream& in, Snack& s);// order the snack
	friend ostream& operator<<(ostream& out, const Snack& p);// display what you ordered
	friend Snack operator+(const Snack& s1, const Snack& s2);// add new object
	friend Snack operator-(const Snack& s1, const Snack& s2);// subtract previous object
	//functions
	friend Snack order(Snack& s1, Snack& s2);//order process
	friend void payment(Snack& p);// payment process


};