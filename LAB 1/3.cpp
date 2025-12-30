#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter Array Size: ";
    cin >> size;

    int arr[100];
    for (int i = 0; i < size; i++) {
        cout << "Enter " << (i + 1) << "th Element: ";
        cin >> arr[i];
    }

    int choice, pos;
    cout << "\nDelete from:\n1. Beginning\n2. Middle\n3. End\nEnter your choice: ";
    cin >> choice;

    if (size == 0) {
        cout << "Array is empty. Nothing to delete." << endl;
        return 0;
    }

    switch (choice) {
        case 1:
            for (int i = 1; i < size; i++) {
                arr[i - 1] = arr[i];
            }
            size--;
            break;

        case 2:
            cout << "Enter the position to delete (1 to " << size << "): ";
            cin >> pos;
            if (pos < 1 || pos > size) {
                cout << "Invalid position." << endl;
                return 0;
            }
            for (int i = pos; i < size; i++) {
                arr[i - 1] = arr[i];
            }
            size--;
            break;

        case 3:
            size--;
            break;

        default:
            cout << "Invalid choice." << endl;
            return 0;
    }

    cout << "Updated Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
