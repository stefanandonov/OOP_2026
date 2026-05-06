//
// Created by Stefan Andonov on 6.5.26.
//


#include<iostream>
using namespace std;

class Vehicle {
protected:
public:
    Vehicle() {
        cout << "Vehicle constructor called" << endl;
    }

    ~Vehicle() {
        cout << "Vehicle destructor called" << endl;
    }

    virtual double speed() = 0;

    virtual void print () = 0;

};

class Car : virtual public Vehicle {
public:
    Car() : Vehicle() {
        cout << "Car constructor called" << endl;
    }

    ~Car() {
        cout << "Car destructor called" << endl;
    }

    double speed() override {
        return 180;
    }

    void print() override {
        cout << "Car with speed: " << speed() << endl;
    }
};

class Jet : virtual public Vehicle {
public:
    Jet() : Vehicle() {
        cout << "Jet constructor called" << endl;
    }

    ~Jet() {
        cout << "Jet destructor called" << endl;
    }

    double speed() override {
        return 1000;
    }

    void print() override {
        cout << "Jet with speed: " << speed() << endl;
    }
};

class JetCar : public Jet, public Car {
public:
    JetCar() :  Jet(), Car() {
        cout << "JetCar constructor called" << endl;
    }

    ~JetCar() {
        cout << "JetCar destructor called" << endl;
    }

    double speed() override {
        return (Car::speed() + Jet::speed())/2.0;
    }

    void print () override{
        cout << "JetCar with speed: " << speed() << endl;
    }

};

int main () {

    Vehicle ** vehicles = new Vehicle * [3];

    vehicles[0] = new Jet();
    vehicles[1] = new Car();
    vehicles[2] = new JetCar();

    for (int i = 0; i < 3; ++i) {
        vehicles[i]->print();
    }


    return 0;
}