//validate IP address with few constrains
#include<iostream>
#include<string.h>
#include<sstream>
using namespace std;
bool isValid(char *s)
{
    int n= strlen(s);
    
    //(1) if the length of the string is greater than 3 in each field then it is a invalid IP
    if((n== 0 && n>3))
    false;
    //(2) check if the string has only integers digits
    for(int i=0;i<n;i++)
    {
        if((s[i] >= '0' && s[i] <= '9') ==false) return false;
    }
    std::string str(s);
    
    //(3) if the IP has 00 0r 005 it is a invalid IP
    if(str.find('0')==false && n>1)
    {
        return false;
    }
    //convert the IP from string to int datatype;
    stringstream ss(str);
    int field;
    ss >> field;
    return (field >=0 && field <=255) ? true :false;
    
}
int validateIP(char* ip)
{
        char* token;  
        int rawdataDots=0;
    int dots=0; // to check the Location of the '.', if 3 dots found.

    if(ip ==NULL) return false;
    for(int i=0;i<strlen(ip);i++)
    {
        if(ip[i]=='.') ++rawdataDots;
    }
    if(rawdataDots !=3) return 0;
    token=strtok(ip, ".");
    if(token == NULL)
     return 0;
     while(token)
     {
         if(isValid(token))
         {
             //parse the remaining string 
             token=strtok(NULL, ".");
             {
                 if(token != NULL)
                     ++dots;
             }
         }
         else 
         return 0;
     }
    if(dots !=3) return 0;
    
  return 1;
}
int main()
{
    int result=0;
char ip1[] ="244.12.1456.2";
char ip2[] ="78.123.456.2";
char ip3[] ="78.165.26.1";
 validateIP(ip1) ? cout<<"valid IP \n" : cout<<"invalid IP\n";
 validateIP(ip2) ? cout<<"valid IP \n" : cout<<"invalid IP\n";
 validateIP(ip3) ? cout<<"valid IP \n" : cout<<"invalid IP\n";
}