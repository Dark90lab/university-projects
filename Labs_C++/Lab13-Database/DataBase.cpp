#include <iostream>
#include <string>

#include "DataBase.h"

using namespace std;

void DataBase::ShowData()
{
    for(auto & employeer : employeers) {
        cout << employeer.FirstName << " " << employeer.LastName << " Position: " << employeer.Position << " Salary: " << employeer.Salary << endl;
    }
}

bool DataBase::AddEmployee(Employee e)
{
    bool flag = true;

    for(auto & employeer : employeers) {
        if(e.FirstName == employeer.FirstName and e.LastName == employeer.LastName) {
            flag = false;
        }
    }

    if(flag) {
        employeers.push_back(e);
        return true;
    } else {
        return false;
    }
}

bool DataBase::AddEmployee()
{
    string name, surname, position;
    int salary;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter surname: ";
    cin >> surname;
    cout << "Enter position: ";
    cin >> position;
    cout << "Enter salary: ";
    cin >> salary;

    Employee temp(name, surname, position, salary);

    return AddEmployee(temp);

}

bool DataBase::ModifyEmployee()
{

    string name, lastName, position;
    int salary;

    cout << "Enter first name: ";
    cin >> name;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter new position: ";
    cin >> position;
    cout << "Enter new salary: ";
    cin >> salary;

    for(auto & employeer : employeers) {
        if(name == employeer.FirstName and lastName == employeer.LastName) {
            employeer.Position = position;
            employeer.Salary = salary;
            return true;
        }
    }

    return false;
}

bool DataBase::DeleteEmployee()
{

    string name, lastName;

    cout << "Enter first name: ";
    cin >> name;
    cout << "Enter last name: ";
    cin >> lastName;

    for(auto it = employeers.begin(); it != employeers.end(); it++) {
        if(name == it->FirstName and lastName == it->LastName) {
            employeers.erase(it);
            return true;
        }
    }
    return false;
}

void DataBase::SortByName()
{

    employeers.sort([&]( Employee & a, const Employee & b) { return a.FirstName < b.FirstName; });

}

Employee DataBase::MaxSalary()
{

    bool flag = false;
    auto temp = employeers.begin();

    for(auto it = employeers.begin(); it != employeers.end(); it++) {
        if(it->Salary > temp->Salary) {
            temp = it;
            flag = true;
        }
    }

    if(flag) {
        return Employee(temp->FirstName, temp->LastName, temp->Position, temp->Salary);
    } else {
        return Employee("", "", "", -1);
    }

}

void DataBase::FindPosition() {

    string word;
    list <Employee> temp;

    cout << "Enter word to search by: ";
    cin >> word;

    for(auto & employeer : employeers) {
        if (employeer.Position.find(word) != string::npos) {
            temp.push_back(employeer);
        }
    }

    for(auto & it : temp) {
        cout << it.FirstName << " " << it.LastName << " Position: " << it.Position << " Salary: " << it.Salary << endl;
    }

}

void DataBase::RemoveSalaryAbove()
{
    int limit;

    cout << "Enter salary limit: ";
    cin >> limit;

    for(auto it = employeers.begin(); it != employeers.end(); it++) {
        if(it->Salary > limit) {
            employeers.erase(it);
        }
    }
}

