#ifndef BASIC_H
#define BASIC_H
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

class user
{
    public:
    std::string UserName;
    std::string Password;
};

void AccountExtractor(std::string& line,char& devider,std::vector<user> & list);


#endif