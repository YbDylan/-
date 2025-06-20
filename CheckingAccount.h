
// Created by 30956 on 2025-06-18.
//

#ifndef C__CURRICULUM_DESIGN_CHECKINGACCOUNT_H
#define C__CURRICULUM_DESIGN_CHECKINGACCOUNT_H
#include"Account.h"

class CheckingAccount: public Account{
private:
    double fee;//每笔结算手续费
public:
    CheckingAccount(const std::string& accnum,const std::string& name,double bal,double fee);
    double lixi() const override;
    std::string gettype() const override;
};
#endif //C__CURRICULUM_DESIGN_CHECKINGACCOUNT_H
