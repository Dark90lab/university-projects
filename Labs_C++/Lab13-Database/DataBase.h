#pragma once

#include <string>
#include <list>

#include "Employee.h"

using namespace std;

class DataBase
{
private:
    list<Employee> employeers;

    // You may add declaration of needed elements

public:
    void ShowData();
    bool AddEmployee(Employee e);
    bool AddEmployee();
    bool ModifyEmployee();
    bool DeleteEmployee();
    void SortByName();
    Employee MaxSalary();
    void FindPosition();
    void RemoveSalaryAbove();
};

