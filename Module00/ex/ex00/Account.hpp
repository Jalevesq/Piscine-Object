#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP


// Mandatory: It must be impossible to add money to a client account without going through the bank
#include <iostream>

class Account {
    public:
        Account(int accountID);
        ~Account();
        const int& getMyID() const;
        const int& getMyLoan() const;
        const int& getMyValue() const;
    private:
        Account();
        int id;
        int value;
        int loan;
};

#endif