//
// Created by Stefan Andonov on 25.3.26.
//


#include<iostream>
using namespace std;


class Array {
private:
    int * content;
    int n;
    int capacity;

    void copy (const Array & other){
        this->capacity = other.capacity;
        this->n = other.n;
        this->content = new int [capacity];
        for (int i = 0; i < n; ++i) {
            this->content[i] = other.content[i];
        }
    }
public:
    Array() {
        n=0;
        capacity=5;
        content = new int [capacity];
    }

    Array (int capacity){
        n=0;
        this->capacity=capacity;
        content = new int [capacity];
    }

    Array (const Array & other){
        copy(other);
    }


//    assign()
    Array & operator = (const Array & other){
        if (this!=&other){
            delete [] content;
            copy (other);
        }
        return *this;
    }

    ~Array() {
        delete [] content;
    }

    Array & operator += (int number){
        if (n==capacity) {
            int * temp = new int [2*capacity];
            for (int i = 0; i < n; ++i) {
                temp[i]=this->content[i];
            }
            delete [] content;
            this->content = temp;
            capacity*=2;
        }

        content[n]=number;
        n++;

        return *this;
    }

    friend ostream & operator << (ostream & out, const Array & a){
        out << "Array with capacity: " << a.capacity << endl;
        out << "Elements: " << a.n << endl;
        for (int i = 0; i < a.n; ++i) {
            out << a.content[i] << " ";
        }
        return out;
    }

    int & operator [] (int idx) const{
        return content[idx];
    }

    bool operator == (const Array & a){
        if (this->n!=a.n){
            return false;
        }

        for (int i = 0; i < n; ++i) {
            if (this->content[i]!=a.content[i]){
                return false;
            }
        }

        return true;
    }

    Array & operator -= (int number){
        //TODO homework
        //reduce capacity if n gets reduced to capacity/2
        int * tmp = new int [capacity];
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (content[i]!=number){
                tmp[j++]=content[i];
            }
        }
        n=j;
        delete [] content;
        content = tmp;

        return *this;
    }




};

int main () {

//    Array a; //default -constructor
////
////    a+=1;
//    Array a1(100); //constructor with argument
////
//    Array a2 (a1); //copy constructor
//    Array a3 = a2; //copy constructor;
////
//    a3 = a; //operator = (assignment)
//
////    a3=a3;
//
//    int x=1;
//    cout << (x+=6);
//
//    cout << x << " " << x+1 << "  ";

    cout << 5;

    Array a (10);
    for (int i = 0; i < 25; ++i) {
        a += (i+1);
        cout << a << endl;
    }


    a[8]=5000;

//    a.getContent()[8];

    cout << a << endl;


    Array a2 = a;

    cout << (a2 == a) << endl;

    a2[7]=-5;

    cout << (a2 == a);

    return 0;
}