//
// Created by Stefan Andonov on 4.3.26.
//

#include<iostream>

using namespace std;

enum POSITION {
    Regular, //0
    TeamLead, //1
    Manager, //2
    C_Level //3
};


class Employee {
private:
    char name[100];
    double salary;
    POSITION position;

public:
    Employee(char *_name = "NONAME", double _salary = 0, POSITION _position = Regular) {
        strcpy(name, _name);
        salary = _salary;
        position = _position;
    }

    void print() {
        cout << "Employee name: " << name << " Salary: " << salary << " Position: ";
        switch (position) {
            case Regular:
                cout << "Regular employee";
                break;
            case TeamLead:
                cout << "Team Lead";
                break;
            case Manager:
                cout << "Manager";
                break;
            default:
                cout << "Executive";
        }

        cout << endl;
    }

    double getSalary() {
        return salary;
    }

    void raiseSalary (int percent){
//        salary+=(5*salary/100);

        salary*=(1.0 + percent/100.0);
    }
};

int main() {

    Employee employees [100];

    int n;
    cin >> n;



    char name[100];
    double salary;
    int position;

    for (int i=0;i<n;i++){
        cin.ignore();
        cin.getline(name,100);
        cin >> salary >> position;

        employees[i] = Employee(name, salary, (POSITION) position);

    }

    //TODO sort them in descending order

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (employees[j].getSalary() < employees[j+1].getSalary()){
                swap(employees[j], employees[j+1]);
            }
        }
    }

    for (int i=0;i<n;i++){
        employees[i].print();
    }

    employees[n-1].raiseSalary(3);

    cout << "After increase to the lowest payed employee";
    for (int i=0;i<n;i++){
        employees[i].print();
    }



    return 0;
}