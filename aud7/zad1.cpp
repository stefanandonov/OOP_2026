//
// Created by Stefan Andonov on 15.4.26.
//


#include<iostream>

using namespace std;

class Student {
protected:
    int index;
    string firstName;
    string lastName;
    double average;
    int year;
public:
    Student(int index, const string &firstName, const string &lastName, double average, int year) : index(index),
                                                                                                    firstName(
                                                                                                            firstName),
                                                                                                    lastName(lastName),
                                                                                                    average(average),
                                                                                                    year(year) { }

    void print () {
        cout << "Student ID: " << this->index << " " << firstName << " " << lastName << " Average grade: " << average << " Year of studies: " << year;
    }
};

class Tutor : public Student {
private:
    int labsWeekly;
public:
    Tutor(int index, const string &firstName, const string &lastName, double average, int year, int labsWeekly)
            : Student(index, firstName, lastName, average, year) {
        //first five properties are sent to the Student constructor, we handle only the new ones (labsWeekly)
        this->labsWeekly = labsWeekly;
    }

    double capacity () {
        if (year == 3){
            return 100* labsWeekly / 4.0;
        } else {
            return 100 * labsWeekly / 6.0;
        }
    }

    void print() {
        cout << "Tutor ";
        Student::print();
        cout << " Labs weekly: " << this->labsWeekly << " Capacity: " << capacity();
    }
};

int main() {

    int index;
    string firstName;
    string lastName;
    double average;
    int year;

    cin >> index;
    cin.ignore();
    getline(cin, firstName);
    getline(cin, lastName);
    cin >> average >> year;

    Student regularStudent (index, firstName, lastName, average, year);

    regularStudent.print();
    cout << endl;


    int labsWeekly;
    cin >> index;
    cin.ignore();
    getline(cin, firstName);
    getline(cin, lastName);
    cin >> average >> year >> labsWeekly;

    Tutor tutor (index, firstName, lastName, average, year, labsWeekly);

    tutor.print();
    cout << endl;


    return 0;
}
