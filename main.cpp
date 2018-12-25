
#include "basic.h"
#include "shelfman.h"
#include "bookman.h"
#include "accounting.h"
#include "social.h"
#include "inteface.h"

void func(AInterface account);

std::string menu1="what do you want to do?\n"\
"    1- Sign\n"\
"    2- SingIn\n"\
"    3- Exit\n\n"\
"your choice: ";

std::string menu2="what do you want to do?(type in lower case)\n"\
"    a- Show All Books\n"\
"    b- Show a Book\n"\
"    c- Like a Book\n"\
"    d- Buy a Book\n"\
"    e- Show your favorite books\n"\
"    f- Show your books\n"\
"    g- Show your shelves\n"\
"    h- Show books from a shelf\n"\
"    i- Create a new shelf\n"\
"    j- Add a book to a shelf\n"\
"    k- Follow a person\n"\
"    l- Show latest Updates\n"\
"    z- Logout\n\n"\
"your choice: ";

int main()
{
    AInterface account;
    bool t=true;
    while (t)
    {
        system ("clear");
        std::cout<<menu1;
        char choice;
        std::cin >> choice;  
        switch (choice) 
        {
            case '1':
            account.Register();
            break;
            case '2':
            func(account);
            break;
            case '3':
            t=false;
            break;
            default:
            break;
        }

    }
}

void func(AInterface account)
    {
    account.Login();
    BInterface Bfuncs(*account.db,account.CurrentUser());
    SInterface Sfuncs(*account.db,account.CurrentUser());
    SCInterface SCfuncs(*account.db,account.CurrentUser());
    bool h=true;
    while(h)
    {
        std::cout<<menu2;
        char choice;
        std::cin >> choice;  
        switch (choice) 
        {
            case 'a':
            Bfuncs.ShowAllBooks();
            break;
            case 'b':
            Bfuncs.ShowOneBook();
            break;
            case 'c':
            Bfuncs.LikeBook();
            break;
            case 'd':
            Bfuncs.BuyBook();
            break;
            case 'e':
            Bfuncs.ShowFavoriteBooks();
            break;
            case 'f':
            Sfuncs.ShowMyBooks();
            break;
            case 'g':
            Sfuncs.ShowShelves();
            break;
            case 'h':
            Sfuncs.ShowShelfBooks();
            break;
            case 'i':
            Sfuncs.AddShelf();
            break;
            case 'j':
            Sfuncs.AddToShelf();
            break;
            case 'k':
            SCfuncs.Follow();
            break;
            case 'l':
            SCfuncs.ShowUpdates();
            break;
            case 'z':
            h=false;
            break;
            default:
            break;
        }
    }
}
    
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
    // SCfuncs.ShowUpdates();
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
    // }
 