cmake_minimum_required(VERSION 3.29)
project(c__curriculum_design)

set(CMAKE_CXX_STANDARD 20)

add_executable(c__curriculum_design main.cpp
        Account.h
        Account.cpp
        SavingsAccount.h
        SavingsAccount.cpp
        CheckingAccount.h
        CheckingAccount.cpp
        AccountManager.h
        AccountManager.cpp)
install(TARGETS c__curriculum_design RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(FILES file_account.txt DESTINATION ${CMAKE_INSTALL_PREFIX}/data)