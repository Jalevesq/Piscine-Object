#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include "Account.hpp"

// Mandatory: • The attributes of the structures must not be modifiable from the outside
class Bank {
    public:
        Bank(int liquidity);
        Bank();
        ~Bank();
        int     createAccount();
        void    deleteAccount(int accountID);


        const int& getBankLiquidity() const;
        const int& getAccountValue(int accountID) const;
        const int& getAccountLoan(int accountID) const;

        // void transferMoney(int fromAccountID, int toAccountID, int amount);
        void giveLoan(int accountID, int amountToLoan);
        void payOffLoan(int accountID, int amountToPayOff);
    private:
        std::map<int, Account*> clientAccount; // Mandatory: Never have two identical IDs
        std::set<int> availableIDs;
        int liquidity;
        int nextID;

        Account& getAccount(int accountID) const;
        int generateID();

};

#endif