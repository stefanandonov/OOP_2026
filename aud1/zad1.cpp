//
// Created by Stefan Andonov on 25.2.26.
//

void swap (int & a, int & b){
    int tmp = a;
    a = b;
    b = tmp;
}


#include<iostream>
using namespace std;

int main () {

    int a=5,b=6;

    swap(a,b);

    cout << a << " " << b;

    //
    int day[100];
    int month[100];
    int year[100];

    Date dates[100];

}