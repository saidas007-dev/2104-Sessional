#include <bits/stdc++.h>
using namespace std;

void sortarray(int *arr, int len) {
  for (int i = 0; i < len - 1; i++) {
    int flag = 0;
    for (int j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        flag++;
      }
    }
    if (flag == 0)
      break;
  }
}

int binarysearch(int *arr, int len) {
  int keyval;
  cout << "Enter The value You Want To Search : ";
  cin >> keyval;

  int count = 1;
  int start = 0;
  int end = len - 1;

  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (arr[mid] == keyval) {
      cout << "It Took " << count << " Comparisions." << endl;
      return mid;
    } else if (arr[mid] < keyval) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }

    count++;
  }

  return -1;
}

int main() {
  int len;
  cout << "Enter Array Size: ";
  cin >> len;

  int arr[len];

  for (int i = 0; i < len; i++) {
    cout << "Enter " << (i + 1) << "th Element: ";
    cin >> arr[i];
  }

  cout << "The Array Elements Are (Before Sorting): ";
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  sortarray(arr, len);

  cout << "The Array Elements Are (After Sorting): ";
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  int index = binarysearch(arr, len);

  if (index == -1)
    cout << "The Value Was Not Found" << endl;
  else
    cout << "Value Found At Index: " << index << endl;

  return 0;
}
