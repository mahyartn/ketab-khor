#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "basic.h"
class AccountManager
{
    private:
    
    std::string filename;
    void LoadUsers(std::ifstream &acounts);
    void AddUserToFile(std::string user_name,std::string password);
    std::string SearchAndFetchUser(std::string user_name);
    std::vector<user> UserList;
    public:
    AccountManager(std::string name);
    bool AddUser(std::string user_name,std::string password);
    bool Authenticate(std::string user_name,std::string password);
    std::string current_session_id = "";
};

AccountManager::AccountManager(std::string name)
{
std::ifstream accounts_file (name);
std::string line;
if (accounts_file.is_open())
  {
    getline(accounts_file,line);
    if (line == "This is the acount list:") std::cout << "great!\n";
    else
    {
        std::cout << "Wrong file!\n";
        return;
    }
    while (getline(accounts_file,line))
    {
        AccountsExtractor(line,' ',UserList);
    }
    accounts_file.close();
    filename = name;
  }
else std::cout << "Unable to open file\n";
}

std::string AccountManager::SearchAndFetchUser(std::string user_name)
{
    for (int i =0;i<UserList.size();i++)
    {
        if (UserList[i].UserName == user_name) return UserList[i].Password;
    }
    return "";
}

void AccountManager::AddUserToFile(std::string user_name,std::string password)
{
    std::ofstream accounts_file(filename,std::ios::app);
    if (accounts_file.is_open())
    {
        accounts_file<<user_name<<" "<<password<<"\n";
    }
    else std::cout << "Unable to open file\n";
}

bool AccountManager::AddUser(std::string user_name,std::string password)
{
    std::string result=SearchAndFetchUser(user_name);
    if (result != "") return false;
    else
    {
        user temp;
        temp.UserName=user_name;
        temp.Password=password;
        UserList.push_back(temp);
        AddUserToFile(user_name,password);
        return true;
    }
}

bool AccountManager::Authenticate(std::string user_name,std::string password)
{
    if (password==SearchAndFetchUser(user_name))
    {
        current_session_id = user_name;
        return true;
    }
    else return false;
}

int main()
{
 AccountManager ali("test.txt");
 std::cout<<ali.Authenticate("admin","astro!@#")<<"  \n";
}
