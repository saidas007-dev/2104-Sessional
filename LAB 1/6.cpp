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
  int i = size - 1;
  int j = 0;
  int temp;
  for (; (j < size &&  i > 0); i--, j++) {
    temp = arr[i];
    arr[i] = arr[j];
    arr[j]=temp;
  }

  cout << "The Array Elements Are (After Reversing) :";

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
