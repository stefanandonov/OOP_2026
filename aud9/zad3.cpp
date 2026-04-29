//
// Created by Stefan Andonov on 29.4.26.
//

#include<iostream>

using namespace std;


class QuizAttempt {
protected:
    char id[7];
public:
    QuizAttempt(char *id = "") {
        strcpy(this->id, id);
    }

    virtual double score() = 0;

    virtual void print() = 0;

    bool operator >= (QuizAttempt & qa){
        return this->score() >= qa.score();
    }
};

class MCQuizAttempt : public QuizAttempt {
private:
    char correct[11];
    char answers[11];
public:
    MCQuizAttempt(char *id = "", char *correct = "AAAAAAAAAA", char *answer = "AAAAAAAAAA") : QuizAttempt(id) {
        strcpy(this->correct, correct);
        strcpy(this->answers, answer);
    }

    double score() override {
        double total = 0;
        for (int i = 0; i < 10; ++i) {
            if (correct[i] == answers[i]) {
                total += 1.0;
            } else {
                total -= 0.25;
            }
        }
        return total;
    }

    void print() override {
        for (int i = 0; i < 10; ++i) {
            cout << i + 1 << " Correct: " << correct[i] << " Answer: " << answers[i] << " Points: ";
            if (answers[i] == correct[i]) {
                cout << 1 << endl;
            } else {
                cout << -0.25 << endl;
            }
        }
        cout << "Total score: " << score();
    }
};


class TFQuizAttempt : public QuizAttempt {
private:
    bool correct[10];
    bool answers[10];
public:
    TFQuizAttempt(char *id = "", bool *correct = {}, bool *answers = {}) : QuizAttempt(id) {
        for (int i = 0; i < 10; ++i) {
            this->correct[i] = correct[i];
            this->answers[i] = answers[i];
        }
    }

    double score() override {
        double total = 0;
        for (int i = 0; i < 10; ++i) {
            if (correct[i] == answers[i]) {
                total += 1.0;
            } else {
                total -= 0.5;
            }
        }
        return total;
    }

    void print() override {
        for (int i = 0; i < 10; ++i) {
            cout << i + 1 << " Correct: " << (correct[i] ? "True" : "False") << " Answer: "
                 << (answers[i] ? "True" : "False") << " Points: ";
            if (answers[i] == correct[i]) {
                cout << 1 << endl;
            } else {
                cout << -0.5 << endl;
            }
        }
        cout << "Total score: " << score();
    }
};


//Starter code
QuizAttempt *readMCQuizAttempt() {
    char ID[7];
    char correct[11];
    char answers[11];

    cin >> ID >> correct >> answers;
    return new MCQuizAttempt(ID, correct, answers);
}

QuizAttempt *readTFQuizAttempt() {
    char ID[7];
    bool correct[10];
    bool answers[10];
    cin >> ID;
    for (int i = 0; i < 10; i++) {
        cin >> correct[i];
    }
    for (int i = 0; i < 10; i++) {
        cin >> answers[i];
    }

    return new TFQuizAttempt(ID, correct, answers);
}

int main() {
    int testCase;

    cin >> testCase;

    if (testCase == 1) {
        cout << "Test MCQuizAttempt" << endl;
        QuizAttempt *attempt = readMCQuizAttempt();
        cout << "Score: " << attempt->score() << endl;
        attempt->print();
    } else if (testCase == 2) {
        cout << "Test TFQuizAttempt" << endl;
        QuizAttempt *attempt = readTFQuizAttempt();
        cout << "Score: " << attempt->score() << endl;
        attempt->print();
    } else if (testCase == 3) {
        cout << "Test operator >=" << endl;
        int n;
        cin >> n;
        QuizAttempt **attempts = new QuizAttempt *[n];
        for (int i = 0; i < n; i++) {
            int type;
            cin >> type;
            if (type == 1) {
                attempts[i] = readMCQuizAttempt();
            } else {
                attempts[i] = readTFQuizAttempt();
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if ((*attempts[i]) >= (*attempts[j])) {
                        cout << i << " >= " << j << endl;
                    } else {
                        cout << i << " < " << j << endl;
                    }
                }
            }
        }
    } else {
        int n;
        cin >> n;
        QuizAttempt **attempts = new QuizAttempt *[n];
        for (int i = 0; i < n; i++) {
            int type;
            cin >> type;
            if (type == 1) {
                attempts[i] = readMCQuizAttempt();
            } else {
                attempts[i] = readTFQuizAttempt();
            }
            attempts[i]->print();
            cout << endl;
        }

//        cout << "Average score of passed students is: " << averagePointsOfPassedStudents(attempts, n) << endl;
    }

    return 0;
}