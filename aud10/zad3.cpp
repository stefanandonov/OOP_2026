//
// Created by Stefan Andonov on 6.5.26.
//


#include<iostream>
using namespace std;


class RoundPeg {
protected:
    double radius;
public:
    RoundPeg(double r) : radius(r){

    }

    virtual double getRadius() const {
        return radius;
    }
};

class SquarePeg {
protected:
    double side;
public:
    SquarePeg(double s) : side (s){

    }

    double getSide() const {
        return side;
    }
};


class RoundHole {
private:
    double radius;
public:
    RoundHole(double r) : radius(r){

    }

    bool fits (RoundPeg * roundPeg){
        return roundPeg->getRadius() <= this->radius;
    }


};

class SquarePegAdapter : public SquarePeg, public RoundPeg {
public:
    SquarePegAdapter(double s) : SquarePeg(s), RoundPeg(0) {}

    double getRadius() const override {
        return side * sqrt(2)/2.0;
    }
};

int main () {


    RoundHole hole (5);


    RoundPeg ** pegs = new RoundPeg * [6];

    pegs[0] = new RoundPeg(3);
    pegs[1] = new RoundPeg(5);
    pegs[2] = new RoundPeg(5.2);

    pegs[3] = new SquarePegAdapter(5);
    pegs[4] = new SquarePegAdapter(7);
    pegs[5] = new SquarePegAdapter(8);

    for (int i = 0; i < 6; ++i) {
        cout << hole.fits(pegs[i]) << endl;
    }

    return 0;
}