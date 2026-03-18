//
// Created by Stefan Andonov on 18.3.26.
//


#include<iostream>

using namespace std;


class Student {
private:
    int idx;
    float average;
    static int COUNT;
    static float SUM_OF_AVERAGES;

public:

    Student () {
        this->idx = 250001;
        this->average = 6.0;
    }
    Student(float average):  average(average) {
        Student::COUNT++;
        this->idx = 250000 + COUNT;
        Student::SUM_OF_AVERAGES+=average;
    }

    int getIdx() const {
        return idx;
    }

    float getAverage() const {
        return average;
    }

    void print () {
        cout << idx << ": " << average << " Total students so far: " << COUNT << endl;
    }

    static float getStudentsAverageGrade() {
        return SUM_OF_AVERAGES / COUNT;
    }
};

int Student::COUNT = 0;
float Student::SUM_OF_AVERAGES = 0.0;


int main () {

    int n;
    cin >> n;

    Student students[100];

    for (int i = 0; i < n; ++i) {
        float average;
        cin >> average;

        students[i] = Student(average);
        students[i].print();
    }

    for (int i = 0; i < n; ++i) {
        students[i].print();
    }

    cout << Student::getStudentsAverageGrade();

    return 0;
}