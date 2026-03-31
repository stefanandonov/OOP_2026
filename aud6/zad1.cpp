//
// Created by Stefan Andonov on 30.3.26.
//

#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;


class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int day = 1, int month = 1, int year = 2014) : day(day), month(month), year(year) {}

    friend ostream & operator << (ostream & out, const Date & d) {
        out << setfill('0') << setw(2) << d.day << "/" << setfill('0') << setw(2) << d.month << "/" << d.year;
        return out;
    }

    bool isAfter (Date & other) const {
        if (year > other.year){
            return true;
        } else if (year < other.year) {
            return false;
        } else {
            if (month > other.month){
                return true;
            } else if (month < other.month){
                return false;
            } else { //year==year && month == month
                if (day > other.day){
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
};

class Call {
private:
    Date date;
    char calling[11];
    char called[11];
    int duration;
public:
    Call(const Date &date = Date(), char *calling = "070000000", char *called = "070000000", int duration = 0) : date(date),
                                                                        duration(duration) {
        strcpy(this->calling, calling);
        strcpy(this->called, called);
    }

    friend ostream & operator << (ostream & out, const Call & c){
        // 10
        out << c.date << " " << c.calling << " " << c.called << " " << c.duration;
        return out;
    }

    const Date &getDate() const {
        return date;
    }

    const char *getCalling() const {
        return calling;
    }

    const char *getCalled() const {
        return called;
    }

    int getDuration() const {
        return duration;
    }

//    friend void filterCallsAfterDate (Call * calls, int n, Date after);
};

void filterCallsAfterDate (Call * calls, int n, Date & after) {
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        if (calls[i].getDuration() < 600 && calls[i].getDate().isAfter(after)){
            cout << calls[i] << endl;
            ++counter;
        }
    }

    if (counter==0){
        cout << "No calls satisfy the given condition.";
    }
}


int main () {
    int n;
    cin >> n;

    Call calls[100];

    int day;
    int month;
    int year;
    char calling[11];
    char called[11];
    int duration;

    for (int i = 0; i < n; ++i) {
        cin >> day >> month >> year >> calling >> called >> duration;
        Date d (day, month, year);
        calls[i] = Call(d,calling,called,duration);
    }

    cin >> day >> month >> year;

    Date filtering (day, month, year);

    filterCallsAfterDate(calls, n, filtering);



    return 0;
}
