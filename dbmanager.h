#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <stdio.h>
#include "basic.h"



class BookFunctions
{
    private:
    MyDataBase db;
    public:
    BookFunctions(MyDataBase &database);
    std::vector<std::vector<std::string>> AllBooks();
    std::vector<std::vector<std::string>> Book(std::string id);
    bool LikeBook(std::string id,std::string username);
    bool BuyBook(std::string id,std::string username);
//bool BuyBook(std::string id,std::string username,std::string shelf_name);
};

class ShelfFunctions
{
    private:
    MyDataBase db;
    public:
    ShelfFunctions(MyDataBase &database);
    bool AddShelf(std::string shelf_name,std::string user_name);
    int AddToShelf(std::string shelf_name,std::string user_name,std::string book_id);
    std::vector<std::vector<std::string>> ShowShelves(std::string user_name);
    std::vector<std::vector<std::string>> ShowShelfBooks(std::string user_name,std::string Shelf_name);
    
    // std::vector<std::vector<std::string>> Book(std::string id);
    // bool LikeBook(std::string id,std::string username);
    // bool BuyBook(std::string id,std::string username);
//bool BuyBook(std::string id,std::string username,std::string shelf_name);
};


#endif