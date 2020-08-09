#include <iostream>
#include <iomanip>
#include <string>

#include "Employee.h"

using namespace std;

Employee::Employee(string fn, string ln, string pos, int sal)
{
    FirstName = fn;
    LastName = ln;
    Position = pos;
    Salary = sal;
}

ostream&operator<<(ostream& os, const Employee& e)
{
    os << " | " << left << setw(15) << e.FirstName << " | " << setw(20) << e.LastName << " | " << setw(20) << e.Position << " | " << right << setw(8) << e.Salary << " | " << endl ;
    return os;
}

// You may add implementation of needed elements

