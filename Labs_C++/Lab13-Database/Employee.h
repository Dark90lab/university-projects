#pragma once

#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    string FirstName;
    string LastName;
    string Position;
    int Salary;

    Employee(string fn, string ln, string pos, int sal);

    friend ostream& operator<<(ostream& os, const Employee& s);

    // You may add declaration of needed elements

};

