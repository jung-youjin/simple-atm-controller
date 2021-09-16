#ifndef BANK_H
#define BANK_H

#include <vector>

using namespace std;

class Bank {
private:
    int account;
    int action;
    // int account[3];
    int pinNumber = 1234;
    struct Account {
        int balance;
    };
    vector<Account> Accounts;

public:
    Bank();
    ~Bank() {}
    void balance();
    void deposit();
    void withdraw();
    bool checkPin(int pin);
    void selectAccount(int acc);
    void selectAction(int act);
    // bool bankFlow(string input);
};

#endif