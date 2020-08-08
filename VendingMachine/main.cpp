#include <iostream>
#include <iomanip>
#include "Snack.h"
using namespace std;


int main()
{
	
	 //Vending Machine- Uncomment before  turning on
	/*/cout << "----------   Part 1 ------------------------------" << endl<<endl;
	//Test for constructors and print method
	cout << "Default constructor: "<<endl<<endl;
	Snack def;
	def.print();
	cout << "Parametrized constructors: " << endl<<endl;// construction: constructor(name of snack, amount)
	cout << "Product 1" << endl;
	Snack pm_ctr1("Bar", 3);
	pm_ctr1.print();
	cout << "Product 2" << endl;
	Snack pm_ctr2("Water", 2);
	pm_ctr2.print();
	cout << "Test for copy constructor: default = prod1 " << endl;
	Snack def1(pm_ctr1);
	def1.print();
	cout << "Test for assignment operator  prod1 = prod2 " << endl;
	def1 = pm_ctr2;
	pm_ctr2.print();*/
	/*cout << "----------   Part 2 ------------------------------" << endl << endl;
	//Test for check() method
	Snack snack;
	snack.snacks_info();
	snack.check();*/
	/*cout << "----------   Part 3------------------------------" << endl<<endl;
	//Test for operators:
	//operators >> <<:
	Snack::snacks_info();// method to display types of snacks
	Snack s1_op,s2_op;
	cin >> s1_op;
	cout << s1_op;
	cin >> s2_op;
	cout << s2_op;
	//operators + -(total prices of objects and calories):
	Snack s3_op = s1_op + s2_op;// add
	cout << "SUM: " << endl;
	cout << s3_op;
	Snack s4_op = s2_op-s3_op;//subtract
	cout << "SUBTRACTION AN 'ORDER' (cancel first order): " << endl;
	cout << s4_op;
	*/
	cout << "----------   Part 4------------------------------" << endl << endl;
	//Test for functions: - I recommend to comment previous parts because of clarity!
	int state=0;
	Snack s1, s2;
	Snack sum = order(s1, s2); // I divided ordering and paying for two functions because I can change options of ordering and paying e.g to pay by card or by other currencies
	payment(sum);// in the future
	while (state !=1)//you have to turn off the machine
	{
		cout << "Turn off the machine - [1]";
		cin >> state;
	}
	sum.turn_off();//turn off machine
	cout << sum;//print that it's off
	
	return 0;
}
