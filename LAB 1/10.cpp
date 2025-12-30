#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
  int size1;
  cout << "Enter size of Array One :";
  cin >> size1;
  int arr1[size1];
  cout << "For Array One:\n";

  for (int i = 0; i < size1; i++) {
    cout << "Enter " << (i + 1) << "th Element :";
    cin >> arr1[i];
    cout << endl;
  }

  int size2;
  cout << "Enter size of Array Two :";
  cin >> size2;
  int arr2[size2];
  cout << "For Array Two:\n";

  for (int i = 0; i < size2; i++) {
    cout << "Enter " << (i + 1) << "th Element :";
    cin >> arr2[i];
    cout << endl;
  }
  int size3 = size1 + size2;
  int arr3[size3];

  for (int k = 0; k < size1; k++) {
    arr3[k] = arr1[k];
  }

  int i = 0;
  for (int l = size1; l < size3; l++) {
    arr3[l] = arr2[i++];
  }

  cout << "Array After Merging: ";
  for (int i = 0; i < size3; i++) {
    cout << arr3[i] << " ";
  }

  return 0;
}
