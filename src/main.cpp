#include <iostream>
#include <vector>
#include <list>
#include <string>
// #include "lib/Bank.h"
// #include "lib/ATM.h"

using namespace std;

#define LOCK 5

class ATM {
private:
    int atm;

public:
    ATM();
    ~ATM() {}
    bool atmCard;
    void insertCard();
    void pinNumber();
    void selectAccount();
    void selectAction();
};

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

void exit() {
    int exit;
    cout << "\n Thank you for visiting Simple ATM!" << endl;
    cout << " Exiting..." << endl;
}

ATM::ATM() {
    cout << "====================================" << endl;
    cout << "\tWelcome to Simple ATM!\t" << endl;
    cout << "====================================" << endl;
    insertCard();
}

void ATM::insertCard() {
    cout << "\n 1. Insert your card [Y/N]:";
    
	string input;
	cin >> input;

    if (input == "y" || input == "Y") {
        atmCard = true;
    }
    else {
        exit();
        atmCard = false;
    }
}

void ATM::pinNumber() {
    cout << "\n 2. Enter your Bank Card's PIN number: ";
}

void ATM::selectAccount() {
    cout << "\n 3. Select Account to proceed: " << endl;
    cout << "\t [1]: Saving" << endl;
    cout << "\t [2]: Salary" << endl;
    cout << "\t [3]: Checking \n" << endl;
    cout << "=> ";
}

void ATM::selectAction() {
    cout << "\n 4. Select Option to proceed: " << endl;
    cout << "\t [1]: See Balance" << endl;
    cout << "\t [2]: Deposit" << endl;
    cout << "\t [3]: Withdraw" << endl;
    cout << "=> ";
}

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
    cout << " Enter amount of cash to withdraw: ";
    int withdraw;
    cin >> withdraw;
    if (withdraw>this->Accounts[this->account-1].balance) {
        cout << " Limit Excess!" << endl;
    }
    else {
        this->Accounts[this->account-1].balance -= withdraw;
        cout << "\n Withdrawn: $" << withdraw << "\n" << "Balance left: $" << this->Accounts[this->account-1].balance << endl;   
    }
}

void Bank::balance() {
    cout << "\n Current Balance: $" << this->Accounts[this->account-1].balance << endl;
}

void Bank::deposit() {
    cout << "\n Current Balance: $" << this->Accounts[this->account-1].balance << endl;  
    cout << " Enter amount of cash to deposit: ";
    int deposit;
    cin >> deposit;

    this->Accounts[this->account-1].balance += deposit;
    cout << "\n Deposited: $" << deposit << "\n" << "Balance left: $" << this->Accounts[this->account-1].balance << endl;   
}

bool Bank::checkPin(int pin) {
     return (pin==pinNumber ? true : false);
}

void Bank::selectAccount(int acc) {
    this->account = acc;
}

void Bank::selectAction(int act) {
    this->action = act;
    if(act==1) this->balance();
    else if(act==2) this->deposit();
    else if(act==3) this->withdraw();
}

int main() {
    ATM atm;
    int count = 1;

	if (atm.atmCard) {	    
		atm.pinNumber();
        Bank bank;
    	int pin;
    	do {
        	cin >> pin;
            if (bank.checkPin(pin)) {
                int acc, act;
                atm.selectAccount();
                cin >> acc;
                bank.selectAccount(acc);
                atm.selectAction();
                cin >> act;
                bank.selectAction(act);
                break;
            }  

            else {
                cout << "Invalid PIN number. Please try again. Number of re-trials left till Account-LOCK: " << LOCK - count << endl;
                count++;
                atm.pinNumber();
                if (count == LOCK) {
                    cout << "Account-LOCKed due to invalid PIN number retrial numbers." << endl;
                    exit();
                    break;
                }
            }
    	} while(count<LOCK || !bank.checkPin(pin));
	}
    
    exit();
    return 0;
}
