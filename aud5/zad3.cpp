#include <iostream>
#include <cstring>

using namespace std;

//TODO

class Book {
private:
    char name [50];
    int pages;
public:

    Book () {
        strcpy(this->name, "TEST BOOK");
        this->pages = 0;
    }
    Book (char * name, int pages){
        this->pages = pages;
        strcpy(this->name, name);
    }

    void readPages(int pages) {
        this->pages+=pages;
        if (this->pages>200){
            this->pages=200;
        }
    }

    void print() {
        cout << name << " - " << pages << "/200 - ";
        if (pages<100){
            cout << "IN PROGRESS" << endl;
        }
        if (pages>=100 && pages<200){
            cout << "ALMOST DONE" << endl;
        }
        if (pages>=200){
            cout << "FINISHED" << endl;
        }

    }
};

int main() {
    Book books[100];

    char name [50];
    int pages;

    //TODO read N books;
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> name >> pages;
        books[i] = Book(name, pages);

    }


    int idx;
    cin >> idx >> pages;

    books[idx].readPages(pages);

    for (int i = 0; i < N; i++) {
        books[i].print();
    }

    return 0;
}