#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <vector>
#include <map>
#include "Account.hpp"

// Mandatory: • The attributes of the structures must not be modifiable from the outside
class Bank {
    public:
        Bank();
        ~Bank();
        // createAccount();
        // deleteAccount();
        // getAccount();
        // const int& getBankLiquidity();
        // void setNew¨BankLiquidity
        
        // addMoneyToAccount(); // Mandatory: The bank must receive 5% of each money inflow on client accounts
        // removeMoneyFromAccount();
        // giveLoanToAccount(); // Mandatory: The bank must be able to give a loan to a customer, within the limits of its funds
    private:
        std::map<int, std::vector<Account *> > clientAccount; // Mandatory: Never have two identical IDs
        int liquidity;
        //
};

#endif