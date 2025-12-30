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

  cout << "Linked List Before Deletion: ";
  display(head);

  int pos;
  cout << "Enter Position to Delete : ";
  cin >> pos;

  if (pos <= 0 || pos > list_size) {
    cout << "Invalid Position" << endl;
    return 0;
  }

  if (pos == 1) {

    struct node *node = head;
    head = head->ptr;
    free(node);
  } else {
    temp = head;
    for (int i = 1; i < pos - 1; i++) {
      temp = temp->ptr;
    }
    struct node *node = temp->ptr;
    temp->ptr = node->ptr;
    free(node);
  }

  cout << "Linked List After Deletion: ";
  display(head);

  return 0;
}
