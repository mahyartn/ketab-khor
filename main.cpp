#include <fstream>
#include <iostream>

#include <vector>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "basic.h"
#include "shelfman.h"
#include "bookman.h"
#include "accounting.h"
#include "social.h"




int main()
{
    MyDataBase db1("mydatabase.db");
    AccountManager ali(db1);
    ali.Authenticate("admin","astro321");
    
    ali.AddUser("mahdi","astro321");
    BookFunctions books(db1);
    ShelfFunctions shelves(db1);
    Social comunity(db1);
    books.AllBooks();
    books.Book("10");
    books.LikeBook("13","mahyar");
    books.BuyBook("1","mahyar");
    books.FavoriteBooks("mahyar");
    shelves.AddShelf("Fiction","mahyar");
    shelves.AddToShelf("Fiction","mahyar","1");
    shelves.ShowShelves("mahyar");
    shelves.ShowShelfBooks("mahyar","Fiction");
    shelves.ShowMyBooks("mahyar");
    comunity.Follow("mahdi","mahyar");
    comunity.GetLastTime("mahyar");
    comunity.SetLastTime("mahyar");
    //comunity.GetNewLikes("mahdi","2018-12-22 00:01:59");
    comunity.GetNewOwned("mahdi","2017-12-22 00:01:59");
    comunity.GetNewFriends("mahdi","2017-12-22 00:01:59");
    //std::cout<<ali.Authenticate("mahyar","astro123")<<"\n";
}
 