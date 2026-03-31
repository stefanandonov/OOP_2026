#include <iostream>
#include <cstring>

using namespace std;

//YOUR CODE HERE:

enum AccountType {
    PERSONAL,
    ENTITY
};

class Account {
private:
    char *name;
    AccountType type;
    double balance;
    int id;

    static int TOTAL_ACCOUNTS;
public:

    Account(){
        this->name = new char[3];
        strcpy(this->name, "KB");
        this->balance = 0;
        this->type = PERSONAL;
        this->id = 0;
    }
    Account(char *name, int type, double balance){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->balance = balance;
        this->type = (AccountType) type;

        TOTAL_ACCOUNTS++;
        this->id = 111110 + TOTAL_ACCOUNTS;
    }

    Account(const Account &other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->balance = other.balance;
        this->type = other.type;
        this->id = other.id;
    }

    Account &operator=(const Account &other) {
        if (this != &other) {
            delete[] name;
            this->name = new char[strlen(other.name) + 1];
            strcpy(this->name, other.name);
            this->balance = other.balance;
            this->type = other.type;
            this->id = other.id;
        }

        return *this;
    }

    ~Account() {
        delete[] name;
    }

    friend ostream &operator<<(ostream &out, const Account &a) {
        //32000
        out << a.id << " - " << a.name << " ";
        if (a.type == PERSONAL) {
            out << "person ";
        } else {
            out << "company ";
        }
        out << a.balance;
        return out;
    }

    Account & operator -= (double fee){
        balance-=fee;
        return *this;
    }

    char *getName() const;

    AccountType getType() const;

    double getBalance() const;

    int getId() const;

    static int getTotalAccounts();
};

int Account::TOTAL_ACCOUNTS = 0;

char *Account::getName() const {
    return name;
}

AccountType Account::getType() const {
    return type;
}

double Account::getBalance() const {
    return balance;
}

int Account::getId() const {
    return id;
}

int Account::getTotalAccounts() {
    return TOTAL_ACCOUNTS;
}

class Bank {
private:
    char name[20];
    Account * accounts;
    int n;

    void copy(const Bank & other){
        strcpy(this->name, other.name);
        this->n = other.n;
        this->accounts = new Account[this->n];
//        strcpy(this->accounts, other.accounts);
        for (int i = 0; i < n; ++i) {
            this->accounts[i] = other.accounts[i];
        }
    }
public:
    Bank (char * name = "Stefan's Bank"){
        strcpy(this->name, name);
        n = 0;
        accounts = new Account[0];
    }

    Bank (const Bank & other){
        copy(other);
    }

    Bank & operator = (const Bank & other){
        if (this!=&other){
            delete [] accounts;
            copy(other);
        }
        return *this;
    }

    ~Bank(){
        delete [] accounts;
    }

    Bank & operator += (const Account & a){
        for (int i = 0; i < n; ++i) {
            if (accounts[i].getId()==a.getId()){
                return *this;
            }
        }

        Account * tmp = new Account[n+1];
        for (int i = 0; i < n; ++i) {
            tmp[i]=accounts[i];
        }
        tmp[n++]=a;
        delete [] accounts;
        accounts = tmp;
        return *this;
    }

    friend ostream & operator << (ostream & out, const Bank & b) {
        out << b.name << endl;
        for (int i = 0; i < b.n; ++i) {
            out << b.accounts[i] << endl;
        }
        return out;
    }

    bool operator < (const Bank & other){
        return this->n < other.n;
    }

    void bankFee() {
        for (int i = 0; i < n; ++i) {
            if (accounts[i].getType()==PERSONAL){
                accounts[i]-=(accounts[i].getBalance()*0.008);
            } else {
                accounts[i]-=(accounts[i].getBalance()*0.015);
            }
        }
    }
};

Bank leastLiquid (Bank * banks, int n){
    Bank min = banks[0];
    for (int i = 0; i < n; ++i) {
        if (banks[i]<min){
            min = banks[i];
        }
    }
    return min;
}


int main() {
    int testCase;
    cin >> testCase;
    if (testCase == 0) {
        cout << "TESTING ACCOUNT CONSTRUCTOR" << endl;
        Account account1("Paul", 0, 32000);
        Account account2("Globex", 1, 500000);
        Account account3("Anna", 0, 8700);
        cout << "TEST PASSED" << endl;
    } else if (testCase == 1) {
        cout << "TESTING ACCOUNT OPERATOR <<" << endl;
        Account account1("Paul", 0, 32000);
        Account account2("Globex", 1, 500000);
        Account account3("Anna", 0, 8700);
        cout << account1 << endl;
        cout << account2 << endl;
        cout << account3 << endl;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 2) {
        cout << "TESTING ACCOUNT OPERATOR -=" << endl;
        Account account1("Paul", 0, 32000);
        Account account2("Globex Industries", 1, 500000);
        Account account3("Anna", 0, 8700);
        cout << account1 << endl;
        cout << account2<< endl;
        cout << account3<< endl;
        account1 -= 350;
        account2 -= 20000;
        account3 -= 500;
        cout << "===== DECREASE =====" << endl;
        cout << account1<< endl;
        cout << account2<< endl;
        cout << account3<< endl;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 3) {
        cout << "TESTING BANK CONSTRUCTOR and <<" << endl;
        Bank bank1("Capital One Bank");
        cout << bank1;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 4) {
        cout << "TESTING BANK OPERATOR += and <<" << endl;
        Account account1("Paul", 0, 32000);
        Account account2("Globex Industries", 1, 500000);
        Account account3("Anna", 0, 8700);
        Bank bank1("Capital One Bank");
        bank1 += account1;
        bank1 += account2;
        bank1 += account3;
        cout << bank1;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 5) {
        cout << "TESTING BANK OPERATOR += and <<" << endl;
        Account account1("Paul", 0, 32000);
        Account account2("Globex Industries", 1, 500000);
        Account account3("Anna", 0, 8700);
        Bank bank1("Capital One Bank");
        bank1 += account1;
        bank1 += account2;
        bank1 += account3;
        bank1 += account1;
        cout << bank1;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 6) {
        cout << "TESTING BANK COPY-CONSTRUCTOR and OPERATOR =" << endl;
        Account account1("Paul", 0, 32000);
        Account account2("Globex Industries", 1, 500000);
        Account account3("Anna", 0, 8700);
        Account account4("Umbrella Corporation", 1, 300000);
        Account account5("Theo", 0, 15500);
        Bank bank1("Capital One Bank");
        bank1 += account1;
        bank1 += account2;
        bank1 += account3;
        Bank bank2(bank1);
        Bank bank4;
        {
            Bank bank3("First National Bank");
            bank3 += account4;
            bank3 += account5;
            bank4 = bank3;
        }
        cout << bank2;
        cout << bank4;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 7) {
        cout << "TESTING BANK OPERATOR < " << endl;
        Account account1("Paul", 0, 32000);
        Account account2("Globex Industries", 1, 500000);
        Account account3("Anna", 0, 8700);
        Account account4("Umbrella Corporation", 1, 300000);
        Account account5("Theo", 0, 15500);
        Bank bank1("Capital One Bank");
        bank1 += account1;
        bank1 += account2;
        bank1 += account3;
        Bank bank3("First National Bank");
        bank3 += account4;
        bank3 += account5;
        if (bank1 < bank3) {
            cout << "TEST FAILED" << endl;
        } else {
            cout << "TEST PASSED" << endl;
        }
    } else if (testCase == 8) {
        cout << "TESTING METHOD bankFee()" << endl;
        char name[30], name1[30];
        int type, numberOfBanks, numberOfAccounts;
        float money;
        cin >> numberOfBanks;
        cin.ignore();
        Bank banks[10];
        for (int i = 0; i < numberOfBanks; i++) {
            cin.getline(name, 20);
            banks[i] = Bank(name);
            cin >> numberOfAccounts;
            cin.ignore();
            Account accounts[10];
            for (int j = 0; j < numberOfAccounts; j++) {
                cin >> name1 >> type >> money;
                cin.ignore();
                accounts[j] = Account(name1, type, money);
                banks[i] += accounts[j];
            }
        }
        for (int i = 0; i < numberOfBanks; i++) {
            cout << banks[i];
            cout << "FEE-PAID" << endl;
            banks[i].bankFee();
            cout << banks[i];
        }
    } else if (testCase == 9) {
        cout << "TESTING METHOD leastLiquid()" << endl;
        char name[30], name1[30];
        int type, numberOfBanks, numberOfAccounts;
        float money;
        cin >> numberOfBanks;
        cin.ignore();
        Bank banks[10];
        for (int i = 0; i < numberOfBanks; i++) {
            cin.getline(name, 20);
            banks[i] = Bank(name);
            cin >> numberOfAccounts;
            cin.ignore();
            Account accounts[10];
            for (int j = 0; j < numberOfAccounts; j++) {
                cin >> name1 >> type >> money;
                cin.ignore();
                accounts[j] = Account(name1, type, money);
                banks[i] += accounts[j];
            }
        }
        cout << leastLiquid(banks, numberOfBanks);
    }
    return 0;
}