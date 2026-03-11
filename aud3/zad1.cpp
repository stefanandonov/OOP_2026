//
// Created by Stefan Andonov on 11.3.26.
//


#include<iostream>
#include<cstring>
using namespace std;

class Team {
private:
    char name [100];
    int year;
    char city [100];
public:
    Team(char * _name = "Vardar", char * _city = "Skopje", int _year = 2026) { //2in1
        strcpy(name, _name);
        strcpy(city, _city);
        year = _year;

    }

    void print () {
        cout << name << " - " << city << "(" << year << ")" << endl;
    }
};

class Game {
private:
    Team home;
    Team away;
    int homeGoals;
    int awayGoals;
public:
    Game (Team _home, Team _away, int _homeGoals = 0, int _awayGoals = 0){
        home = _home;
        away = _away;
        homeGoals = _homeGoals;
        awayGoals = _awayGoals;
    }

    void print () {
        cout << "Home: ";
        home.print();
        cout << "Away: ";
        away.print();
        cout << "Result --> " << homeGoals << ":" << awayGoals << endl;
    }

    void scoreHome (){
        homeGoals++;
    }

    void scoreAway () {
        awayGoals++;
    }

};

int main () {
    Team t1 ("Barca", "Barcelona", 1899);
    Team t2;
    Team t3 ("Tikvesh", "Kavadarci");
    Team t4 ("Rabotnicki");

    t1.print();
    t2.print();
    t3.print();
    t4.print();

    Game g1 (t1,t2);
    Game g2 (t1, t2, 2);
    Game g3 (t1, t2, 2, 3);

    g1.print();
    g2.print();
    g3.print();

    g1.scoreHome();
    g1.scoreHome();
    g1.scoreAway();

    g1.print();

    return 0;
}