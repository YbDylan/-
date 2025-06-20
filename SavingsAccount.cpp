#include"SavingsAccount.h"
SavingsAccount::SavingsAccount(const std::string &accnum, const std::string &name, double bal, double rate):Account(accnum,name,bal),interestRate(rate) {}
double SavingsAccount::lixi() const {
    return balance*interestRate;
}

std::string SavingsAccount::gettype() const {
    return "Savings";
}
