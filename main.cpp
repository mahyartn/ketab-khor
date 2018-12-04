#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
class AccountManager
{
    private:
    void SearchUser(std::string user_name);
    void LoadUsers(std::ifstream &acounts);
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
        std::cout <<line<<"\n";
    }
  }
else std::cout << "Unable to open file\n";
}

void AccountManager::SearchUser(std::string user_name)
{

}
int main()
{
 AccountManager ali("test.txt");
std::string alii="akjkja lklalkal";
std::string ghol="";
int pos=alii.find(' ');
ghol=alii.substr(pos+1,alii.length());
std::cout<<ghol<<"\n";
}
