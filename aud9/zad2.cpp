//
// Created by Stefan Andonov on 29.4.26.
//


#include<iostream>
#include<cmath>
using namespace std;

class Shape { //interface
public:
    virtual void print () {
        cout << getType() <<" with area " << area() << " and volume " << volume() << endl;
    }
    virtual double area() = 0;
    virtual double volume() = 0;
    virtual string getType() = 0;
};

class Cube : public Shape {
private:
    double a;
public:
    Cube (double a) : Shape() {
        this->a = a;
    }

//    void print() override {
//        cout << "Cube with area " << area() << " and volume " << volume() << endl;
//    }

    double area() override {
        return 6*a*a;
    }

    double volume() override {
        return a*a*a;
    }

    string getType() override {
        return "Cube";
    }
};

class Cylinder: public Shape {
private:
    double radius;
    double height;
public:
    Cylinder (double radius, double height) : Shape() {
        this->radius = radius;
        this->height = height;
    }

//    void print() override {
//        cout << "Cylinder with area " << area() << " and volume " << volume() << endl;
//    }

    double area() override {
        return 2*radius*3.14*(height+radius);
    }

    double volume() override {
        return radius*radius*height*3.14;
    }

    string getType() override {
        return "Cylinder";
    }
};

class Cuboid : public Shape{
private:
    double a;
    double b;
    double c;
public:
    Cuboid(double a, double b, double c) : Shape() {
        this->a = a;
        this->b = b;
        this->c = c;
    }

//    void print() override {
//        cout << "Cuboid with area " << area() << " and volume " << volume() << endl;
//    }

    double area() override {
        return 2*a*b + 2*a*c + 2*b*c;
    }

    double volume() override {
        return a*b*c;
    }

    string getType() override {
        return "Cuboid";
    }
};


class Cone: public Shape {
private:
    double radius;
    double height;
public:
    Cone (double radius, double height) : Shape() {
        this->radius = radius;
        this->height = height;
    }

//    void print() override {
//        cout << "Cone with area " << area() << " and volume " << volume() << endl;
//    }

    double area() override {
        return 3.14*radius*(radius + sqrt(height*height + radius*radius));
    }

    double volume() override {
        return radius*radius*height*3.14/3;
    }

    string getType() override {
        return "Cone";
    }
};

void shapeWithMaxVolume (Shape ** shapes, int n){
    Shape * max = shapes[0];
    for (int i = 0; i < n; ++i) {
        if (shapes[i]->volume() > max->volume()){
            max = shapes[i];
        }
    }

    max->print();
}


int notCircleBasedShapes (Shape ** shapes, int n){
    int counter = 0;
    for (int i = 0; i < n; ++i) {
//        if (shapes[i] ti si cube ili ti si cuboid )
        if (dynamic_cast<Cube *>(shapes[i])!= nullptr || dynamic_cast<Cuboid *>(shapes[i])!= nullptr){
            ++counter;
        }
    }
    return counter;
}



int main () {

    int n;
    cin >> n;

    Shape ** shapes = new Shape * [n];

    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        //0 = cube, 1 = cylinder, 2 = cuboid, 3=cone
        if (type==0){ //cube
            double a;
            cin >> a;
            shapes[i] = new Cube(a);
        } else if (type==1){ //cylinder
            double radius, height;
            cin >> radius >> height;
            shapes[i] = new Cylinder(radius, height);
        } else if (type==2){ //cuboid
            double a,b,c;
            cin >> a >> b >> c;
            shapes[i] = new Cuboid(a,b,c);
        } else { //cone
            double radius, height;
            cin >> radius >> height;
            shapes[i] = new Cone(radius, height);
        }
    }

    for (int i = 0; i < n; ++i) {
        shapes[i]->print();

        Cube * cubePtr = dynamic_cast<Cube *>(shapes[i]);
        Cuboid * cuboidPtr = dynamic_cast<Cuboid *>(shapes[i]);
        Cone * conePtr = dynamic_cast<Cone *>(shapes[i]);
        Cylinder * cylinderPtr = dynamic_cast<Cylinder *>(shapes[i]);

//        cout << cubePtr << " " << cuboidPtr << " " << conePtr << " " << cylinderPtr << endl;
    }

    cout << "Shape with largest volume " << endl;
    shapeWithMaxVolume(shapes, n);

    cout << "Shapes with base different than circle: " << notCircleBasedShapes(shapes, n);

    return 0;
}