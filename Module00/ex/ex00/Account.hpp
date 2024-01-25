#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP


// Mandatory: It must be impossible to add money to a client account without going through the bank
#include <iostream>

class Bank;

class Account {
    public:
        const int& getMyID() const;
        const int& getMyLoan() const;
        const int& getMyValue() const;
    private:
        friend class Bank;
        Account(int accountID, int value);
        Account(const Account& other);
        ~Account();

        // void changeValue(int amountToChange);
        void addLoan(int loanGiven, int amountMoney);
        void payOffLoan(int amountToPayOff);
        int id;
        int value;
        int loan;
};

#endif