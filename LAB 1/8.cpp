#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
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

  int odd = 0;
  int even = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 0)
      even++;
    else
      odd++;
  }

  cout << "Number Of Even And Odd Elements Are:" << even << " And " << odd;
  return 0;
}
