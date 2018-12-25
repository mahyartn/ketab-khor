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

class AInterface //accounting interface
{
    private:
    AccountManager* acman;
    public:
    MyDataBase* db;
    AInterface();
    void Register();
    void Login();
    void Logout();
    std::string CurrentUser();
};

#endif