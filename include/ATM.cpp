#include "../lib/ATM.h"
#include <iostream>

using namespace std;

class ATM;

ATM::ATM() {
    cout << "====================================" << endl;
    cout << "\tWelcome to Simple ATM!\t" << endl;
    cout << "====================================" << endl;
    insertCard();
}

void ATM::exit() {
    int exit;
    cout << "\n Thank you for visiting Simple ATM!" << endl;
    cout << " Exiting..." << endl;
}

void ATM::insertCard() {
    cout << "\n 1. Insert your card [Y/N]:";
    
	string input;
	cin >> input;

    if (input == "y" || input == "Y") {
        atmCard = true;
    }
    else {
        cout << "\n No card inserted!" << endl;
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