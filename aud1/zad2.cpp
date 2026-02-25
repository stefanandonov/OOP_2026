#include<iostream>
using namespace std;
//
// Created by Stefan Andonov on 25.2.26.
//

struct Date {
    int day;
    int month;
    int year;

    int compare (Date other){
        if (year == other.year) {
            if (month == other.month){
                if (day == other.day){
                    return 0;
                } else if (day < other.day){
                    return -1;
                } else {
                    return 1;
                }
            } else if (month < other.month){
                return -1;
            } else { //month > other.month
                return 1;
            }
        } else if (year < other.year){
            return -1;
        } else { //year > other.year
            return 1;
        }

    }


};

void readDate (Date & d){
    cin >> d.day >> d.month >> d.year;
}

void printDate (Date d){
    cout << d.day << "." << d.month << "." << d.year << endl;
}



int main () {
    Date d;
    Date d2;
    readDate(d);
    readDate(d2);
    printDate(d);
    printDate(d2);


    cout << d.compare(d2);

}