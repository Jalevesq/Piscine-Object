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

        // void addLiquidity(int amountToAdd);
        // void removeLiquidity(int amountToRemove);
        // void addMoneyToAccount(int accountID, int amountToAdd); // Mandatory: The bank must receive 5% of each money inflow on client accounts
        // void removeMoneyFromAccount(int accountID, int amountToRemove);
        // void giveLoan(int accountID, int amountToLoan);
        // void payOffLoan(int accountID, int amountToPayOff);
    private:
        std::map<int, Account*> clientAccount; // Mandatory: Never have two identical IDs
        int liquidity;

        std::set<int> availableIDs;
        int generateID();

        int nextID;
};

#endif