#include<bits/stdc++.h>
using namespace std;

int main()
{
  int size ;
  cout<<"Enter Array Size:"; cin>>size;
int arr[size];

for (int i=0;i<size;i++)
{
  cout<<"Enter "<<(i+1)<<"th Element :";
  cin>>arr[i];
  cout<<endl;
}
int max=arr[0]; int min=arr[0];

for(int i=0;i<size;i++)
{
  if(arr[i]>max) max=arr[i];
  if(arr[i]<min) min=arr[i];
}

cout<<"The  Max and Mins Values Are :"<<max<<" "<<min;

return 0;
}
