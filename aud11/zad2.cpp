//
// Created by Stefan Andonov on 11.5.26.
//


#include<iostream>
#include<cctype>
#include<fstream>

using namespace std;

bool vowel(char c) {
    switch (tolower(c)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
    }
    return false;
}


int main() {

    ifstream fin("/Users/stefanandonov/CLionProjects/OOP_2026/aud11/primer.txt");
    ofstream fout ("/Users/stefanandonov/CLionProjects/OOP_2026/aud11/output.txt");

    char c;
    int counter = 0;
    int linesAbove10 = 0;

    //char by char
//    while (fin >> c){
////        cout << c << endl;
//        if (vowel(c)){
//            ++counter;
//        }
//    }

    //line by line
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
        int lineCounter = 0;
        for (int i = 0; i < line.size(); i++) {
            if (vowel(line[i])) {
                ++lineCounter;
            }
        }

        if (lineCounter>10){
            ++linesAbove10;
        }
        counter+=lineCounter;
    }

    fout << "Vkupno " << linesAbove10 << " reda imaat povekje od 10 samoglaski." << endl;
    fout << "Vo datotekata ima vkupno "<< counter << " samoglaski.";
    return 0;
}