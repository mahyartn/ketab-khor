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
    bool Follow(std::string user_name1,std::string user_name2);
    void SetLastTime(std::string username);
    std::vector<std::vector<std::string>> GetLastTime(std::string username);
    std::vector<std::vector<std::string>> GetNewLikes(std::string username,std::string time1);
    std::vector<std::vector<std::string>> GetNewFriends(std::string username,std::string time1);
    std::vector<std::vector<std::string>> GetNewOwned(std::string username,std::string time1);
    
};





#endif