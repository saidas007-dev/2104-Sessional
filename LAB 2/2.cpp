#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

struct node {
  int data;
  struct node *ptr;
};

struct node *createnode() {
  int val;
  cout << "Enter value : ";
  cin >> val;
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = val;
  newnode->ptr = nullptr;
  return newnode;
}

void printlist(struct node *node) {
  cout << "The List value Is:";
  while (node != nullptr) {
    cout << node->data << "  ";
    node = node->ptr;
  }
}

struct node *reversenode(struct node *head)

{
  struct node *prev;
  struct node *curr;
  struct node *next;
  prev = nullptr;
  next = nullptr;
  curr = head;
  while (curr != nullptr) {
    next = curr->ptr;
    curr->ptr = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

int main() {

  struct node *head = nullptr;
  struct node *temp = nullptr;

  int list_size;
  cout << "Enter List Size:";
  cin >> list_size;
  for (int i = 0; i < list_size; i++) {
    cout << "Enter " << (i + 1) << "Th Element :" << endl;
    struct node *newnode = createnode();
    if (head == nullptr) {
      head = temp = newnode;
    }

    else {
      temp->ptr = newnode;
      temp = newnode;
    }
  }
  temp = head;
  cout << "The Node Before Reversing :" << endl;
  printlist(temp);

  struct node *reversednode = reversenode(head);

  cout << "The Node After Reversing :" << endl;
  printlist(reversednode);

  return 0;
}
