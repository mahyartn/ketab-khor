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
    vvs AllBooks();
    vvs Book(std::string id);
    int LikeBook(std::string id,std::string username);
    int BuyBook(std::string id,std::string username);
    vvs FavoriteBooks(std::string username);
//bool BuyBook(std::string id,std::string username,std::string shelf_name);
};

class BookCLI //accounting interface
{
    private:
    MyDataBase DB;
    std::string CurrentUser;
    BookFunctions* Books;
    public:
    BookCLI(MyDataBase &db,std::string Username);
    void ShowAllBooks();
    void ShowOneBook();
    void LikeBook();
    void BuyBook();
    void ShowFavoriteBooks();
};


#endif