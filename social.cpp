#include "social.h"

Social::Social(MyDataBase &database)
{
  db=database;
}
bool Social::Follow(std::string user_name1,std::string user_name2)
{
  std::string sql = "select id from person where user_name='"+ user_name2+ "'";
  std::vector<std::vector<std::string>> temp=db.execute(sql.c_str());
  if (temp.size()==0) return 1;
  sql = "select id from friend where person_name='"+ user_name1+ "'and person2_name='"+ user_name2+"'";
  temp=db.execute(sql.c_str());
  if(temp.size()>0)
  {
    std::cout<<"Already Followed!!\n";
    return 1;
  }
  sql = "insert into friend (person_name,person2_name,timestamp) values ('"+ user_name1 + "','"+ user_name2 +"',datetime('now'))";
  db.execute(sql.c_str());
  sql = "insert into timestampss (times,person_name,own_id,friend_id,like_id) values (datetime('now'),'"+ user_name1 + "',0,(select id from friend where person_name='"+ user_name1 + "' and person2_name = '"+user_name2+"'),0)";
  db.execute(sql.c_str());
  return 0;

}

void Social::SetLastTime(std::string username)
{
  std::string sql = "update Person set last_seen = datetime('now') where user_name = '"+username+"'";
  db.execute(sql.c_str());
}

std::vector<std::vector<std::string>> Social::GetLastTime(std::string username)
{
  std::string sql = "select last_seen from person where user_name='"+ username+ "'";
  std::vector<std::vector<std::string>> temp=db.execute(sql.c_str());
  std::cout<< temp[0][0]<<"\n";
  return temp;
}

std::vector<std::vector<std::string>> Social::GetNewLikes(std::string username,std::string time1)
{
  std::string sql = "select person_name,timestamp,name,author,publisher,year from likes inner join books on likes.book_id=books.id where timestamp > '"+time1+"' and person_name in(select person2_name from friend where person_name ='"+username+"')";
  std::vector<std::vector<std::string>> temp=db.execute(sql.c_str());
  for (int i=0;i<temp.size();i++)
  {
    std::cout<<temp[i][0] <<" | "<<temp[i][1] <<" | "<<temp[i][2] <<" | "<<temp[i][3] <<" | "<<temp[i][4] <<"";
    std::cout<<"\n";
  }
  return temp;
    
}
std::vector<std::vector<std::string>> Social::GetNewOwned(std::string username,std::string time1)
{
  std::string sql = "select person_name,timestamp,books.name,author,publisher,year from own inner join books on own.book_id=books.id inner join shelf on own.person_name=shelf.owner_name where shelf.name='General' and timestamp > '"+time1+"' and person_name in(select person2_name from friend where person_name ='"+username+"')";
  std::vector<std::vector<std::string>> temp=db.execute(sql.c_str());
//   for (int i=0;i<temp.size();i++)
//   {
//     std::cout<<temp[i][0] <<" | "<<temp[i][1] <<" | "<<temp[i][2] <<" | "<<temp[i][3] <<" | "<<temp[i][4] <<"";
//     std::cout<<"\n";
//   }
  return temp;
    
}
std::vector<std::vector<std::string>> Social::GetNewFriends(std::string username,std::string time1)
{
  std::string sql = "select person_name,person2_name,timestamp from friend where timestamp > '"+time1+"' and person_name in(select person2_name from friend where person_name ='"+username+"')";
  std::vector<std::vector<std::string>> temp=db.execute(sql.c_str());
  for (int i=0;i<temp.size();i++)
//   {
//     std::cout<<temp[i][0] <<" | "<<temp[i][1] <<" | "<<temp[i][2] <<"";
//     std::cout<<"\n";
//   }
  return temp;
   
}
    