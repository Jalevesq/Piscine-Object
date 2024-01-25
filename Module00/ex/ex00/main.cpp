// Mandatory:
// • If it makes sense, the creation of a Getter and a Setter is mandatory. Getter(s) by
// copy will not be accepted
// • If it makes sense, the creation of a const Getter is mandatory. const Getter(s) by
// copy will not be accepted
// During the evaluation, each choice made during this exercise must be defended.

#include <iostream>
#include "Account.hpp"
#include "Bank.hpp"

using std::cout;
using std::endl;

// ANSI Color Codes
const std::string RED = "\033[31m";      // Red color
const std::string GREEN = "\033[32m";    // Green color
const std::string YELLOW = "\033[33m";   // Yellow color
const std::string BLUE = "\033[34m";     // Blue color
const std::string MAGENTA = "\033[35m";  // Magenta color
const std::string CYAN = "\033[36m";     // Cyan color

// ANSI Formatting Codes
const std::string BOLD = "\033[1m";      // Bold text
const std::string RESET = "\033[0m";     // Reset to default

void test1(Bank *bank, int account1) {
    cout << RED << BOLD << "--- [Test 1] ---" << RESET << endl;
    cout << GREEN << BOLD << "Trying to give a normal loan" << RESET << endl;
    cout << YELLOW << BOLD << "- Before -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << YELLOW << BOLD << "- Action -" << RESET << endl;
    bank->giveLoan(account1, 100); // HERE
    cout << YELLOW << BOLD <<  "- After -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << RED << BOLD << "----------" << RESET << endl;
}

void test2(Bank *bank, int account1) {
    cout << RED << BOLD << "--- [Test 2] ---" << RESET << endl;
    cout << GREEN << BOLD << "Trying to give a negative loan" << RESET << endl;
    cout << YELLOW << BOLD << "- Before -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << YELLOW << BOLD << "- Action -" << RESET << endl;
    bank->giveLoan(account1, -1); // HERE
    cout << YELLOW << BOLD <<  "- After -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << RED << BOLD << "----------" << RESET << endl;
}

int main() {
    Bank bank = Bank(1000);

    int account1 = bank.createAccount();
    int account2 = bank.createAccount();

    cout << "account1 - ID: " << account1 << ", Value: " << bank.getAccountValue(account1) << ", Loan: " << bank.getAccountLoan(account1) << endl;
    cout << "account2 - ID: " << account2 << ", Value: " << bank.getAccountValue(account2) << ", Loan: " << bank.getAccountLoan(account2) << endl;

    test1(&bank, account1);
    test2(&bank, account1);
    cout << "Give loan 100" << endl;
    bank.giveLoan(account1, 100);
    cout << "account1 - ID: " << account1 << ", Value: " << bank.getAccountValue(account1) << ", Loan: " << bank.getAccountLoan(account1) << endl;



    cout << "--- END ---" << endl;
}