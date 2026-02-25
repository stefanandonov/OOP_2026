
//
// Created by Stefan Andonov on 25.2.26.
//


#include<iostream>
using namespace std;

struct President {
    char name [100];
    char politicalParty [100];
    int yearElected;
};

void readPresident (President & p){
    cin.getline(p.name, 100);
    cin.getline(p.politicalParty, 100);
    cin >> p.yearElected;
}

void printPresident (President p){
    cout << p.name << " (" << p.politicalParty << ") - Elected in: " << p.yearElected << endl;
}

struct City {
    char name[100];
    int population;
};


void readCity (City &c){
    cin.getline(c.name,100);
    cin >> c.population;
}

void printCity (City c){
    cout << c.name << " (" << c.population << ")" << endl;
}

struct Country {
    char name [100];
    int population;
    City capitalCity; //composition of City
    President president; //composition of President
};

void readCountry (Country & c){
    cin.getline(c.name, 100);
    cin >> c.population;
    cin.ignore();
    readCity(c.capitalCity);
    cin.ignore();
    readPresident(c.president);
}

void printCountry (Country c){
    cout << "Country: " << c.name << " Population: " << c.population << endl;
    cout << "Capital city: ";
    printCity(c.capitalCity);
    cout << "President: ";
    printPresident(c.president);
}

int main () {
//    President p;
//    readPresident(p);
//    printPresident(p);

//    Country c;
//    readCountry(c);
//    printCountry(c);

    Country countries[100];

    int n;
    cin >> n;

    cin.ignore();

    for (int i = 0; i < n; ++i) {
        readCountry(countries[i]);
        cin.ignore();
    }

    for (int i = 0; i < n; ++i) {
        printCountry(countries[i]);
    }

}