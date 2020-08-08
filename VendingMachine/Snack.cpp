#include <iostream>
#include <string.h>
#include "Snack.h"
#include <cmath>
using namespace std;

bool Snack::state = 1;//default Machine is ON

istream& operator>>(istream& in, Snack& p)//data input
{
	int num;
	do                 // Typing number of product
	{
		cout << "Select snack number: ";
		in >> num;
	} while ((num != 0) && (num != 1) && (num != 2));//if it's wrong type one more time
	delete[] p.s_name;// delete old name{reset}
	p.s_name = new char[strlen(p.names[num])+1];//allocate new array with length of appropriate name + one place for '\0'
	strcpy(p.s_name, p.names[num]); //setting the name of snack
	cout << "Enter amount: ";
	in >> p.s_amount;			// setting amount of snack
	p.s_price = p.s_amount * p.prices[num];//setting price of snack multiplied by amount
	p.s_calories = p.s_amount * p.calories[num];//setting calories of snack multiplied by amount
	return in;
}

ostream& operator<<(ostream& out, const Snack& p)//data output
{
	if (Snack::state == 0)//if machine is off then print that its turn off
	{
		out << "Machine is OFF" << endl << endl;
		return out;
	}
	else
	{
		out << "Machine is On" << endl << endl;
		if (p.s_name == NULL)//checking default object name
			out << "Snack: NULL";
		else
		{
			if (!strcmp(p.s_name, "SUM"))// checing if object is a result of +/- operator
			{
				out << "Total: " << endl << "Price: " << p.s_price << "[zl]" << endl;
				out << "Cal: " << p.s_calories << "[cal]" << endl << endl;
				return out;
			}
			
			out << "Snack: ";
			int len = strlen(p.s_name);
			for (int i = 0; i < len; i++)//coping name of snack 
				out << p.s_name[i];
		}
		cout << endl;
		out << "Amount: " << p.s_amount << " [pc.]" << endl << "Total Price: " << p.s_price << "[zl]" << endl << "Calories: " << p.s_calories << " [cal]" << endl << endl;
		return out;
	}
}
Snack  operator+(const Snack& s1, const Snack& s2)//add calories and prices
{
	Snack s;
	s.s_name = new char[4];
	strcpy(s.s_name, "SUM");//"SUM" name impacts on the output format
	s.s_calories = s1.s_calories + s2.s_calories;
	s.s_price = s1.s_price + s2.s_price;
	return s;

}

Snack  operator-(const Snack& s1, const Snack& s2)//subtract calories and prices
{
	Snack s;
	s.s_name = new char[4];
	strcpy(s.s_name, "SUM"); // "SUM" name impacts on the output format
	s.s_calories = s1.s_calories - s2.s_calories;
	s.s_price = s1.s_price - s2.s_price;
	if (s.s_price < 0)//test for negative value 
		s.s_price *= (-1);
	if (s.s_calories < 0)
		s.s_calories *= (-1);
	return s;
}

Snack::Snack() : s_name(nullptr), s_price(0), s_calories(0), s_amount(0) // default constructor 
{
	
}

Snack::Snack(const char* _name, double amount)//parametrized constructor where you have to put name of snack and amount
{
	
	int count = 0;
	for (int i = 0; i < N; i++) // check if  name is different from available names if no construct default object
	{
		if (!strcmp(names[i],_name))
		{
			count++;
		}
	}
	if (count == 0)
	{
		s_name = nullptr;
		s_amount = 0;
		s_calories = 0;
		s_price = 0;
		return;
	}

	this->s_amount = amount;//set ammount

	for (int i = 0; i < N; i++)
	{
		if (!strcmp(_name, names[i]))//test for name of snack to allocate s_name array
		{
			int len = strlen(names[i]);
			s_name = new char[len+1];//allocating new array which last element in '\0'
			s_name[len] = '/0';
			if (!s_name)//check for failed allocation
			{
				s_amount = 0;
				s_calories = 0;
				s_price = 0;
				return;
			}
			strcpy(this->s_name, names[i]);//assign proper snack name
			this->s_price = prices[i] * s_amount;
			this->s_calories = calories[i] * s_amount;
		}



	}

}

Snack::~Snack() //destructor
{
	delete[] s_name;
}

Snack::Snack(const Snack& p) // copy constructor
{

	if (p.s_name==nullptr)
	{
		s_name = nullptr;
		s_amount = 0;
		s_calories = 0;
		s_price = 0;
		return;

	}
	this->s_name = new char[strlen(p.s_name) + 1];//allocte
	strcpy(this->s_name,p.s_name);//copy string
	this->s_amount = p.s_amount;
	this->s_calories = p.s_calories;
	this->s_price = p.s_price;
}

Snack& Snack::operator=(const Snack& p)//assignment operator
{
	if (this == &p)
		return *this;
	delete[] s_name;
	if (p.s_name == nullptr)//set values for null object
	{
		s_name = nullptr;
		s_amount = 0;
		s_calories = 0;
		s_price = 0;
		return *this;

	}
	this->s_name = new char[strlen(p.s_name) + 1];
	strcpy(this->s_name, p.s_name);
	s_amount = p.s_amount;
	s_calories = p.s_calories;
	s_price = p.s_price;
	return *this;


}

void Snack::snacks_info() //Method - global info for Vending Machine 
{
	cout << "*VENDING MACHINE* " << endl;
	cout << "Number in squared brackets informs you which key you have to press." << endl;
	cout << "Select  the number of scnack from below : " << endl;
	cout << "[0] - Water   - 2.60 [zl/pc] - 0   [cal]" << endl;
	cout << "[1] - Bar     - 3.20 [zl/pc] - 487 [cal]" << endl;
	cout << "[2] - Candy   - 1.50 [zl/pc] - 78  [cal]" << endl << endl;

}

void Snack::print() const // Method - printing content of Snack
{

	if (this->s_name != nullptr)
	{
		int len = strlen(s_name);
		cout << "Snack: ";
		for (int i = 0; i < len; i++)
			cout << s_name[i];
	}
	else { cout << "Snack: NULL"; }
	cout << endl;
	cout << "Amount: " << s_amount << " [pc.]" << endl << "Total Price: " << s_price << "[zl]" << endl << "Calories: " << s_calories << " [cal]" << endl << endl;

}

Snack order(Snack& s1, Snack& s2) // Function - order all snacks and return total price and calories to pay for it
{
	Snack::snacks_info();// Vending Machine content
	cin >> s1;//input first snack
	cout << s1;
	cout << "Add snack? Yes -[1], No -[0] " << endl;
	int test1;
	cin >> test1;
	if (test1 == 0)//if you wouldn't like to modify order -  return 
	{
		Snack sum = s1;
		s1.s_name = new char[4];//allocate array for special name 
		strcpy(sum.s_name, "SUM");// change name of object to format an output
		return sum;
	}
	else
	{
		cin >> s2;//if you'd like to add something you can do it
		cout << s2;
		Snack sum2 = s1 + s2;//sum calories and prices
		cout << "That's all - [1] Cancel previous snack - [0] " << endl;// if you want you can cancel s1 snack and pay only for the second order
		int test2;
		cin >> test2;
		if (test2 == 1)
			return sum2;
		else
		{
			Snack substract = s2-sum2;// canceling s2 snack by operator -
			return substract;

		}

	}

}

double coin_check(double n)//auxiliary function to payment function
{
	int k;
	if (n == 1 || n == 2 || n == 5)//check, if coin is proper then  return
	{
		return n;
	}
	else
	{
		do
		{
			cout << "Insert Coin: ";//insert coin 
			cin >> k;
		} while (k!=1 && k!=2 && k!=5);

		return k;
	}
}


void payment(Snack& p)//Function which take bject which has summed calories and PRICE
{
	if (strcmp(p.s_name,"SUM"))
	{
		cout << "Invalid object passed into payment function!" << endl;
		return;
	}

	cout << p;// display total values 
	cout << "Available Coins: 1 [zl] 2 [zl] 5 [zl]" << endl;
	cout << "Vending Machine gives the change!(also grosze),Throw in one by one!" << endl;

	double sum = p.s_price;
	double c_cash;//customer cash
	double rest;

	cout << "Insert Coin: ";
	cin >> c_cash;// first coin
	c_cash = coin_check(c_cash);
	if (c_cash > p.s_price)// check whether coin is greatehr than total price, if yes - return rest for customer
	{
		rest = c_cash - p.s_price;
		cout << "Rest: " << rest << endl;
	}
	else// if no - customer must put another coin
	{
		p.s_price = p.s_price - c_cash;// substract first coin from remaining price
		while (p.s_price >= 0) // loop to fulfill missing founds
		{
			cout << "Left: " << p.s_price << endl;
			cout << "Insert Coin: ";
			cin >> c_cash;
			c_cash = coin_check(c_cash);
			p.s_price = p.s_price - c_cash;
		}
		cout << "Rest: " << p.s_price*(-1) << endl;// take an absolute value
	}
	cout << "Than you!"<<endl;
}


void Snack::check() const
{
	double most_cal=this->calories[0];//the most caloric
	int maxidx1=0;//max index 1
	int minidx1=0;//min index 1
	double least_cal=this->calories[0];// least caloric
	cout << "The most caloric snack is: ";
	for (int i = 1; i < N; i++)//loop which returns indexes
	{
		if (this->calories[i] > most_cal)
		{
			maxidx1 = i;
			most_cal = this->calories[i];
		}

		if (this->calories[i] < least_cal)
		{
			minidx1 = i;
			least_cal = this->calories[i];
		}
	}
	cout << this->names[maxidx1]<< endl;//printing results
	cout << "The least caloric snack is: ";
	cout << this->names[minidx1] << endl<<endl;

	double exp = this->prices[0];// the most expensive
	int maxidx2 = 0;// max index 2
	int minidx2 = 0;//min index 2
	double cheap = this->prices[0];// the cheapest
	cout << "The most expensive snack is: ";
	for (int i = 1; i < N; i++)//loop which returns indexes
	{
		if (this->prices[i] > exp)
		{
			maxidx2 = i;
			exp = this->prices[i];
		}

		if (this->prices[i] < cheap)
		{
			minidx2 = i;
			least_cal = this->prices[i];
		}
	}
	cout << this->names[maxidx2] << endl;//printing results
	cout << "The cheapest snack is: ";
	cout << this->names[minidx2] << endl;
}
