// === main.cpp ===
#include <iostream>
#include <memory>
#include "AccountManager.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;

void printMenu() {
    cout << "\n====== Omni-Union Core 账户管理系统 ======\n";
    cout << "1. 添加账户\n";
    cout << "2. 查询账户（按账号）\n";
    cout << "3. 存款\n";
    cout << "4. 取款\n";
    cout << "5. 转账\n";
    cout << "6. 显示所有账户\n";
    cout << "7. 按余额排序\n";
    cout << "8. 按账号排序\n";
    cout << "9. 导入账户数据\n";
    cout << "10. 导出账户数据\n";
    cout << "0. 退出\n";
    cout << "请选择操作（0-10）：";
}

int main() {
    AccountManager manager;
    bool running = true;

    while (running) {
        printMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: { // 添加账户
                string type, accNum, name;
                double balance, rateOrFee;
                cout << "输入账户类型(Savings/Checking): ";
                cin >> type;
                cout << "输入账号: ";
                cin >> accNum;
                cout << "输入户名: ";
                cin >> name;
                cout << "输入初始余额: ";
                cin >> balance;
                if (type == "Savings") {
                    cout << "输入利率(0.0-1.0): ";
                    cin >> rateOrFee;
                    manager.addAccount(make_shared<SavingsAccount>(accNum, name, balance, rateOrFee));
                } else if (type == "Checking") {
                    cout << "输入手续费: ";
                    cin >> rateOrFee;
                    manager.addAccount(make_shared<CheckingAccount>(accNum, name, balance, rateOrFee));
                } else {
                    cout << "未知账户类型，添加失败。\n";
                }
                break;
            }
            case 2: { // 查询账户
                string accNum;
                cout << "输入查询账号: ";
                cin >> accNum;
                auto acc = manager.findByAccountNumber(accNum);
                if (acc) {
                    cout << *acc << endl;
                } else {
                    cout << "账户不存在。\n";
                }
                break;
            }
            case 3: { // 存款
                string accNum;
                double amount;
                cout << "输入账号: ";
                cin >> accNum;
                cout << "输入存款金额: ";
                cin >> amount;
                auto acc = manager.findByAccountNumber(accNum);
                if (acc) {
                    *acc += amount;
                    cout << "存款成功，当前余额: " << acc->getblance() << endl;
                } else {
                    cout << "账户不存在。\n";
                }
                break;
            }
            case 4: { // 取款
                string accNum;
                double amount;
                cout << "输入账号: ";
                cin >> accNum;
                cout << "输入取款金额: ";
                cin >> amount;
                auto acc = manager.findByAccountNumber(accNum);
                if (acc) {
                    if (*acc -= amount; acc->getblance() >= 0) {
                        cout << "取款成功，当前余额: " << acc->getblance() << endl;
                    } else {
                        cout << "余额不足，取款失败。\n";
                    }
                } else {
                    cout << "账户不存在。\n";
                }
                break;
            }
            case 5: { // 转账
                string fromAcc, toAcc;
                double amount;
                cout << "输入转出账号: ";
                cin >> fromAcc;
                cout << "输入转入账号: ";
                cin >> toAcc;
                cout << "输入转账金额: ";
                cin >> amount;
                auto from = manager.findByAccountNumber(fromAcc);
                auto to = manager.findByAccountNumber(toAcc);
                if (!from || !to) {
                    cout << "账户不存在，转账失败。\n";
                    break;
                }
                if (from->getblance() < amount) {
                    cout << "余额不足，转账失败。\n";
                    break;
                }
                *from -= amount;
                *to += amount;
                cout << "转账成功。\n";
                break;
            }
            case 6: { // 显示所有账户
                manager.displayAll();
                break;
            }
            case 7: { // 按余额排序
                manager.sortByBalance();
                cout << "已按余额排序。\n";
                break;
            }
            case 8: { // 按账号排序
                manager.sortByAccountNumber();
                cout << "已按账号排序。\n";
                break;
            }
            case 9: { // 导入账户数据
                string filename;
                cout << "输入导入文件名: ";
                cin >> filename;
                manager.importFromFile(filename);
                cout << "导入完成。\n";
                break;
            }
            case 10: { // 导出账户数据
                string filename;
                cout << "输入导出文件名: ";
                cin >> filename;
                manager.exportToFile(filename);
                cout << "导出完成。\n";
                break;
            }
            case 0: {
                running = false;
                cout << "退出程序。\n";
                break;
            }
            default:
                cout << "无效选择，请重试。\n";
        }
    }

    return 0;
}

