#ifndef ATM_H
#define ATM_H

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
    void exit();
};

#endif