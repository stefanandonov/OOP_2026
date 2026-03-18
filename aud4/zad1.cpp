#include<iostream>
#include<cstring>

using namespace std;

class Team {
private:
    char name[100];
    int year;
    char city[100];
public:
//    Team(char * name = "Vardar", char * city = "Skopje", int year = 2026) { //2in1
//        strcpy(this->name, name);
//        strcpy(this->city, city);
//        this->year = year;
//
//    }

    Team(char *name = "Vardar", char *city = "Skopje", int year = 2026) {
        strcpy(this->name, name);
        strcpy(this->city, city);
        this->year = year;
    }

    Team(const Team &other) {
        cout << "Team copy constructor invoked!" << endl;
        strcpy(this->name, other.name);
        strcpy(this->city, other.city);
        this->year = other.year;
    }

    void print() {
        cout << name << " - " << city << "(" << year << ")" << endl;
    }

    bool equals(const Team &other) const {
        return strcmp(this->name, other.name)==0 && strcmp(this->city, other.city)==0 && this->year == other.year;
    }
};

class Game {
private:
    Team home;
    Team away;
    int homeGoals;
    int awayGoals;
public:
//    Game(Team home, Team away, int homeGoals = 0, int awayGoals = 0) {
//        this->home = home;
//        this->away = away;
//        this->homeGoals = homeGoals;
//        this->awayGoals = awayGoals;
//    }

    Game(const Team &home, const Team &away, int homeGoals = 0, int awayGoals = 0) {
        this->home = home;
        this->away = away;
        this->homeGoals = homeGoals;
        this->awayGoals = awayGoals;
    }

    void print() {
        cout << "Home: ";
        home.print();
        cout << "Away: ";
        away.print();
        cout << "Result --> " << homeGoals << ":" << awayGoals << endl;
    }

    void scoreHome() {
        homeGoals++;
    }

    void scoreAway() {
        awayGoals++;
    }

    const Team &getHome() const {
        return home;
    }

    const Team &getAway() const {
        return away;
    }

};

bool rematch(Game & g1, Game & g2) {
    return g1.getHome().equals(g2.getAway()) && g1.getAway().equals(g2.getHome());
}

int main() {
    Team t1("Barca", "Barcelona", 1899);
    Team t2;
    Team t3("Tikvesh", "Kavadarci");
    Team t4("Rabotnicki");
    Team t5 = t1; //explicit copy-constructor
    Team t6(t3); //explicit copy-constructor

    cout << t5.equals(t1) << endl;
    cout << t6.equals(t3) << endl;

    t1.print();
    t2.print();
    t3.print();
    t4.print();
    t5.print();
    t6.print();

    Game g1(t1, t2);
    Game g2(t2, t1, 2);
//    Game g3(t1, t2, 2, 3);
//
    g1.print();
    g2.print();
//    g3.print();
//
    g1.scoreHome();
    g1.scoreHome();
    g1.scoreAway();

    g1.print();

    cout << rematch(g1,g2);

    return 0;
}