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
  cout << "The Array Elements Are (Before Sorting) :";

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  cout << "The Array Elements Are (After Sorting) :";

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
