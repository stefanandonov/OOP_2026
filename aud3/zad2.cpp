//
// Created by Stefan Andonov on 11.3.26.
//


#include<iostream>
#include<cstring>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date (int _day = 11, int _month = 3, int _year = 2026){
        day = _day;
        month = _month;
        year = _year;
    }

    void print (){
        cout << day << "." << month << "." << year;
    }
};

class Employee {
private:
    char name [30];
    double salary;
    Date dob;
    Date startDate;
public:
    Employee(char * _name = "", double _salary = 0, Date _dob = Date(), Date _startDate = Date()){
        strcpy(name, _name);
        salary = _salary;
        dob = _dob;
        startDate = _startDate;
    }

    void print () {
        cout << "Employee: " << name << " Salary: " << salary;
        cout << " Date of birth: ";
        dob.print();
        cout << " Start date: ";
        startDate.print();
        cout << endl;
    }

    double getSalary() {
        return salary;
    }

    void increaseSalary () {
        salary+=2000;
    }
};

class Company {
private:
    char name [50];
    Employee employees [50];
    int totalEmployees;
public:

    Company (char *_name){ //
        strcpy(name, _name);
        totalEmployees = 0;

    }
    Company(char * _name, Employee _employees[], int _totalEmployees){
        strcpy(name, _name);
        totalEmployees = _totalEmployees;
        for (int i = 0; i < totalEmployees; ++i) {
            employees[i]=_employees[i];
        }
    }

    void addEmployee (Employee e){
        employees[totalEmployees++]=e;
//        totalEmployees++;
    }

    void print () {
        cout << name << endl;
//        cout << employees; WRONG
        for (int i = 0; i < totalEmployees; ++i) {
            cout << i+1 << ". ";
            employees[i].print();
        }
    }

    Employee & lowestPayedEmployee (){
        Employee & lowest = employees[0];
        for (int i = 0; i < totalEmployees; ++i) {
            if (employees[i].getSalary() < lowest.getSalary()){
                lowest = employees[i];
            }
        }
        return lowest;
    }

};

int main () {

//    Date stefansBirthday (8,1,1997);
//    Employee e1 ("Stefan", 30000, Date(1,1,1998));
//    Employee e2 ("Petko", 40000, Date(2,5,2000), Date(20,12,2020));
//
//    Company c ("FINKI Company");
//    c.print();
//    c.addEmployee(e1);
//    c.print();
//    c.addEmployee(e2);
//    c.print();

    char name [50];
    cin >> name;

    Company c (name);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
//        ("Petko", 40000, Date(2,5,2000), Date(20,12,2020))
        char name [30];
        double salary;
        int birthday;
        int birthmonth;
        int birthyear;
        int startday;
        int startmonth;
        int startyear;

        cin >> name >> salary >> birthday >> birthmonth >> birthyear >> startday >> startmonth >> startyear;
        Employee e (name, salary, Date(birthday, birthmonth, birthyear), Date(startday, startmonth, startyear));
        c.addEmployee(e);

    }

    c.print();

    cout << "Lowest paid employee: " << endl;
    c.lowestPayedEmployee().print();

    c.lowestPayedEmployee().increaseSalary();

    cout << "After salary increase" << endl;
    c.print();

    return 0;
}