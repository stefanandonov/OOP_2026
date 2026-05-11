//
// Created by Stefan Andonov on 15.4.26.
//


#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;

class NotValidAccountNumberException {
private:
    string invalidAccountNumber;
    string reason;
public:
    NotValidAccountNumberException(const string &ian, const string &r) : invalidAccountNumber(ian), reason (r) {}

    void showMessage() {
        cout << "The account number " << invalidAccountNumber << " is not valid because" << reason << endl;
    }
};

class OperationNotAllowedException {
private:
    string message;
public:
    explicit OperationNotAllowedException(const string &message) : message(message) {}

    void showMessage() {
        cout << message << endl;
    }
};

enum VendorType {
    FOOD_DELIVERY,
    TOBACCO,
    LIQUER,
    GROCERY,
    TAXI,
    GAS_STATION
};

enum Depositor {
    PRIVATE_CITIZEN,
    COMPANY,
    MINISTRY_OF_EDUCATION_AND_SCIENCE
};

class DebitAccount {
protected:
    string accountNumber;
    string fullName;
    float balance;
public:
    DebitAccount(const string &accountNumber, const string &fullName, double balance) : accountNumber(accountNumber),
                                                                                        fullName(fullName),
                                                                                        balance(balance) {

        if (accountNumber.size() != 15){
            throw NotValidAccountNumberException(accountNumber, "it doesn't have length of 15 chars");
        }

        for (int i=0;i<accountNumber.size();i++){
            if (!isdigit(accountNumber[i])){
                throw NotValidAccountNumberException(accountNumber, "one of the chars is not a digit");
            }
        }
    }


    friend ostream &operator<<(ostream &out, const DebitAccount &da) {
        return out << da.accountNumber << " " << da.fullName << " " << da.balance;
    }

    virtual void deposit(float amount, Depositor depositor) {
        balance += amount;
    }

    virtual void withdraw(float amount) {
        if (amount > balance) {
            throw OperationNotAllowedException("The user doesn't have sufficient amount to withdraw.");
        }
        balance-=amount;

//        if (balance >= amount) {
//            balance -= amount;
//        } else {
//            cout << "You don't have money!" << endl;
//        }
    }

    virtual void pay(float amount, VendorType vendor) {
        withdraw(amount);
    }
};

class StudentMealCard : public DebitAccount {
    static int WEEKLY_ALLOWANCE;
public:
    StudentMealCard(const string &accountNumber, const string &fullName) : DebitAccount(accountNumber,
                                                                                        fullName,
                                                                                        WEEKLY_ALLOWANCE) {}

    friend ostream &operator<<(ostream &out, const StudentMealCard &smc) {
        return out << "Student Meal Card " << DebitAccount(smc);
    }

    void deposit(float amount, Depositor depositor) {
        if (depositor == MINISTRY_OF_EDUCATION_AND_SCIENCE && amount <= WEEKLY_ALLOWANCE) {
            balance = amount; //Existing balance if not spent is wiped out.
        } else {
            cout << "This transaction is not allowed for this type of card" << endl;
        }
    }

    void withdraw(float amount) {
        cout << "This transaction is not allowed for this type of card" << endl;
    }

    void pay(float amount, VendorType vendor) {
        if (vendor == FOOD_DELIVERY || vendor == GROCERY) {
            if (amount <= balance) {
                balance -= amount;
            }
        } else {
            cout << "This transaction is not allowed for this type of card" << endl;
        }
    }
};

int StudentMealCard::WEEKLY_ALLOWANCE = 840;

int main() {


    try {
        DebitAccount *da = new DebitAccount("asdasd", "asdasd", 500);
        da->withdraw(800);
        cout << *da << endl;
    } catch (OperationNotAllowedException & e){
        e.showMessage();
    } catch (NotValidAccountNumberException & e){
        e.showMessage();
    }


    DebitAccount *a1 = new DebitAccount("100000000063095", "Budzet na RM", 16012);
    cout << *a1 << endl;


    try {
        DebitAccount *smc = new StudentMealCard("12312312112345A", "Stefan");

        cout << *smc << endl;

        cout << "\n--- Testing deposit from private citizen ---" << endl;
        smc->deposit(500, PRIVATE_CITIZEN);   // not allowed
        cout << *smc << endl;

        cout << "\n--- Testing deposit from company ---" << endl;
        smc->deposit(500, COMPANY);           // not allowed
        cout << *smc << endl;

        cout << "\n--- Testing valid deposit from ministry ---" << endl;
        smc->deposit(840, MINISTRY_OF_EDUCATION_AND_SCIENCE);   // allowed
        cout << *smc << endl;

        cout << "\n--- Testing invalid deposit above weekly allowance ---" << endl;
        smc->deposit(1000, MINISTRY_OF_EDUCATION_AND_SCIENCE);  // not allowed
        cout << *smc << endl;

        cout << "\n--- Testing withdraw ---" << endl;
        smc->withdraw(100);                   // not allowed
        cout << *smc << endl;

        cout << "\n--- Testing pay to FOOD_DELIVERY ---" << endl;
        smc->pay(200, FOOD_DELIVERY);         // allowed
        cout << *smc << endl;

        cout << "\n--- Testing pay to GROCERY ---" << endl;
        smc->pay(100, GROCERY);               // allowed
        cout << *smc << endl;

        cout << "\n--- Testing pay to TAXI ---" << endl;
        smc->pay(50, TAXI);                   // not allowed effectively
        cout << *smc << endl;

        cout << "\n--- Testing pay to TOBACCO ---" << endl;
        smc->pay(50, TOBACCO);                // not allowed effectively
        cout << *smc << endl;

        cout << "\n--- Testing pay with insufficient funds ---" << endl;
        smc->pay(1000, FOOD_DELIVERY);        // allowed vendor, but insufficient balance
        cout << *smc << endl;

    } catch (NotValidAccountNumberException & e){
        e.showMessage();
    }




    return 0;
}
