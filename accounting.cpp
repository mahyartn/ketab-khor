#include "accounting.h"

AccountManager::AccountManager(MyDataBase &database)
{
    db=database;
}


bool AccountManager::AddUser(std::string user_name,std::string password)
{
    std::string sql = "select user_name from person where user_name ='" + user_name +"'";
    std::vector<std::vector<std::string>> temp= db.execute(sql.c_str());
    if (temp.size()>0)
    {
        std::cout<<"user exists!!\n";
    }
    else
    {
        sql = "insert into person (user_name,password,last_seen) values ( '"+user_name+"' , '" + password +"',datetime('now'))";
        db.execute(sql.c_str());
        sql = "insert into Shelf (name,owner_name) values ( 'General' , '"+ user_name+"')";
        db.execute(sql.c_str());
        
    }
    
}

bool AccountManager::Authenticate(std::string user_name,std::string password)
{
    std::string sql = "select user_name from person where user_name ='" + user_name+"'";
    std::vector<std::vector<std::string>> temp= db.execute(sql.c_str());
    if (temp.size()>0)
    {
        sql = "select user_name from person where user_name ='" + user_name+"' and password='"+password+"'";
        std::vector<std::vector<std::string>> temp2=db.execute(sql.c_str());
        if (temp2.size()>0) 
            if (temp2[0][0]==user_name)
            {
                current_session_id=user_name;
                std::cout<<"access granted!!\n";
                return 1;
            }
    }
    else  return 0;
}
