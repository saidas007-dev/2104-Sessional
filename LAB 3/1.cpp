#include <bits/stdc++.h>
using namespace std;

void bubblesort(int arr[], int len) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int flag = 0;
    for (int j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        flag++;
      }
      count++;
    }
    if (flag == 0) {
      cout << "It Took " << count << "Number Of Comparisons ." << endl;
    }
  }
  cout << "It Took " << count << "Number Of Comparisons ." << endl;
}

void printarray(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
}

int main() {

  int len;
  cout << "Enter Array Size :";
  cin >> len;

  int arr[1000];

  for (int i = 0; i < len; i++) {
    cout << "Enter " << (i + 1) << " Th Element :";
    cin >> arr[i];
    cout << endl;
  }

  cout << "Array After Sorting : " << endl;
  bubblesort(arr, len);
  int rand[] = {10, 9, 8, 7, 6, 5, 4};
  bubblesort(rand, sizeof(rand));
  printarray(rand, sizeof(rand));

  return 0;
}
