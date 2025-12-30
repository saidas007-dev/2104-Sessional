#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *ptr;
};

struct node *createnode() {
    int data;
    cout << "Enter Value: ";
    cin >> data;

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->ptr = NULL;
    return newnode;
}


struct node *insertionsort(struct node *head, int list_size) {
    if (head == NULL || head->ptr == NULL)
        return head;

    struct node *sorted = NULL;

    struct node *cur = head;
    while (cur != NULL) {
        struct node *next = cur->ptr;


        if (sorted == NULL || cur->data < sorted->data) {
            cur->ptr = sorted;
            sorted = cur;
        } else {
            struct node *temp = sorted;
            while (temp->ptr != NULL && temp->ptr->data < cur->data) {
                temp = temp->ptr;
            }
            cur->ptr = temp->ptr;
            temp->ptr = cur;
        }

        cur = next;
    }
    return sorted;
}

struct node* middle(struct node* start, struct node* end) {
    if (start == NULL)
        return NULL;

    struct node *slow = start;
    struct node *fast = start->ptr;

    while (fast != end) {
        fast = fast->ptr;
        if (fast != end) {
            slow = slow->ptr;
            fast = fast->ptr;
        }
    }
    return slow;
}


void binarysearch(struct node* head, int list_size) {
    int key;
    cout << "Enter Value To Search: ";
    cin >> key;

    struct node *start = head;
    struct node *end = NULL;

    int count = 1;

    while (start != end) {
        struct node *mid = middle(start, end);

        if (mid == NULL) {
            cout << "Not Found" << endl;
            return;
        }

        if (mid->data == key) {
            cout << "Found After " << count << " Steps." << endl;
            cout << "Value = " << mid->data << endl;
            return;
        }
        else if (mid->data < key) {
            start = mid->ptr;
        }
        else {
            end = mid;
        }

        count++;
    }

    cout << "Value Not Found" << endl;
}

void display(struct node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->ptr;
    }
    cout << endl;
}

int main() {
    struct node *head = NULL;
    struct node *temp = NULL;

    int list_size;
    cout << "Enter The Length Of The List: ";
    cin >> list_size;

    for (int i = 0; i < list_size; i++) {
        struct node *newnode = createnode();

        if (head == NULL)
            head = temp = newnode;
        else {
            temp->ptr = newnode;
            temp = newnode;
        }
    }

    cout << "The Linked List Is: ";
    display(head);

    head = insertionsort(head, list_size);

    cout << "The Sorted Linked List Is: ";
    display(head);

    binarysearch(head, list_size);

    return 0;
}
