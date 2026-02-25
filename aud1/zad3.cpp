
//
// Created by Stefan Andonov on 25.2.26.
//
#include<iostream>

using namespace std;


struct Student {
    int index;
    char name[100];
//    int p1,p2,p3,p4; //TODO change with array of integer
    int points[20];
    int tasks;

    int totalPoints() {
        int sum = 0;
        for (int i = 0; i < tasks; ++i) {
            sum += points[i];
        }
        return sum;
    }
};

void readStudent(Student &s) {
    cin >> s.index;
    cin.ignore();
    cin.getline(s.name, 100);
//    cin >> s.p1 >> s.p2 >> s.p3 >> s.p4;
    cin >> s.tasks;
    for (int i = 0; i < s.tasks; ++i) {
        cin >> s.points[i];
    }
}

void printStudent(Student s) {
    cout << s.index << "(" << s.name << ") Total points: " << s.totalPoints() << endl;
}

int main() {

    Student students[100];

    int n;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        readStudent(students[i]);
    }

    //TODO sort students in descending order by totalPoint

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].totalPoints() < students[j+1].totalPoints()){
                swap(students[j], students[j+1]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printStudent(students[i]);
    }


}