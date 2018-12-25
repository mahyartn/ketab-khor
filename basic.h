#ifndef BASIC_H
#define BASIC_H
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <sqlite3.h> 
#include <unistd.h>
#include <stdio.h>

typedef std::vector<std::vector<std::string>> vvs;

void ShowBook(std::vector<std::vector<std::string>> temp);
    
class MyDataBase 
{
    private:
    sqlite3 *db;
    char *zErrMsg = 0;
    char const *sql;
    static int callback(void *data, int argc, char **argv, char **azColName);
    const char* data;
    public:
    MyDataBase (const char* db_name);
    MyDataBase ();
    vvs execute(const char* sql_command);

};

#endif