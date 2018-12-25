#include "social.h"

Social::Social(MyDataBase &database)
{
  db=database;
}
int Social::Follow(std::string user_name1,std::string user_name2)
{
  std::string sql = "select id from person where user_name='"+ user_name2+ "'";
  vvs temp=db.execute(sql.c_str());
  if (temp.size()==0) return 2;
  sql = "select id from friend where person_name='"+ user_name1+ "'and person2_name='"+ user_name2+"'";
  temp=db.execute(sql.c_str());
  if(temp.size()>0)  return 1;
  sql = "insert into friend (person_name,person2_name,timestamp) values ('"+ user_name1 + "','"+ user_name2 +"',datetime('now'))";
  db.execute(sql.c_str());
  return 0;
}

void Social::SetLastTime(std::string username)
{
  std::string sql = "update Person set last_seen = datetime('now') where user_name = '"+username+"'";
  db.execute(sql.c_str());
}

vvs Social::GetLastTime(std::string username)
{
  std::string sql = "select last_seen from person where user_name='"+ username+ "'";
  vvs temp=db.execute(sql.c_str());
  std::cout<< temp[0][0]<<"\n";
  return temp;
}

vvs Social::GetNewLikes(std::string username,std::string time1)
{
  std::string sql = "select person_name,name,author,books.id,timestamp from likes inner join books on likes.book_id=books.id where timestamp > '"+time1+"' and person_name in(select person2_name from friend where person_name ='"+username+"')";
  vvs temp=db.execute(sql.c_str());
  return temp;
    
}
vvs Social::GetNewOwned(std::string username,std::string time1)
{
  std::string sql = "select person_name,books.name,author,books.id,timestamp from own inner join books on own.book_id=books.id inner join shelf on own.person_name=shelf.owner_name where shelf.name='General' and timestamp > '"+time1+"' and person_name in(select person2_name from friend where person_name ='"+username+"')";
  vvs temp=db.execute(sql.c_str());
  return temp; 
}
vvs Social::GetNewFriends(std::string username,std::string time1)
{
  std::string sql = "select person_name,person2_name,timestamp from friend where timestamp > '"+time1+"' and person_name in(select person2_name from friend where person_name ='"+username+"')";
  vvs temp=db.execute(sql.c_str());
  for (int i=0;i<temp.size();i++)
  return temp; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

SocialCLI::SocialCLI(MyDataBase &db,std::string Username)
{
    DB=db;
    CurrentUser=Username;
    community=new Social(DB);
}

void SocialCLI::Follow()
{
    system("clear");
    std::cout << "Please Enter Person Name to follow: ";
    std::string name;
    std::cin >> name;
    int temp=community->Follow(CurrentUser,name);
    if (temp==2) std::cout <<"Person not found!\n";
    else if (temp==1) std::cout <<"Person already Followed!\n";
    else std::cout <<"Person Successfully followed.\n";
    std::cout<<"(Press ENTER To Continue....)\n";
    std::cin.ignore();
    std::cin.get();
}
void SocialCLI::ShowUpdates()
{
  system("clear");
  vvs temp=community->GetLastTime(CurrentUser);
  std::string date1=temp[0][0];
  std::cout <<"Last Activities since "<<date1<<" is here: \n";
  temp=community->GetNewFriends(CurrentUser,date1);
  for (int i=0;i<temp.size();i++) std::cout <<temp[i][0]<<" has followed "<<temp[i][1]<<" on "<<temp[i][2]<<".\n\n";
  temp=community->GetNewLikes(CurrentUser,date1);
  for (int i=0;i<temp.size();i++) std::cout <<temp[i][0]<<" has liked the book named "<<temp[i][1]<<" by "<<temp[i][2]<<" whith Book ID:"<<temp[i][3]<<" on "<<temp[i][4]<<".\n\n";
  temp=community->GetNewOwned(CurrentUser,date1);
  for (int i=0;i<temp.size();i++) std::cout <<temp[i][0]<<" has bought the book named "<<temp[i][1]<<" by "<<temp[i][2]<<" whith Book ID:"<<temp[i][3]<<" on "<<temp[i][4]<<".\n\n";   
  community->SetLastTime(CurrentUser);
  std::cout<<"(Press ENTER To Continue....)\n";
  std::cin.ignore();
  std::cin.get();
}

    