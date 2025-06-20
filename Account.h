//
// Created by 30956 on 2025-06-18.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
#include<string>

class Account{
protected:
    std::string accountnumber;
    std::string ownername;
    double balance;
public:
    Account(const std::string& accnum,const std::string& name, double bal);
    virtual ~Account(){}
    std::string getaccountnumber() const;
    std::string getownername() const;
    double getblance() const;
    void putmoney(double money);//取钱
    bool getmoney(double money);
    Account& operator+=(double money);//转账
    Account& operator-=(double money);
    virtual double lixi() const = 0;//利息/结算
    virtual std::string gettype() const = 0;
    friend std::ostream& operator<<(std::ostream&os, const Account& acc);
};

#endif //C__CURRICULUM_DESIGN_HEAD_H
