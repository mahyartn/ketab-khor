#ifndef BOOKMAN_H
#define BOOKMAN_H

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
    int LikeBook(std::string id,std::string username);
    int BuyBook(std::string id,std::string username);
    std::vector<std::vector<std::string>> FavoriteBooks(std::string username);
//bool BuyBook(std::string id,std::string username,std::string shelf_name);
};

class BInterface //accounting interface
{
    private:
    MyDataBase DB;
    std::string CurrentUser;
    BookFunctions* Books;
    public:
    BInterface(MyDataBase &db,std::string Username);
    void ShowAllBooks();
    void ShowOneBook();
    void LikeBook();
    void BuyBook();
    void ShowFavoriteBooks();
};


#endif