#include "Bank.hpp"

Bank::Bank() {
    std::cout << "Bank constructor called" << std::endl;
    if (liquidity < 0)
        throw std::invalid_argument("Liquidity of Bank cannot be negative");
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


    // enlever le 5% et me le mettre
    // - Vérifier que la banque a assez pour donner amountToLoan
    // - Vérifier que: 1. le account
}