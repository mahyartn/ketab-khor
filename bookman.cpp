#include "bookman.h"



BookFunctions::BookFunctions(MyDataBase &database)
{
  db=database;
}
std::vector<std::vector<std::string>> BookFunctions::AllBooks()
{
  std::string sql = "select * from books";
  std::vector<std::vector<std::string>> temp= db.execute(sql.c_str());
  // for (int i=0;i<temp.size();i++)
  // {
  //   std::cout<<temp[i][0] <<" | "<<temp[i][1] <<" | "<<temp[i][2] <<" | "<<temp[i][3] <<" | "<<temp[i][4] <<"";
  //   std::cout<<"\n";
  // }
  return temp;
}

std::vector<std::vector<std::string>> BookFunctions::Book(std::string id)
{
  std::string sql = "select * from books where id="+id;
  std::vector<std::vector<std::string>> temp= db.execute(sql.c_str());
  for (int i=0;i<temp.size();i++)
  {
    std::cout<<temp[i][0] <<" | "<<temp[i][1] <<" | "<<temp[i][2] <<" | "<<temp[i][3] <<" | "<<temp[i][4] <<"";
    std::cout<<"\n";
  }
  return temp;
}

bool BookFunctions::LikeBook(std::string id,std::string username)
{
  std::string sql = "select id from likes where person_name='"+ username + "'and book_id="+ id ;
  std::vector<std::vector<std::string>> temp=db.execute(sql.c_str());
  if(temp.size()>0)
  {
    std::cout<<"Already Liked!!\n";
    return 1;
  }
  sql = "insert into likes (person_name,book_id,timestamp) values ('"+ username + "',"+ id +",datetime('now'))";
  db.execute(sql.c_str());
  sql = "insert into timestampss (times,person_name,own_id,friend_id,like_id) values (datetime('now'),'"+ username + "',0,0,(select id from likes where person_name='"+ username + "' and book_id ="+id+"))";
  db.execute(sql.c_str());
  return 0;
}
bool BookFunctions::BuyBook(std::string id,std::string username)
{
  std::string sql = "select id from own where person_name='"+ username + "'and book_id="+ id ;
  std::vector<std::vector<std::string>> temp=db.execute(sql.c_str());
  if(temp.size()>0)
  {
    std::cout<<"Already own!!\n";
    return 1;
  }
  sql = "insert into own (person_name,book_id,shelf_id,timestamp) values ('"+ username + "',"+ id +",(select id from shelf where name='General' and owner_name = '"+username+"'),datetime('now'))";
  db.execute(sql.c_str());
  sql = "insert into timestampss (times,person_name,own_id,friend_id,like_id) values (datetime('now'),'"+ username + "',(select id from own where person_name='"+ username + "' and book_id ="+id+"),0,0)";
  db.execute(sql.c_str());
  return 0;
}

std::vector<std::vector<std::string>> BookFunctions::FavoriteBooks(std::string username)
{
  std::string sql = "select * from books where id in (select book_id from likes where person_name= '"+username+"')" ;
  std::vector<std::vector<std::string>> temp=db.execute(sql.c_str());
  if(temp.size()==0)
  {
    std::cout<<"No books!!\n";
  }
  // for (int i=0;i<temp.size();i++)
  // {
  //   std::cout<<temp[i][0] <<" | "<<temp[i][1] <<" | "<<temp[i][2] <<" | "<<temp[i][3] <<" | "<<temp[i][4] <<"";
  //   std::cout<<"\n";
  // }
  return temp;
}