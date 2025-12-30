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

void printList(struct node *head) {
  struct node *temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->ptr;
  }
  cout << endl;
}

struct node *reverseList(struct node *head) {
  struct node *prev = NULL;
  struct node *curr = head;
  struct node *next = NULL;

  while (curr != NULL) {
    next = curr->ptr;
    curr->ptr = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

int main() {
  struct node *head = NULL;
  struct node *temp = NULL;

  int list_size;
  cout << "Enter the length of the list: ";
  cin >> list_size;

  for (int i = 0; i < list_size; i++) {
    struct node *newnode = createnode();
    if (head == NULL) {
      head = temp = newnode;
    } else {
      temp->ptr = newnode;
      temp = newnode;
    }
  }

  cout << "List Before Reversing: ";
  printList(head);

  head = reverseList(head);

  cout << "List After Reversing: ";
  printList(head);

  return 0;
}
