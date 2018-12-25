#ifndef SOCIAL_H
#define SOCIAL_H

#include <stdio.h>
#include "basic.h"

class Social
{
    private:
    MyDataBase db;
    public:
    Social(MyDataBase &database);
    int Follow(std::string user_name1,std::string user_name2);
    void SetLastTime(std::string username);
    vvs GetLastTime(std::string username);
    vvs GetNewLikes(std::string username,std::string time1);
    vvs GetNewFriends(std::string username,std::string time1);
    vvs GetNewOwned(std::string username,std::string time1);  
};

class SocialCLI
{
    private:
    MyDataBase DB;
    std::string CurrentUser;
    Social *community;
    public:
    SocialCLI(MyDataBase &db,std::string Username);
    void Follow();
    void ShowUpdates();
};




#endif