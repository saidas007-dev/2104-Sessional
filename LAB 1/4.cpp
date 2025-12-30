#include <bits/stdc++.h>
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

  int val;
  cout << "Enter Key Value:";
  cin >> val;

  for (int i = 0; i < size; i++) {
    if (arr[i] == val) {
      cout << "Value is Found ";
      return 0;

    }

    else {
      cout << "Value Not Found.";
    }
  }

  return 0;
}
