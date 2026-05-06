//
// Created by Stefan Andonov on 6.5.26.
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
                                                                                                    year(year) {}

    void print() {
        cout << "Student ID: " << this->index << " " << firstName << " " << lastName << " Average grade: " << average
             << " Year of studies: " << year;
    }

    int getIndex() const {
        return index;
    }

    const string &getFirstName() const {
        return firstName;
    }

    const string &getLastName() const {
        return lastName;
    }

    double getAverage() const {
        return average;
    }

    int getYear() const {
        return year;
    }
};

enum TITLE {
    LAB_ASSISTANT,
    TR_ASSISTANT,
    ASSISTANT_PROFESSOR,
    ASSOCIATE_PROFESSOR,
    FULL_PROFESSOR,
};


class StaffMember {
protected:
    int lecturesWeekly;
    int tutorialsWeekly;
    int labsWeekly;

    static int HOURLY_RATE_LAB_ASSISTANT;
public:
    StaffMember(int lecturesWeekly, int tutorialsWeekly, int labsWeekly) : lecturesWeekly(lecturesWeekly),
                                                                                        tutorialsWeekly(
                                                                                                tutorialsWeekly),
                                                                                        labsWeekly(labsWeekly)
                                                                                        {}
    virtual double salary() = 0;

    virtual void print() {
        cout << "Labs:  " << labsWeekly << " weekly. Salary: " << salary();

    }

};

int StaffMember::HOURLY_RATE_LAB_ASSISTANT = 600;

class Tutor : public Student, public StaffMember {
public:
    Tutor(int index, const string &firstName, const string &lastName, double average, int year, int labsWeekly)
            : Student(index, firstName, lastName, average, year),
              StaffMember(0, 0, labsWeekly) {}

    double salary() override {
        return 10000 + (labsWeekly * 4 * HOURLY_RATE_LAB_ASSISTANT);
    }

    void print() override {
        cout << "Tutor -> ";
        StaffMember::print();
        cout << " ";
        Student::print();
        cout << endl;
    }
};

class Assistant : public StaffMember {
public:
    Assistant(int tutorialsWeekly, int labsWeekly) : StaffMember(0, tutorialsWeekly,
                                                                                     labsWeekly) {}

    double salary() override {
        return 30000 + (tutorialsWeekly * 4 * 500) + (labsWeekly * 4 * HOURLY_RATE_LAB_ASSISTANT);
    }

    void print() override {
        cout << "Teaching and research assistant ";
        cout << "Tutorials:  " << tutorialsWeekly << " weekly." << endl;
        StaffMember::print();
    }

};

int main() {

    StaffMember ** members = new StaffMember * [2];

    members[0] = new Tutor(151020, "Stefan", "Andonov", 9.3, 4, 6);
    members[1] = new Assistant(7, 8);

    for (int i = 0; i < 2; ++i) {
        members[i]->print();
        Student * s = dynamic_cast<Student *>(members[i]);
        if (s!=nullptr){
            cout << i << "-th member is also a student";
            cout << s->getIndex();
        }
        cout << endl << endl;
    }

    return 0;
}