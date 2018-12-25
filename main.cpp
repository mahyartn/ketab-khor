
#include "basic.h"
#include "shelfman.h"
#include "bookman.h"
#include "accounting.h"
#include "social.h"
#include "inteface.h"

int main()
{
    AInterface account;
    account.Login();
    BInterface Bfuncs(*account.db,account.CurrentUser());
    SInterface Sfuncs(*account.db,account.CurrentUser());
    SCInterface SCfuncs(*account.db,account.CurrentUser());
    // Bfuncs.ShowAllBooks();
    // Bfuncs.ShowOneBook();
    // Bfuncs.LikeBook();
    // Bfuncs.BuyBook();
    // Bfuncs.ShowFavoriteBooks();
    // Sfuncs.ShowMyBooks();
    // Sfuncs.ShowShelves();
    // Sfuncs.ShowShelfBooks();
    // Sfuncs.AddShelf();
    // Sfuncs.AddToShelf();
    // SCfuncs.Follow();
    SCfuncs.ShowUpdates();
    // std::cout<<test.acman->current_session_id<<"jj\n";
    // MyDataBase db1("mydatabase.db");
    // AccountManager ali(db1);
    // BookFunctions books(db1);
    // ShelfFunctions shelves(db1);
    // Social comunity(db1);
    // ali.Authenticate("admin","astro321");
    // ali.AddUser("mahdi","astro321");
    // books.AllBooks();
    // books.Book("10");
    // books.LikeBook("13","mahyar");
    // books.BuyBook("1","mahyar");
    // books.FavoriteBooks("mahyar");
    // shelves.AddShelf("Fiction","mahyar");
    // shelves.AddToShelf("Fiction","mahyar","1");
    // shelves.ShowShelves("mahyar");
    // shelves.ShowShelfBooks("mahyar","Fiction");
    // shelves.ShowMyBooks("mahyar");
    // comunity.Follow("mahdi","mahyar");
    // comunity.GetLastTime("mahyar");
    // comunity.SetLastTime("mahyar");
    // comunity.GetNewLikes("mahdi","2018-12-22 00:01:59");
    // comunity.GetNewOwned("mahdi","2017-12-22 00:01:59");
    // comunity.GetNewFriends("mahdi","2017-12-22 00:01:59");
    // std::cout<<ali.Authenticate("mahyar","astro123")<<"\n";
}
 