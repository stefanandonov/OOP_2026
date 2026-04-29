//
// Created by Stefan Andonov on 29.4.26.
//


#include<iostream>
using namespace std;

class Animal {
protected:
    string name;
    string onboarded;
public:
    Animal(const string &name, const string &onboarded) : name(name), onboarded(onboarded) {}

    virtual string sound() = 0;//pure-virtual method => class is becoming abstract class
};

class Dog : public Animal {
public:
    Dog(const string &name, const string &onboarded) : Animal(name, onboarded) {}

    string sound() override {
        return "AF AF";
    }
};

class Cat: public Animal {
public:
    Cat(const string &name, const string &onboarded) : Animal(name, onboarded) {}

    string sound() override {
        return "MJAUUUU";
    }
};

int main () {

//    Animal a("tom", "2026-04-29");
//    Animal * a = new Animal("tom", "2026-04-29");
//    Cannot create objects of abstract class

    Animal ** animals = new Animal * [2];
    animals[0] = new Cat("Tom", "2026-04-29");
    animals[1] = new Dog ("Jacky", "2025-04-29");

    for (int i = 0; i < 2; ++i) {
        cout << i+1 << " " << animals[i]->sound() << endl;
    }

    delete [] animals;
    return 0;
}