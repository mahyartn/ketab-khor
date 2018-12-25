#include "bookman.h"



BookFunctions::BookFunctions(MyDataBase &database)
{
  db=database;
}
  //use this code to check the temp strings!
  //for (int i=0;i<temp.size();i++)
  // {
  //   std::cout<<temp[i][0] <<" | "<<temp[i][1] <<" | "<<temp[i][2] <<" | "<<temp[i][3] <<" | "<<temp[i][4] <<"";
  //   std::cout<<"\n";
  // }
std::vector<std::vector<std::string>> BookFunctions::AllBooks()
{
  std::string sql = "select * from books";
  std::vector<std::vector<std::string>> temp= db.execute(sql.c_str());
  return temp;
}

std::vector<std::vector<std::string>> BookFunctions::Book(std::string id)
{
  std::string sql = "select * from books where id="+id;
  std::vector<std::vector<std::string>> temp= db.execute(sql.c_str());
  return temp;
}

int BookFunctions::LikeBook(std::string id,std::string username)
{
  std::string sql = "select id from books where id="+id;
  std::vector<std::vector<std::string>> temp=db.execute(sql.c_str());
  if(temp.size()==0) return 0;
  sql = "select id from likes where person_name='"+ username + "'and book_id="+ id ;
  temp=db.execute(sql.c_str());
  if(temp.size()>0) return 1;
  sql = "insert into likes (person_name,book_id,timestamp) values ('"+ username + "',"+ id +",datetime('now'))";
  db.execute(sql.c_str());
  return 2;
}

int BookFunctions::BuyBook(std::string id,std::string username)
{
  std::string sql = "select id from books where id="+id;
  std::vector<std::vector<std::string>> temp=db.execute(sql.c_str());
  if(temp.size()==0) return 0;
  sql = "select id from own where person_name='"+ username + "'and book_id="+ id ;
  temp=db.execute(sql.c_str());
  if(temp.size()>0) return 1;
  sql = "insert into own (person_name,book_id,shelf_id,timestamp) values ('"+ username + "',"+ id +",(select id from shelf where name='General' and owner_name = '"+username+"'),datetime('now'))";
  db.execute(sql.c_str());
  return 2;
}

std::vector<std::vector<std::string>> BookFunctions::FavoriteBooks(std::string username)
{
  std::string sql = "select * from books where id in (select book_id from likes where person_name= '"+username+"')" ;
  std::vector<std::vector<std::string>> temp=db.execute(sql.c_str());
  return temp;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

BInterface::BInterface(MyDataBase &db,std::string Username)
{
    DB=db;
    CurrentUser=Username;
    Books=new BookFunctions(DB);
}

void BInterface::ShowAllBooks()
{
    std::vector<std::vector<std::string>> temp=Books->AllBooks();
    if (temp.size()>0) ShowBook (temp);
    std::cout<<"(Press ENTER To Continue....)\n";
    std::cin.ignore();
    std::cin.get();
}

void BInterface::ShowOneBook()
{
    system("clear");
    std::cout << "Please Enter the book ID you want to see: ";
    std::string BookID;
    std::cin >> BookID;
    std::vector<std::vector<std::string>> temp=Books->Book(BookID);
    if (temp.size()>0) ShowBook(temp);
    else std::cout <<"Book not found!!\n";
    std::cout<<"(Press ENTER To Continue....)\n";
    std::cin.ignore();
    std::cin.get();
            
}

void BInterface::ShowFavoriteBooks()
{
    system("clear");
    std::vector<std::vector<std::string>> temp=Books->FavoriteBooks(CurrentUser);
    if (temp.size()>0) ShowBook(temp);
    else std::cout <<"No Favorite Books!!\n";
    std::cout<<"(Press ENTER To Continue....)\n";
    std::cin.ignore();
    std::cin.get();
            
}

void BInterface::LikeBook()
{
    system("clear");
    std::cout << "Please Enter the book ID you Like: ";
    std::string BookID;
    std::cin >> BookID;
    int temp=Books->LikeBook(BookID,CurrentUser);
    if (temp==0) std::cout <<"Book not found!\n";
    else if (temp==1) std::cout <<"Book already liked!\n";
    else std::cout <<"Book successfully added to liked.\n";
    std::cout<<"(Press ENTER To Continue....)\n";
    std::cin.ignore();
    std::cin.get();    
}
void BInterface::BuyBook()
{
    system("clear");
    std::cout << "Please Enter the book ID you like to buy: ";
    std::string BookID;
    std::cin >> BookID;
    int temp=Books->BuyBook(BookID,CurrentUser);
    if (temp==0) std::cout <<"Book not found!\n";
    else if (temp==1) std::cout <<"Book already owned!\n";
    else std::cout <<"Book successfully added to library.\n";
    std::cout<<"(Press ENTER To Continue....)\n";
    std::cin.ignore();
    std::cin.get();    
}
