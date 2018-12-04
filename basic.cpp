#include <basic.h>


void AccountExtractor(std::string& line,char& devider,std::vector<user> &list)
{
    user temp;
    int pos=line.find(devider);
    temp.UserName=line.substr(0,pos);
    temp.Password=line.substr(pos+1,line.length());
    list.push_back(temp);
}
