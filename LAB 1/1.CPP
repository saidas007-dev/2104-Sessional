#include <bits/stdc++.h>
using namespace std;

void bubblesort(int arr[], int size)
{

    for(int i=0;i<size -1 ; i++)
    {
        for(int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
              }
          }
      }
  }

int main() {
  int x;
  int size;
  cout << "Enter Array Size:";
  cin >> size;
  int arr[size];

  for (int i = 0; i < size; i++) {
    cout << "Enter " << (i + 1) << "th Element :";
    cin >> arr[i];
    cout << endl;
  }

  cout << "The Array Elements Are :";

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  


  return 0;
}
