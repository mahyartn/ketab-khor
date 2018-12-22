#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sqlite3.h>
#include<iostream>

int argc1=0;
   std::vector < char*> argv1;

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   std::vector<std::vector<std::string>>* myvec = (std::vector<std::vector<std::string>>*)data;
   std::vector<std::string> temp1;
   for(i = 0; i<argc; i++) {
      temp1.push_back(argv[i]);
   }
   myvec->push_back(temp1);
   return 0;
}

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char const *sql;
   const char* data = "Callback function called";
   std::vector<std::vector<std::string>> str_vec;


    // You can get current size by using size()
   
   
   /* Open database */
   rc = sqlite3_open("test.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create merged SQL statement */
   sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1; " \
         "SELECT * from COMPANY where id=10";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, (void*) &str_vec, &zErrMsg);
   
   if (str_vec.size()==0) printf ("not found\n"); 
   //else printf ("%s is the first one\n",argv1[0]);
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operation done successfully\n");
   }

   sqlite3_close(db);

    std::cout << "Current size of row vector: " << str_vec.size() << std::endl;
    std::cout << "Current size of width vector: " << str_vec[0].size() << std::endl;
    std::cout << str_vec[1][0] << std::endl;

   return 0;
}