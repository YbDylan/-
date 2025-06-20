//
// Created by 30956 on 2025-06-18.
//

#ifndef C__CURRICULUM_DESIGN_SAVINGSACCOUNT_H
#define C__CURRICULUM_DESIGN_SAVINGSACCOUNT_H
#include"Account.h"

class SavingsAccount:public Account {
private:
    double interestRate;//储蓄利率
public:
    SavingsAccount(const std::string &accnum, const std::string &name, double bal, double rate);

    double lixi() const override;

    std::string gettype() const override;
};
#endif //C__CURRICULUM_DESIGN_SAVINGSACCOUNT_H
