//
// Created by Stefan Andonov on 4.3.26.
//

#include<iostream>
#include<cmath>

using namespace std;


class Triangle {
private:
    int a, b, c;
public:
//    constructor with arguments
//    Triangle(int  _a, int _b, int _c){
//        a = _a;
//        b = _b;
//        c = _c;
//    }

//    default constructor
//    Triangle(){
//        a=b=c=1;
//    }

    Triangle(int _a = 1, int _b = 1, int _c = 1) { //nes-cafe constructor 2in1
        a = _a;
        b = _b;
        c = _c;
    }

    void print() {
        cout << a << ", " << b << ", " << c << endl;
        for (int i = 0; i < a; ++i) {
            cout << "-";
        }
        cout << ";";

        for (int i = 0; i < b; ++i) {
            cout << "-";
        }
        cout << ";";

        for (int i = 0; i < c; ++i) {
            cout << "-";
        }
        cout << ";" << endl;
        cout << "Area: " << area() << endl;
    }

    double area() {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    ~Triangle() {

    }
};

int main() {

    Triangle t1(3, 4, 5);

    Triangle t2;

    t1.print();

    t2.print();

    return 0;
}