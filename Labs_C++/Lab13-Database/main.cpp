#include <iostream>
#include <string>

#include "Employee.h"
#include "DataBase.h"

using namespace std;

int main()
{
    Employee employeers[] = {
            Employee("Kazimierz", "Wielki", "programmer", 6000),
            Employee("Major", "Major", "sales manager", 5000),
            Employee("Piotr", "Kowalski", "senior programmer", 11000),
            Employee("Jan", "Kowalski", "junior programmer", 3000),
            Employee("Anna", "Smith", "programmer", 7000),
            Employee("James", "Bond", "senior programmer", 13000),
            Employee("Sherlock", "Holmes", "tester", 4321),
            Employee("Julius", "Caesar", "CEO", 1200000),
            Employee("Karolina", "Lewandowska", "project manager", 15000),
            Employee("Jan", "Dzban", "watchman", 2000),
    };
    DataBase db;
    for ( auto e : employeers )
        db.AddEmployee(e);

    string s;
    do
    {
        cout << endl;
        cout << "select operation" << endl;
        cout << "1 - show data" << endl;
        cout << "2 - add employee" << endl;
        cout << "3 - modify employee" << endl;
        cout << "4 - delete employee" << endl;
        cout << "5 - sort employees by name" << endl;
        cout << "6 - find employee with max salary" << endl;
        cout << "7 - find all employees with given position" << endl;
        cout << "8 - remove all employees with salary above given value" << endl;
        cout << "0 - exit" << endl;
        cin >> s;
        if ( s=="" ) s = " ";
        cout << endl;
        switch ( s[0] )
        {
            case '1':
                db.ShowData();
                break;
            case '2':
                if ( db.AddEmployee() )
                    cout << "Employee succesfully added" << endl;
                else
                    cout << "Employee already exists in database - not added" << endl;
                break;
            case '3':
                if ( db.ModifyEmployee() )
                    cout << "Employee succesfully modified" << endl;
                else
                    cout << "Employee not found" << endl;
                break;
            case '4':
                if ( db.DeleteEmployee() )
                    cout << "Employee succesfully deleted" << endl;
                else
                    cout << "Employee not found" << endl;
                break;
            case '5':
                db.SortByName();
                break;
            case '6':
                cout << db.MaxSalary();
                break;
            case '7':
                db.FindPosition();
                break;
            case '8':
                db.RemoveSalaryAbove();
                break;
        }
    }
    while ( s[0]!='0' );

    return 0;
}
