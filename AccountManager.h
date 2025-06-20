#ifndef C__CURRICULUM_DESIGN_ACCOUNTMANAGER_H
#define C__CURRICULUM_DESIGN_ACCOUNTMANAGER_H
#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>
#include "Account.h"

class AccountManager {
private:
    std::vector<std::shared_ptr<Account>> accounts;

public:
    void addAccount(const std::shared_ptr<Account>& acc);
    std::shared_ptr<Account> findByAccountNumber(const std::string& accNum) const;

    void sortByBalance();
    void sortByAccountNumber();

    void displayAll() const;
    void importFromFile(const std::string& filename);
    void exportToFile(const std::string& filename) const;
};
#endif //C__CURRICULUM_DESIGN_ACCOUNTMANAGER_H
