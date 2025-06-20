#include"CheckingAccount.h"
CheckingAccount::CheckingAccount(const std::string &accnum, const std::string &name, double bal, double fee) :Account(accnum,name,bal),fee(fee){}
double CheckingAccount::lixi() const{
    return -fee;
}
std::string CheckingAccount::gettype() const{
    return "Checking";
}