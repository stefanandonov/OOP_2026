#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char id [7]; //static allocated 7 chars
    char * name; //dynamic allocated
    float averageGrade;
    int year;

    void copy (const Student & other){
        this->year = other.year;
        this->averageGrade = other.averageGrade;
        strcpy(this->id, other.id);
        this->name = new char [strlen(other.name)+1];
        strcpy(this->name, other.name);
    }
public:
    Student(char *id = "", char *name = "", float averageGrade = 5.0, int year = 1) {
        this->year = year;
        this->averageGrade = averageGrade;
        strcpy(this->id, id);
        this->name = new char [strlen(name)+1];
        strcpy(this->name, name);
    }

    ~Student() {
        delete [] name;
    }

    Student (const Student & other){
        copy(other);
    }

    Student & operator = (const Student & other){
        if (this!=&other){
            delete [] name;
            copy(other);
        }
        return *this;
    }


    friend ostream &operator<<(ostream &os, const Student &student) {
        os << "id: " << student.id << " name: " << student.name << " averageGrade: " << student.averageGrade
           << " year: " << student.year;
        return os;
    }

    friend istream & operator >> (istream & in, Student & s) {
        char id [7]; //static allocated 7 chars
        char name [50]; //dynamic allocated
        float averageGrade;
        int year;
        in.getline(id, 7);
        in.getline(name, 50);
        in >> averageGrade >> year;
        in.ignore();

        s = Student(id, name, averageGrade, year);
        return in;
    }

    Student & operator ++ (){
        ++year;
        return *this;
    }

    Student operator ++ (int){
        Student s (*this); //copy constructor
        ++year;
        return s;
    }

//    bool operator > (const Student & s) {
//        return averageGrade>s.averageGrade;
//    }

    bool operator<(const Student &rhs) const {
        return averageGrade < rhs.averageGrade;
    }

    bool operator>(const Student &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Student &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Student &rhs) const {
        return !(*this < rhs);
    }

    bool operator == (const Student & other) {
        return strcmp(this->id,other.id)==0;
    }

    friend class Group;


};

class Group {
private:
    char name [20];
    Student * students; //dynamic array of Students
    int count;

    void copy (const Group & other){
        strcpy(this->name, other.name);
        this->count = other.count;
//        strcpy(this->students, other.students); //NOOO
        students = new Student [count];
        for (int i = 0; i < count; ++i) {
            students[i]=other.students[i];
        }
    }
public:
    Group (char * name = "PIT1"){
        strcpy(this->name, name);
        this->count = 0;
        students = new Student [count];
    }

    ~Group() {
        delete [] students;
    }

    Group (const Group & other) {
        copy(other);
    }

    Group & operator = (const Group & other) {
        if (this!=&other){
            delete [] students;
            copy(other);
        }

        return *this;
    }

    friend ostream &operator<<(ostream &os, const Group &group) {
        os << "name: " << group.name << " Students: " << endl;
        for (int i = 0; i < group.count; ++i) {
            os << i+1 << ". " << group.students[i] << endl;
        }
        return os;
    }

    Group & operator += (const Student & s){
        for (int i = 0; i < count; ++i) {
            if (students[i] == s){
                return *this;
            }
        }

        Student * temp = new Student [count+1];
        for (int i = 0; i < count; ++i) {
            temp[i]=students[i];
        }
        temp[count]=s;
        count++;
        delete [] students;
        students = temp;
        return * this;
    }

    double operator [] (char * id){
        for (int i = 0; i < count; ++i) {
            if (strcmp(students[i].id,id)==0){
                return students[i].averageGrade;
            }
        }
        return 5.0;
    }

};



int main() {

//    Student s ("151020", "Stefan", 9.0, 3);
    Student s;
    cin >> s;
    Student s1;
    cin >> s1;

    Group g ("SIIS");

    g+=s;
    g+=s1;

    cout << g;

    cout << g["151020"];



//    cout << s << endl;
//    cout << s1 << endl;
//
//    cout << ++s << endl;
//
//    cout << s++ << endl;
//    cout << s << endl;


    cout << (s>s1);


    return 0;

}