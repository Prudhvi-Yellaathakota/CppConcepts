//Move the duplicate elements into the end of the Array

#include<iostream>
using namespace std;
void MoveZeros(int* a, int n)
{
	int j=0;
  for(int i=0;i<n;i++)
    if(a[i] !=0)
		a[j++]=a[i];
  while(j<n )
	  a[j++]=0;
}
void PrintArray(const int *arr,const int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
int arr[]={2,5,0,3,0,0,23,0};
MoveZeros(arr,8);
PrintArray(arr,8);
return 0;
}

/*
=======
output:
=======
input:  {2,5,0,3,0,0,23,0}

o/p:   2,5,3,23,0,0,0,0

*/