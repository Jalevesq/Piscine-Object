#include "Account.hpp"

Account::Account(int accountID, int value) {
    this->id = accountID;
    this->value = value;
    this->loan = 0;
    std::cout << "Account constructor called: " << this->id << std::endl;
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

void Account::addLoan(int loanGiven, int amountMoney) {
    this->value += amountMoney;
    this->loan += loanGiven;
}

void Account::payOffLoan(int amountToPayOff) {
    this->value -= amountToPayOff;
    this->loan -= amountToPayOff;
}

void Account::addMoney(int amountToAdd) {
    this->value += amountToAdd;
}

void Account::removeMoney(int amountToRemove) {
    this->value -= amountToRemove;
}
