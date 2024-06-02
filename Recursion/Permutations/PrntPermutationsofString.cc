/** Print all permutations of a string
 * Filename: PrntPermutationsofString.cc
 * Eg: string str = "ABCD";
 * output: { ABCD,}
 * TODO: Generate Doxygen tool for the comment
*/
#include<iostream>
#include<string>
using namespace std;
void printPermutations(string& str, int startPos, int endPos, int& count)
{
    if(startPos == endPos)
    {
        count++;
        std::cout<<"count: "<<count<< " "<<str<<std::endl;
        return;
    }
    else
    {
        for(int i = startPos; i <= endPos; i++)
        {
            swap(str[i], str[startPos]); 
            printPermutations(str, startPos+1, endPos, count);
            swap(str[i], str[startPos]);
        }
    }
    return;
}
int main()
{
    std::string input;
    cout<<"Enter string: ";cin>>input;
    std::cout<<std::endl;
    int count = 0;
    printPermutations(input, 0,input.size()-1, count);
    return 0;
}

/*Problem intutive
in first element swap(str[0], str[strtpos]) = swap(A, A); (nothing)
 then Permutate to the next elements by fixing the first index in String AXXX= A(Permutate(str, 1, end, count));
 Final swap is used to regain the string to normal position

* 2nd iteration
 int i= startPos = index1 = B
  swap(B, startPos); //fix the B at index 0 then find permutations for BXXX;
  Afterswapping str = BACD
  Permutate(str, startpos + 1, endPos); = (str, 1, n-1);
  final swap: swap(str[i], str[startPos]) = swap(A, B);
  after final swap: ABCD;

*/