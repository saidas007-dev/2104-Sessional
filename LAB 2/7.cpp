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
  cout << endl;

  int keyval;
  cout << "Enter Key Value: ";
  cin >> keyval;
  cout << endl;

  int count = 0;
  int flag = 0;
  int i = 0;
  for (; i < size; i++) {
    count++;
    if (arr[i] == keyval) {

      flag++;
    }
  }
  if (flag != 0) {
    cout << "The value Is Found At " << (i + 1) << "Th Position ." << endl;
  } else
    cout << "The value Not Found." << endl;
  cout << "It Took " << count << " Number Of Comparisions" << endl;
  return 0;
}
