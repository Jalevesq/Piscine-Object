#include "Account.hpp"

Account::Account(int accountID, int value) {
    std::cout << "Account constructor called" << std::endl;
    this->id = accountID;
    this->value = value;
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


bool Account::addLoan(int amountToAdd) {
    if (amountToAdd + this->loan >= std::numeric_limits<int>::max()) {
        std::cout << "Loan addition exceeds maximum account loan limit. Nothing has been loaned." << std::endl;
        return false;
    }

    return true;
}