#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include "Account.hpp"

class Bank {
    public:
        Bank(int liquidity);
        Bank();
        ~Bank();
        int     createAccount();
        void    deleteAccount(int accountID);

        void addMoneyAccountBank(int accountID, int amountToAdd);
        void removeMoneyAccountBank(int accountID, int amountToRemove);

        void addMoneyAccountOutside(int accountID, int amountToAdd);

        const int& getBankLiquidity() const;
        const int& getAccountValue(int accountID) const;
        const int& getAccountLoan(int accountID) const;

        void giveLoan(int accountID, int amountToLoan);
        void payOffLoan(int accountID, int amountToPayOff);

        const Account& operator[](int index) const;
    private:
        std::map<int, Account*> clientAccount;
        std::set<int> availableIDs;
        int liquidity;
        int nextID;

        Account& getAccount(int accountID) const;
        int generateID();

};

#endif