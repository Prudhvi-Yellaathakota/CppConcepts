// fileName:
/* To find Endianess of your system
* little Endian: 
Eg: 0x2341
little endian: 0x23, 0x41
  Big Endian(network byte order)
  big endian: 0x41, 0x23
*/
#include<iostream>
using namespace std;
int main()
{
    int i = 4;
    char* ptr = (char*) & i;
    if(*ptr) std::cout<<"Little endian";
    else 
    std::cout<<"Big Endian";
    return 0;
}