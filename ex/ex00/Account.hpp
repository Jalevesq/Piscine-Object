#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP


// Mandatory: It must be impossible to add money to a client account without going through the bank

class Account {
    public:
        Account();
        ~Account();
        // getMyID();
        // getMyLoan();
        // getMyValue();
    private:
        int id;
        int value;
        int loan;
        //
};

#endif