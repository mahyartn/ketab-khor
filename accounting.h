#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include <string>
#include <vector>
#include "basic.h"


class AccountManager
{
    private:
    MyDataBase db;
    public:
    AccountManager(MyDataBase &database);
    bool AddUser(std::string user_name,std::string password);
    bool Authenticate(std::string user_name,std::string password);
    void DeAuthenticate();
    std::string current_session_id = "";
};

#endif