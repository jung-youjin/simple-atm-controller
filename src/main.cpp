#include <iostream>
#include <vector>
#include <string>
#include "../lib/Bank.h"
#include "../lib/ATM.h"

using namespace std;

#define LOCK 5

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
                    atm.exit();
                    break;
                }
            }
        } while(count<LOCK || !bank.checkPin(pin));
        atm.exit();
    }
    return 0;
}
