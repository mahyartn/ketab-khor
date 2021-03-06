#include "accounting.h"

AccountManager::AccountManager(MyDataBase &database)
{
    db=database;
}

bool AccountManager::AddUser(std::string user_name,std::string password)
{
    std::string sql = "select user_name from person where user_name ='" + user_name +"'";
    vvs temp= db.execute(sql.c_str());
    if (temp.size()>0)
    {
        return 0;
    }
    else
    {
        sql = "insert into person (user_name,password,last_seen) values ( '"+user_name+"' , '" + password +"',datetime('now'))";
        db.execute(sql.c_str());
        sql = "insert into Shelf (name,owner_name) values ( 'General' , '"+ user_name+"')";
        db.execute(sql.c_str());
        return 1;   
    }
    
}

bool AccountManager::Authenticate(std::string user_name,std::string password)
{
    std::string sql = "select user_name from person where user_name ='" + user_name+"'";
    vvs temp= db.execute(sql.c_str());
    if (temp.size()>0)
    {
        sql = "select user_name from person where user_name ='" + user_name+"' and password='"+password+"'";
        vvs temp2=db.execute(sql.c_str());
        if (temp2.size()==1) 
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }  
}
void AccountManager::DeAuthenticate()
{
    current_session_id="";
}
AcountingCLI::AcountingCLI()
{
    db=new MyDataBase ("mydatabase.db");
    acman=new AccountManager(*db);
    system ("clear");
}

void AcountingCLI::Register()
{
    while(true)
    {
        std::cout<<"Please Enter New Username: ";
        std::string username;
        std::cin>> username;
        std::cout<<"Please Enter New Password: ";
        std::string password;
        std::cin>> password;
        if (acman->AddUser(username,password))
        {
            system ("clear");
            std::cout<<"User Added!\n\n (Press ENTER To Continue....)\n";
            std::cin.ignore();
            std::cin.get();
            break;
        }
        system ("clear");
        std::cout<<"Not valid!\n";
    }
}

void AcountingCLI::Login()
{
    while(true)
    {
        std::cout<<"Please Enter Username: ";
        std::string username;
        std::cin>> username;
        std::cout<<"Please Enter Password: ";
        std::string password;
        std::cin>> password;
        if (acman->Authenticate(username,password))
        {
            system ("clear");
            std::cout<<"...Access Granted...\n";
            break;
        }
        std::cout<<"\n!!!Username or Password is incorrect!!!\n";
    }

}

std::string AcountingCLI::CurrentUser()
{
    return acman->current_session_id;
}


