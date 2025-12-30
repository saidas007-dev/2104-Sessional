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

    int choice, val, pos;
    cout << "\nInsert at:\n1. Beginning\n2. Middle\n3. End\nEnter your choice: ";
    cin >> choice;

    cout << "Enter the value to insert: ";
    cin >> val;

    switch (choice) {
        case 1:
            for (int i = size - 1; i >= 0; i--) {
                arr[i + 1] = arr[i];
            }
            arr[0] = val;
            size++;
            break;

        case 2:
            cout << "Enter the position to insert (1 to " << size + 1 << "): ";
            cin >> pos;
            if (pos < 1 || pos > size + 1) {
                cout << "Invalid position." << endl;
                return 0;
            }
            for (int i = size - 1; i >= pos - 1; i--) {
                arr[i + 1] = arr[i];
            }
            arr[pos - 1] = val;
            size++;
            break;

        case 3:
            arr[size] = val;
            size++;
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
