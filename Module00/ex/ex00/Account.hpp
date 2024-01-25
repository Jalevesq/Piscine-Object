#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

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

        void addLoan(int loanGiven, int amountMoney);
        void payOffLoan(int amountToPayOff);
        void addMoney(int amountToAdd);
        void removeMoney(int amountToRemove);
        int id;
        int value;
        int loan;
};

#endif