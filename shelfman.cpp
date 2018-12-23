#include "shelfman.h"


ShelfFunctions::ShelfFunctions(MyDataBase &database)
{
  db=database;
}
bool ShelfFunctions::AddShelf(std::string shelf_name,std::string user_name)
{
    std::string sql = "select id from Shelf where owner_name='"+ user_name + "'and name='"+ shelf_name +"'";
  std::vector<std::vector<std::string>> temp=db.execute(sql.c_str());
  if(temp.size()>0)
  {
    std::cout<<"Already Added!!\n";
    return 1;
  }
  sql = "insert into Shelf (name,owner_name) values ('"+ shelf_name + "','"+ user_name +"')";
  db.execute(sql.c_str());
  return 0;
}
int ShelfFunctions::AddToShelf(std::string shelf_name,std::string user_name,std::string book_id)
{
  std::string sql = "select id from shelf where owner_name='"+user_name+"' and name='"+shelf_name+"'";
  std::vector<std::vector<std::string>> temp=db.execute(sql.c_str());
  if(temp.size()==0) return 3;
  sql = "select id from own where person_name='"+ user_name + "' and book_id="+ book_id ;
  temp=db.execute(sql.c_str());
  if(temp.size()==0) return 2;
  sql = "select id from own where person_name='"+ user_name + "' and book_id="+ book_id +" and shelf_id = (select id from shelf where owner_name='"+user_name+"' and name='"+shelf_name+"')";
  temp=db.execute(sql.c_str());
  if(temp.size()>0) return 1;
  sql = "insert into own (person_name,book_id,shelf_id,timestamp) values ('"+ user_name + "',"+ book_id +",(select id from shelf where name='"+shelf_name+"' and owner_name = '"+user_name+"'),datetime('now'))";
  db.execute(sql.c_str());
  return 0;  
}

std::vector<std::vector<std::string>> ShelfFunctions::ShowShelves(std::string user_name)
{
  std::string sql = "select * from shelf where owner_name='"+user_name+"'";
  std::vector<std::vector<std::string>> temp=db.execute(sql.c_str());
    for (int i=0;i<temp.size();i++)
  {
    std::cout<<temp[i][0] <<" | "<<temp[i][1] <<" | "<<temp[i][2] <<"";
    std::cout<<"\n";
  }
  return temp;     
}
std::vector<std::vector<std::string>> ShelfFunctions::ShowShelfBooks(std::string user_name,std::string Shelf_name)
{
  std::string sql = "select * from books where id in (select book_id from own where person_name ='"+user_name+"'and shelf_id=(select id from shelf where owner_name='"+user_name+"'and name='"+Shelf_name+"'))";
  std::vector<std::vector<std::string>> temp= db.execute(sql.c_str());
  for (int i=0;i<temp.size();i++)
  {
    std::cout<<temp[i][0] <<" | "<<temp[i][1] <<" | "<<temp[i][2] <<" | "<<temp[i][3] <<" | "<<temp[i][4] <<"";
    std::cout<<"\n";
  }
  return temp;    
}
std::vector<std::vector<std::string>> ShelfFunctions::ShowMyBooks(std::string user_name)
{
    std::string sql = "select * from books where id in (select book_id from own where person_name ='"+user_name+"'and shelf_id=(select id from shelf where owner_name='"+user_name+"'and name='General'))";
  std::vector<std::vector<std::string>> temp= db.execute(sql.c_str());
  for (int i=0;i<temp.size();i++)
  {
    std::cout<<temp[i][0] <<" | "<<temp[i][1] <<" | "<<temp[i][2] <<" | "<<temp[i][3] <<" | "<<temp[i][4] <<"";
    std::cout<<"\n";
  }
  return temp;   
}
    
    
    
