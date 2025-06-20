#include"Account.h"
Account::Account(const std::string &accnum, const std::string &name, double bal) :accountnumber(accnum),ownername(name),balance(bal){}
std::string Account::getaccountnumber() const{
    return accountnumber;
}
std::string Account::getownername() const {
    return ownername;
}

double Account::getblance() const {
    return balance;
}

void Account::putmoney(double money) {
    if(money > 0) balance+=money;
}
bool Account::getmoney(double money) {
    if(money>0&&balance>=money){
        balance -=money;
        return true;
    }
    return false;
}

Account& Account::operator+=(double money) {
    putmoney(money);
    return *this;
}

Account& Account::operator-=(double money) {
    getmoney(money);
    return *this;
}

std::ostream& operator<<(std::ostream& os,const Account& acc){
    os<<"["<<acc.gettype()<<"]Account: "<<acc.accountnumber<<",owner: "<<acc.ownername<<",balance: "<<acc.balance;
    return os;
}