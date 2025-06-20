//
// Created by 30956 on 2025-06-18.
//
#include "AccountManager.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>
#include <sstream>

void AccountManager::addAccount(const std::shared_ptr<Account>& acc) {
    accounts.push_back(acc);
}

std::shared_ptr<Account> AccountManager::findByAccountNumber(const std::string& accNum) const {
    auto it = std::find_if(accounts.begin(), accounts.end(), [&](const std::shared_ptr<Account>& acc) {
        return acc->getaccountnumber() == accNum;
    });
    return it != accounts.end() ? *it : nullptr;
}

void AccountManager::sortByBalance() {
    std::sort(accounts.begin(), accounts.end(), [](const auto& a, const auto& b) {
        return a->getblance() > b->getblance();
    });
}

void AccountManager::sortByAccountNumber() {
    std::sort(accounts.begin(), accounts.end(), [](const auto& a, const auto& b) {
        return a->getaccountnumber() < b->getaccountnumber();
    });
}

void AccountManager::displayAll() const {
    for (const auto& acc : accounts) {
        std::cout << *acc << std::endl;
    }
}

void AccountManager::importFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) return;

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string type, accNum, name;
        double bal, rateOrFee;
        iss >> type >> accNum >> name >> bal >> rateOrFee;
        if (type == "Savings") {
            accounts.push_back(std::make_shared<SavingsAccount>(accNum, name, bal, rateOrFee));
        } else if (type == "Checking") {
            accounts.push_back(std::make_shared<CheckingAccount>(accNum, name, bal, rateOrFee));
        }
    }
    infile.close();
}

void AccountManager::exportToFile(const std::string& filename) const {
    std::ofstream outfile(filename);
    for (const auto& acc : accounts) {
        outfile << acc->gettype() << " " << acc->getaccountnumber() << " "
                << acc->getownername() << " " << acc->getblance() << " "
                << acc->lixi() << std::endl;
    }
    outfile.close();
}
