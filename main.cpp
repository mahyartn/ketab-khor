#include <fstream>
#include <iostream>

#include <vector>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "basic.h"
#include "dbmanager.h"
#include "accounting.h"




int main()
{
    MyDataBase db1("mydatabase.db");
    AccountManager ali(db1);
    ali.Authenticate("admin","astro321");
    
    //ali.AddUser("mahyar","astro321");
    BookFunctions books(db1);
    books.AllBooks();
    books.Book("10");
    books.LikeBook("2","mahyar");
    books.BuyBook("10","mahyar");
    //std::cout<<ali.Authenticate("mahyar","astro123")<<"\n";
}
 