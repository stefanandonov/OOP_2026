//
// Created by Stefan Andonov on 18.3.26.
//


#include<iostream>

using namespace std;

class Book {
private:
    char name [100];
    char author [100];
    bool available;
public:
    Book(char *name = "", char *author = "", bool available = false) :available(available) {
        strcpy(this->name, name);
        strcpy(this->author, author);
    }

    void print () {
        cout << name << " (" << author << ")" << (available ? "AVAILABLE" : "NOT AVAILABLE") << endl;
    }

};

class Library {
private:
    char name [100];
    Book books[100];
    int n;

public:
    Library (char * name = "", Book * books = {}, int n = 0){
        strcpy(this->name, name);
        this->n = n;
        for (int i = 0; i < n; ++i) {
            this->books[i] = books[i];
        }
    }

    void addBook (Book & b){
        books[n]=b;
        n++;
    }

    void print () {
        cout << name << endl;
        for (int i = 0; i < n; ++i) {
            books[i].print();
        }
    }

};

int main () {

    char libraryName[100];
    int n;

    cin.getline(libraryName, 100); // library name
    cin >> n; // number of books
    cin.ignore();

    Library library(libraryName);

    for (int i = 0; i < n; ++i) {
        char name[100];
        char author[100];
        bool available;

        cin.getline(name, 100);
        cin.getline(author, 100);
        cin >> available;
        cin.ignore();

        Book b(name, author, available);
        library.addBook(b);
    }

    library.print();

    return 0;
}
