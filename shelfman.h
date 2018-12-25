#ifndef SHELFMAN_H
#define SHELFMAN_H

#include <stdio.h>
#include "basic.h"


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
    std::vector<std::vector<std::string>> ShowMyBooks(std::string user_name);
};

class SInterface
{
    private:
    MyDataBase DB;
    std::string CurrentUser;
    ShelfFunctions *shelf;
    public:
    SInterface(MyDataBase &db,std::string Username);
    void ShowMyBooks();
    void ShowShelfBooks();
    void ShowShelves();
    void AddShelf();
    void AddToShelf();
};


#endif