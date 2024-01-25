#include "Account.hpp"

Account::Account(int accountID) {
    std::cout << "Account constructor called" << std::endl;
    this->id = accountID;
    this->value = 0;
    this->loan = 0;
}

Account::~Account() {
    std::cout << "Account destructor called" << std::endl;
}

const int& Account::getMyID() const {
    return (this->id);
}

const int& Account::getMyLoan() const {
    return (this->loan);
}

const int& Account::getMyValue() const {
    return (this->value);
}