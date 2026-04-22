//
// Created by Stefan Andonov on 22.4.26.
//

#include<iostream>
using namespace std;

class HotelReservation {
protected:
    string name;
    int day;
    int people;

    static float PRICE_PER_PERSON_PER_DAY;
public:
    HotelReservation(const string &name = "", int day = 1, int people = 1) : name(name), day(day), people(people) {}

    virtual float price (){
        return day * people * PRICE_PER_PERSON_PER_DAY;
    }

    virtual void print () {
        cout << "Hotel Reservation for " << day << " nights for " << people << " people. Price: " << price() << endl;
    }
};

float HotelReservation::PRICE_PER_PERSON_PER_DAY = 25.0;

class HalfBoardHotelReservation : public HotelReservation {
private:
    static float BREAKFAST_PRICE;
public:
    HalfBoardHotelReservation(const string &name, int day, int people) : HotelReservation(name, day, people) {

    }

    float price() {
        return HotelReservation::price() + (day * people * BREAKFAST_PRICE);
    }

    void print() {
        cout << "Half Board ";
        HotelReservation::print();
    }
};

float HalfBoardHotelReservation::BREAKFAST_PRICE = 5.0;


class Hotel {
private:
    string name;
    HotelReservation ** reservations;
    int n;
public:
    Hotel (const string & name){
        this->name = name;
        reservations = new HotelReservation * [0];
        n = 0;
    }

    Hotel & operator += (HotelReservation * hr){
        HotelReservation ** temp = new HotelReservation * [n+1];
        for (int i = 0; i < n; ++i) {
            temp[i] = reservations[i];
        }
        delete [] reservations;
        reservations = temp;
        reservations[n++]=hr;
        return *this;
    }

    void print () {
        cout << name << endl;
        for (int i = 0; i < n; ++i) {
            reservations[i]->print();
        }
    }

    HotelReservation * mostExpensiveReservation (){
        HotelReservation * max = reservations[0];
        for (int i = 0; i < n; ++i) {
            if (reservations[i]->price() > max->price()){
                max = reservations[i];
            }
        }
        return max;
    }

};

void mostExpensiveReservation(HotelReservation ** reservations, int n){

}

int main () {

    int n;
    string name;
    int day;
    int people;
    int type;
    cin >> n;

    Hotel h ("FINKI's hotel");

    for (int i = 0; i < n; ++i) {

        cin >> type;
        //type == 1 hotelreservation; type == 2 halfboard;
        cin.ignore();
        getline(cin, name);
        cin >> day >> people;

        HotelReservation * hr;

        if (type==1){
            hr = new HotelReservation(name, day, people);
        } else {
            hr = new HalfBoardHotelReservation(name, day, people);
        }

//        hr->print();
        h+=hr;


    }

    h.print();

    cout << "Most expensive reservation in hotel is:" << endl;
    h.mostExpensiveReservation()->print();

    return 0;
}
