//
// Created by Stefan Andonov on 11.5.26.
//


#include<iostream>
#include<fstream>

using namespace std;

class NoProductFoundException {
private:
    string category;
public:
    NoProductFoundException(string c) : category(c) {}

    void showMessage() {
        cout << "No products from category " << category << " were found in the store";
    }
};

class Product {
private:
    string name;
    string category;
    int price;
    int quantity;
public:
    Product(const string &name = "", const string &category = "", int price = 0, int quantity = 0) : name(name),
                                                                                                     category(category),
                                                                                                     price(price),
                                                                                                     quantity(
                                                                                                             quantity) {}


    friend ostream &operator<<(ostream &out, const Product &p) {
        //Coca-cola zero 1.75L (drinks) 100 x 80 = 8000
        return out << p.name << " (" << p.category << ") " << p.quantity << " x " << p.price << " = "
                   << p.quantity * p.price;
    }

    int totalPrice() {
        return price * quantity;
    }

    friend class Store;
};

class Store {
private:
    Product products[100];
    int n;
public:
    Store() {
        n = 0;
    }

    Store &operator+=(Product &p) {
        products[n++] = p;
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Store &s) {
        for (int i = 0; i < s.n; ++i) {
            out << s.products[i] << endl;
        }
        return out;
    }

    Store fromCategory(string &category) {

        Store result;

        for (int i = 0; i < n; ++i) {
            if (products[i].category == category) {
                result += products[i];
            }
        }

        if (result.n == 0) {
            throw NoProductFoundException(category);
        }

        return result;
    }
};


void wtf() {
    ofstream fout("input.txt");
    string line;
    while (getline(std::cin, line)) {
        if (line == "----") {
            break;
        }
        fout << line << endl;
    }
}

void rff(string path) {
    ifstream fin(path);
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}


int main() {

    wtf();


    Store s;

    //TODO your code starts here
    //TODO Read the products from the file and add them in the store `s`

    ifstream fin("input.txt");
    string name;
    string c;
    int price;
    int quantity;
    while (true) {
        getline(fin, name);
        getline(fin, c);
        fin >> price >> quantity;
        fin.ignore();
        if (fin.eof()) {
            break;
        }
        Product p(name, c, price, quantity);
//        cout << p << endl;
        s += p;
    }

    ofstream fout1("output1.txt");

    fout1 << s;


    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT

    string category;
    cin >> category;

    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT


    ofstream fout2("output2.txt");
    //TODO Save the results in the files output1.txt and output2.txt after this line
//    Store result = s.fromCategory(category);
//    fout2 << result;

    try{
        fout2 << s.fromCategory(category);
    } catch (NoProductFoundException & e){
        e.showMessage();
    }

    //DO NOT MODIFY THE CODE BELLOW

    cout << "All products:" << endl;
    rff("output1.txt");
    cout << "Products from category " << category << ": " << endl;
    rff("output2.txt");


    return 0;
}