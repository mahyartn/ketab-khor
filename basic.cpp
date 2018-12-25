#include "basic.h"


void ShowBook(std::vector<std::vector<std::string>> temp)
{
  std::string BookFields[5]={"ID: ","Book Name: ","Author: ","Publisher: ","Year: "};  
  for (int i=0;i<temp.size();i++)
        {
            for (int j=0;j<5;j++) std::cout <<BookFields[j]<<temp[i][j]<<"\n";
            std::cout <<"\n";
        }
}
    
MyDataBase::MyDataBase()
{
}

MyDataBase::MyDataBase(const char* db_name)
{
    char *zErrMsg = 0; 
    /* Open database */
    auto rc = sqlite3_open(db_name, &db);
    if( rc ) 
    {
       fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    } 
    else 
    {
      fprintf(stderr, "Opened database successfully\n");
    }

}


int MyDataBase::callback(void *data, int argc, char **argv, char **azColName)
{
   int i;
   std::vector<std::vector<std::string>>* myvec = (std::vector<std::vector<std::string>>*)data;
   std::vector<std::string> temp1;
   
   for(i = 0; i<argc; i++) {
      if (argv[i]!= NULL )temp1.push_back(argv[i]);
      else temp1.push_back("");      
   }
   myvec->push_back(temp1);
   
   return 0;
}

std::vector<std::vector<std::string>> MyDataBase::execute(const char* sql_command)
{
    std::vector<std::vector<std::string>> str_vec;
    auto rc = sqlite3_exec(db, sql_command, callback, (void*) &str_vec, &zErrMsg);
    // if( rc != SQLITE_OK ) 
    // {
    //   fprintf(stderr, "SQL error: %s\n", zErrMsg);
    //   sqlite3_free(zErrMsg);
    // } 
    // else ;// fprintf(stdout, "Operation done successfully\n");
    return str_vec;
}
