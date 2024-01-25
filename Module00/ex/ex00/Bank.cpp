#include "Bank.hpp"

Bank::Bank() {
    std::cout << "Bank construct or called" << std::endl;
    if (liquidity < 0)
        throw std::invalid_argument("Liquidity of Bank cannot be negative");
    this->liquidity = 0;
    this->nextID = 0;
}

Bank::Bank(int liquidity) {
    std::cout << "Bank construct or called" << std::endl;
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

int Bank::createAccount() {
    int id = this->generateID();
    this->clientAccount[id] = new Account(id);
    return (id);
}

void Bank::deleteAccount(int accountID) {
    std::map<int, Account*>::iterator it = this->clientAccount.find(accountID);
    if (it != this->clientAccount.end()) {
        this->clientAccount.erase(it);
        this->availableIDs.insert(it->first);
        std::cout << "Client account " << it->first << " Deleted." << std::endl;
    } else
        std::cout << "Account " << accountID << " does not exist in this bank.";
}

const int& Bank::getBankLiquidity() const {
    return (this->liquidity);
}

int Bank::generateID() {
    if (this->availableIDs.empty()) {
        if (this->nextID >= INT_MAX)
            throw std::overflow_error("No more available IDs");
        return (this->nextID++);
    }
    int id = *this->availableIDs.begin();
    this->availableIDs.erase(this->availableIDs.begin());
    return (id);
}