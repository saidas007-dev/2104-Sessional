#include <bits/stdc++.h>
using namespace std;

int main() {
  int size1;
  cout << "Enter  size of Array One :";
  cin >> size1;
  int arr1[size1];

  cout << "For Array One:" << endl;
  for (int i = 0; i < size1; i++) {
    cout << "Enter " << (i + 1) << "th Element :";
    cin >> arr1[i];
    cout << endl;
  }

  int size2;
  cout << "Enter  size of Array Two :";
  cin >> size2;
  int arr2[size2];

  cout << "For Array Two:" << endl;
  for (int i = 0; i < size2; i++) {
    cout << "Enter " << (i + 1) << "th Element :";
    cin >> arr2[i];
    cout << endl;
  }
size2=size1+size2;
  for (int k = 0; k < size1; k++) {
    arr2[size1 + k] = arr1[k];
  }

  cout << "Array Two After Copy  :";

  for (int i = 0; i < size2; i++) {
    cout << arr2[i] << " ";
  }

  return 0;
}
