#include "../lib/Bank.h"
#include <iostream>

using namespace std;

class Bank;

Bank::Bank() {
    Account saving, salary, checking;
    saving.balance = 59323;
    salary.balance = 6821;
    checking.balance = 1947;
    this->Accounts.push_back(saving);
    this->Accounts.push_back(salary);
    this->Accounts.push_back(checking);
}

void Bank::withdraw() {
    cout << "\n Current Balance: $" << this->Accounts[this->account-1].balance << endl;   
    cout << " Enter amount of cash to withdraw: $";
    int withdraw;
    cin >> withdraw;
    if (withdraw>this->Accounts[this->account-1].balance) {
        cout << " Limit Excess!" << endl;
    }
    else {
        this->Accounts[this->account-1].balance -= withdraw;
        cout << "\n Withdrawn: $" << withdraw << "\n" << " Balance left: $" << this->Accounts[this->account-1].balance << endl;   
    }
}

void Bank::balance() {
    cout << "\n Current Balance: $" << this->Accounts[this->account-1].balance << endl;
}

void Bank::deposit() {
    cout << "\n Current Balance: $" << this->Accounts[this->account-1].balance << endl;  
    cout << " Enter amount of cash to deposit: $";
    int deposit;
    cin >> deposit;

    this->Accounts[this->account-1].balance += deposit;
    cout << "\n Deposited: $" << deposit << "\n" << " Balance left: $" << this->Accounts[this->account-1].balance << endl;   
}

bool Bank::checkPin(int pin) {
     return (pin==pinNumber ? true : false);
}

void Bank::selectAccount(int acc) {
    this->account = acc;
    if (acc!=1 && acc!=2 && acc!=3) {
        cout << "\n Wrong Option!" << endl;
        cout << " Routing to default account [1]: Saving ... " << endl;
        this->account = 1;
    }
}

void Bank::selectAction(int act) {
    this->action = act;
    if(act==1) this->balance();
    else if(act==2) this->deposit();
    else if(act==3) this->withdraw();
    else {
        cout << "\n Wrong Option!" << endl;
        cout << " Exiting options selection ... " << endl;
    }
}