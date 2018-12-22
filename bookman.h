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
    bool LikeBook(std::string id,std::string username);
    bool BuyBook(std::string id,std::string username);
//bool BuyBook(std::string id,std::string username,std::string shelf_name);
};


#endif