#include "shelfman.h"


ShelfFunctions::ShelfFunctions(MyDataBase &database)
{
  db=database;
}
bool ShelfFunctions::AddShelf(std::string shelf_name,std::string user_name)
{
  std::string sql = "select id from Shelf where owner_name='"+ user_name + "'and name='"+ shelf_name +"'";
  std::vector<std::vector<std::string>> temp=db.execute(sql.c_str());
  if(temp.size()>0) return 1;
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
  return temp;     
}
std::vector<std::vector<std::string>> ShelfFunctions::ShowShelfBooks(std::string user_name,std::string Shelf_name)
{
  std::string sql = "select * from books where id in (select book_id from own where person_name ='"+user_name+"'and shelf_id=(select id from shelf where owner_name='"+user_name+"'and name='"+Shelf_name+"'))";
  std::vector<std::vector<std::string>> temp= db.execute(sql.c_str());
  return temp;    
}
std::vector<std::vector<std::string>> ShelfFunctions::ShowMyBooks(std::string user_name)
{
  std::string sql = "select * from books where id in (select book_id from own where person_name ='"+user_name+"'and shelf_id=(select id from shelf where owner_name='"+user_name+"'and name='General'))";
  std::vector<std::vector<std::string>> temp= db.execute(sql.c_str());
  return temp;   
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

SInterface::SInterface(MyDataBase &db,std::string Username)
{
  DB=db;
  CurrentUser=Username;
  shelf=new ShelfFunctions(DB);
}

void SInterface::ShowMyBooks()
{
    system("clear");
    std::vector<std::vector<std::string>> temp=shelf->ShowMyBooks(CurrentUser);
    if (temp.size()>0) ShowBook(temp);
    else std::cout <<"No Books!!\n";
    std::cout<<"(Press ENTER To Continue....)\n";
    std::cin.ignore();
    std::cin.get();

}

void SInterface::ShowShelfBooks()
{
    system("clear");
    std::cout << "Please Enter the Shelf name you Like to see: ";
    std::string shelf_name;
    std::cin >> shelf_name;
    std::vector<std::vector<std::string>> temp=shelf->ShowShelfBooks(CurrentUser,shelf_name);
    if (temp.size()>0) ShowBook(temp);
    else std::cout <<"No Books!!\n";
    std::cout<<"(Press ENTER To Continue....)\n";
    std::cin.ignore();
    std::cin.get();

}

void SInterface::ShowShelves()
{
    system("clear");
    std::vector<std::vector<std::string>> temp=shelf->ShowShelves(CurrentUser);
    if (temp.size()>0) 
    {
      std::cout<<"Shelf Name: \n";
      for (int i=0;i<temp.size();i++)
      {
        std::cout<<"    "<<temp[i][1]<<"\n";
      }
    }
    else std::cout <<"No shelf!!\n";
    std::cout<<"(Press ENTER To Continue....)\n";
    std::cin.ignore();
    std::cin.get();
}

void SInterface::AddShelf()
{
    system("clear");
    std::cout << "Please Enter New Shelf name: ";
    std::string shelfname;
    std::cin >> shelfname;
    bool temp=shelf->AddShelf(shelfname,CurrentUser);
    if (temp) std::cout <<"Shelf Exists!\n";
    else std::cout <<"Shelf added successfully.\n";
    std::cout<<"(Press ENTER To Continue....)\n";
    std::cin.ignore();
    std::cin.get();    
}

void SInterface::AddToShelf()
{
    system("clear");
    std::cout << "Please Enter the Shelf you like to use: ";
    std::string shelfname;
    std::cin >> shelfname;
    std::cout << "Please Enter the book ID you like to add: ";
    std::string BookID;
    std::cin >> BookID;
    int temp=shelf->AddToShelf(shelfname,CurrentUser,BookID);
    if (temp==3) std::cout <<"Shelf not found!\n";
    else if (temp==2) std::cout <<"Book not found!\n";
    else if (temp==1) std::cout <<"Book already is in the Shelf!\n";
    else std::cout <<"Book successfully added to Shelf.\n";
    std::cout<<"(Press ENTER To Continue....)\n";
    std::cin.ignore();
    std::cin.get();    
}