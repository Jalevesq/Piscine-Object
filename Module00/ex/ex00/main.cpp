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

void test3(Bank *bank, int account1) {
    cout << RED << BOLD << "--- [Test 3] ---" << RESET << endl;
    cout << GREEN << BOLD << "Trying to loan more money than the bank own" << RESET << endl;
    cout << YELLOW << BOLD << "- Before -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << YELLOW << BOLD << "- Action -" << RESET << endl;
    bank->giveLoan(account1, 10000); // HERE
    cout << YELLOW << BOLD <<  "- After -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << RED << BOLD << "----------" << RESET << endl;
}


void test4() {
    Bank bank(2147483647);
    int account1 = bank.createAccount();
    cout << RED << BOLD << "--- [Test 4] ---" << RESET << endl;
    cout << GREEN << BOLD << "Trying to give INT MAX loan." << RESET << endl;
    cout << YELLOW << BOLD << "- Before -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank.getAccountValue(account1) << ", Loan: " << bank.getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank.getBankLiquidity() << std::endl;
    cout << YELLOW << BOLD << "- Action -" << RESET << endl;
    bank.giveLoan(account1, 2147483647); // HERE
    cout << YELLOW << BOLD <<  "- After -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank.getAccountValue(account1) << ", Loan: " << bank.getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank.getBankLiquidity() << std::endl;
    cout << RED << BOLD << "----------" << RESET << endl;
}

void test5(Bank *bank, int account1) {
    cout << RED << BOLD << "--- [Test 5] ---" << RESET << endl;
    cout << GREEN << BOLD << "Trying to pay off loan." << RESET << endl;
    cout << YELLOW << BOLD << "- Before -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << YELLOW << BOLD << "- Action -" << RESET << endl;
    bank->payOffLoan(account1, 50); // HERE
    cout << YELLOW << BOLD <<  "- After -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << RED << BOLD << "----------" << RESET << endl;
}

void test6(Bank *bank, int account1) {
    cout << RED << BOLD << "--- [Test 6] ---" << RESET << endl;
    cout << GREEN << BOLD << "Trying to pay more than what I have in the bank." << RESET << endl;
    cout << YELLOW << BOLD << "- Before -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << YELLOW << BOLD << "- Action -" << RESET << endl;
    bank->payOffLoan(account1, 50); // HERE
    cout << YELLOW << BOLD <<  "- After -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << RED << BOLD << "----------" << RESET << endl;
}

void test7(Bank *bank) {
    cout << RED << BOLD << "--- [Test 7] ---" << RESET << endl;
    cout << GREEN << BOLD << "Trying to give a loan to an account that does not exist" << RESET << endl;
    cout << YELLOW << BOLD << "- Action -" << RESET << endl;
    try {
        bank->giveLoan(123, 10000); // HERE
    } catch (std::runtime_error& e) {
        cout << e.what() << endl;
    }
    cout << RED << BOLD << "----------" << RESET << endl;
}

void test8(Bank *bank,int account1) {

    cout << RED << BOLD << "--- [Test 8] ---" << RESET << endl;
    cout << GREEN << BOLD << "Trying to delete & re-create account." << RESET << endl;
    cout << YELLOW << BOLD << "- Before -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << YELLOW << BOLD << "- Action -" << RESET << endl;
    bank->deleteAccount(account1);
    int recreate = bank->createAccount();
    cout << "New Account ID: " << recreate << endl;
    cout << RED << BOLD << "----------" << RESET << endl;
}

void test9(Bank *bank, int account1) {
    cout << RED << BOLD << "--- [Test 9] ---" << RESET << endl;
    cout << GREEN << BOLD << "Trying to add and remove money from account." << RESET << endl;
    cout << YELLOW << BOLD << "- Before -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << YELLOW << BOLD << "- Action -" << RESET << endl;
    bank->addMoneyAccountBank(account1, 100);
    cout << YELLOW << BOLD <<  "- After -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << YELLOW << BOLD << "- Action -" << RESET << endl;
    bank->removeMoneyAccountBank(account1, 75);
    cout << YELLOW << BOLD <<  "- After -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << RED << BOLD << "----------" << RESET << endl;
}


void test10(Bank *bank, int account1) {
    cout << RED << BOLD << "--- [Test 10] ---" << RESET << endl;
    cout << GREEN << BOLD << "Trying to give a add money from outside the bank" << RESET << endl;
    cout << YELLOW << BOLD << "- Before -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << YELLOW << BOLD << "- Action -" << RESET << endl;
    bank->addMoneyAccountOutside(account1, 935); // HERE
    cout << YELLOW << BOLD <<  "- After -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << RED << BOLD << "----------" << RESET << endl;
}

void test11(Bank *bank, int account1) {
    cout << RED << BOLD << "--- [Test 11] ---" << RESET << endl;
    cout << GREEN << BOLD << "Multiple test" << RESET << endl;
    cout << YELLOW << BOLD << "- Before -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << YELLOW << BOLD << "- Action -" << RESET << endl;
    bank->addMoneyAccountOutside(account1, 1000); // HERE
    cout << YELLOW << BOLD <<  "- After -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << YELLOW << BOLD << "- Action -" << RESET << endl;
    bank->giveLoan(account1, 1000); // HERE
    cout << YELLOW << BOLD <<  "- After -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << YELLOW << BOLD << "- Action -" << RESET << endl;
    bank->payOffLoan(account1, 1000); // HERE
    cout << YELLOW << BOLD <<  "- After -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << ", Loan: " << bank->getAccountLoan(account1) << endl;
    cout << "Bank - Liquidity: " << bank->getBankLiquidity() << std::endl;
    cout << RED << BOLD << "----------" << RESET << endl;
}

void test12(Bank *bank, int account1) {
    cout << RED << BOLD << "--- [Test 12] ---" << RESET << endl;
    cout << GREEN << BOLD << "Trying operator overload on bank" << RESET << endl;
    cout << YELLOW << BOLD << "- Before -" << RESET << endl;
    cout << "account1 - ID: " << account1 << ", Value: " << bank->getAccountValue(account1) << endl;
    cout << YELLOW << BOLD << "- Action -" << RESET << endl;
    const Account& account = (*bank)[0];
    cout << YELLOW << BOLD <<  "- Account -" << RESET << endl;
    cout << "account - ID: " << account.getMyID() << ", Value: " << bank->getAccountValue(account.getMyID() ) << endl;
    cout << RED << BOLD << "----------" << RESET << endl;
}

void test13(Bank *bank) {
    cout << RED << BOLD << "--- [Test 13] ---" << RESET << endl;
    cout << GREEN << BOLD << "Trying operator overload out of bound" << RESET << endl;
    cout << YELLOW << BOLD << "- Action -" << RESET << endl;
    try {
        const Account& account = (*bank)[-1];
        cout << "account - ID: " << account.getMyID() << ", Value: " << bank->getAccountValue(account.getMyID() ) << endl;
    } catch (std::runtime_error& e) {
        std::cout << e.what() << endl;
    }
    cout << RED << BOLD << "----------" << RESET << endl;
}


int main() {
    Bank *bank = new Bank(1000);

    int account1 = bank->createAccount();

    test1(bank, account1);
    test2(bank, account1);
    test3(bank, account1);
    test4();
    test5(bank, account1);
    test6(bank, account1);
    test7(bank);
    test8(bank, account1);
    test9(bank, account1);
    test10(bank, account1);
    test11(bank, account1);
    test12(bank, account1);
    test13(bank);
    delete bank;
    cout << "--- END ---" << endl;
}