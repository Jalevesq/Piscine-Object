#include "Bank.hpp"

Bank::Bank() {
    std::cout << "Bank constructor called" << std::endl;
    this->liquidity = 0;
    this->nextID = 0;
}

Bank::Bank(int liquidity) {
    std::cout << "Bank constructor called" << std::endl;
    if (liquidity < 0)
        throw std::invalid_argument("Liquidity of Bank cannot be negative");
    this->liquidity = liquidity;
    this->nextID = 0;
}

Bank::~Bank() {
    std::cout << "Bank destructor called" << std::endl;
    for (std::map<int, Account*>::iterator it = this->clientAccount.begin(); it != this->clientAccount.end(); it++)
        delete (*it).second;
}

int Bank::generateID() {
    if (this->availableIDs.empty()) {
        if (this->nextID >= std::numeric_limits<int>::max())
            throw std::runtime_error("No more available IDs");
        return (this->nextID++);
    }
    int id = *this->availableIDs.begin();
    this->availableIDs.erase(this->availableIDs.begin());
    return (id);
}

int Bank::createAccount() {
    int id = this->generateID();
    Account *newAccount = new Account(id, 0);
    this->clientAccount[id] = newAccount;
    return (id);
}

void Bank::deleteAccount(int accountID) {
    std::map<int, Account*>::iterator it = this->clientAccount.find(accountID);
    if (it != this->clientAccount.end()) {
        delete it->second;
        this->clientAccount.erase(it);
        this->availableIDs.insert(it->first);
        std::cout << "Client account " << it->first << " Deleted." << std::endl;
    } else
        std::cout << "Account " << accountID << " does not exist in this bank.";
}

Account& Bank::getAccount(int accountID) const {
    std::map<int, Account*>::const_iterator it = this->clientAccount.find(accountID);
    if (it != this->clientAccount.end())
        return (*it->second);
    throw std::runtime_error("Account with ID " + std::to_string(accountID) + " does not exist.");
}

const int& Bank::getBankLiquidity() const {
    return (this->liquidity);
}

const int& Bank::getAccountValue(int accountID) const {
    Account& account = this->getAccount(accountID);
    return account.getMyValue();
}

const int& Bank::getAccountLoan(int accountID) const {
    Account& account = this->getAccount(accountID);
    return account.getMyLoan();
}

void Bank::giveLoan(int accountID, int amountToLoan) {
    Account& account = this->getAccount(accountID);
    int accountMoney = account.getMyValue();
    int accountLoan = account.getMyLoan();
    try {
        if (amountToLoan < 0)
            throw std::runtime_error("Loan has to be a positive number");
        if (this->liquidity < amountToLoan)
            throw std::runtime_error("The bank has not enough money to loan");
        if (accountLoan + amountToLoan >= std::numeric_limits<int>::max())
            throw std::runtime_error("Loan addition exceeds maximum account loan limit.");
        if (accountMoney + amountToLoan >= std::numeric_limits<int>::max())
            throw std::runtime_error("Addition exceeds maximum account value limit.");
    } catch(std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return ;
    }

    int bankPercentage = (amountToLoan * 5) / 100;
    int realLoan = amountToLoan - bankPercentage;
    std::cout << "Loan: " << std::to_string(amountToLoan) << ", Bank percentage: " << std::to_string(bankPercentage) << ", Real loan: " << std::to_string(realLoan) << std::endl;
    account.addLoan(amountToLoan, realLoan);
    this->liquidity += bankPercentage;
    this->liquidity -= amountToLoan;

}

void Bank::payOffLoan(int accountID, int amountToPayOff) {
    Account& account = this->getAccount(accountID);
    int accountMoney = account.getMyValue();
    int accountLoan = account.getMyLoan();
    try {
        if (amountToPayOff <= 0)
            throw std::runtime_error("The amount to pay off needs to be positive.");
        if (amountToPayOff > accountLoan)
            throw std::runtime_error("You cannot pay more than you owe to the bank.");
        if (accountMoney < amountToPayOff)
            throw std::runtime_error("You don't have enough money in your account to pay this much.");
        if (this->liquidity + amountToPayOff >= std::numeric_limits<int>::max())
            throw std::runtime_error("STOP, BANK AS TOO MUCH MONEY - HELP");
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return;
    }


    this->liquidity += amountToPayOff;
    account.payOffLoan(amountToPayOff);
    std::cout << "pay offf: " << std::to_string(amountToPayOff) << std::endl;
}

void Bank::addMoneyToAccount(int accountID, int amountToAdd) {
    Account& account = this->getAccount(accountID);
    int accountMoney = account.getMyValue();
    try {
        if (amountToAdd <= 0)
            throw std::runtime_error("The amount to transfer must be positive.");
        if (amountToAdd > this->liquidity)
            throw std::runtime_error("The bank does not have enough money.");
        if (amountToAdd + accountMoney >= std::numeric_limits<int>::max())
            throw std::runtime_error("Addition exceeds maximum account value limit.");
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return;
    }

    int bankPercentage = (amountToAdd * 5) / 100;
    int realAdd = amountToAdd - bankPercentage;

    std::cout << "Adding " << realAdd << " to " << accountID << std::endl;
    this->liquidity -= (amountToAdd - bankPercentage);
    account.addMoney(realAdd);
}


void Bank::removeMoneyFromAccount(int accountID, int amountToRemove) {
    Account& account = this->getAccount(accountID);
    int accountMoney = account.getMyValue();
    try {
        if (amountToRemove <= 0)
            throw std::runtime_error("The amount to remove must be positive.");
        if (amountToRemove > accountMoney)
            throw std::runtime_error("The account does not have enough money.");
        if (amountToRemove + this->liquidity >= std::numeric_limits<int>::max())
            throw std::runtime_error("Can't remoce, bank as too much money.");
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return;
    }

    std::cout << "Removing " << amountToRemove << " from " << accountID << std::endl;
    this->liquidity += amountToRemove;
    account.removeMoney(amountToRemove);
}