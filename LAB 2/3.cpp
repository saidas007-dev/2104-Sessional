#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int list_size;
struct node {
  int data;
  struct node *prev;
  struct node *next;
};

struct node *createnode() {
  int val;
  cout << "Enter Value :";
  cin >> val;
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = val;
  newnode->prev = nullptr;
  newnode->next = nullptr;
  return newnode;
}

void printlist(struct node *node) {
  cout << "The List value Is:";
  while (node != nullptr) {
    cout << node->data << "  ";
    node = node->next;
  }
}

struct node *insert(struct node *head, struct node *tail, int list_size) {
  int pos;
  cout << "Enter The Position You Want To Insert :";
  cin >> pos;
  if (pos < 1 || pos > list_size + 1) {
    cout << "Invalid Position. " << endl;
    exit(1);
  }
  struct node *newnode = createnode();
  struct node *temp;
  if (pos == 1) {
    ;
    newnode->next = head;
    head->next = newnode;
    head = newnode;
    return head;
  }

  if (pos == list_size) {

    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
    return head;



  } else {
    {
      int i = 1;
      temp = head;
      while (i < pos) {
        temp = temp->next;
        i++;
      }
      newnode->next = temp->next;
      newnode->prev = temp;
      temp->next->prev = newnode;
      temp->next = newnode;

      return head;
    }
  }
}

int main() {

  struct node *head = nullptr;
  struct node *tail = tail = nullptr;

  cout << "Enter List Size:";
  cin >> list_size;

  for (int i = 0; i < list_size; i++) {
    struct node *newnode = createnode();
    if (head == nullptr) {
      head = tail = newnode;

    }

    else {
      {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
      }
    }
  }
  struct node *temp;
  temp = head;
  cout << "The List Is(Before Insertion) :" << endl;
  printlist(temp);

  temp = insert(head, tail, list_size);

  cout << "The List Is(After Insertion) :" << endl;
  printlist(temp);

  return 0;
}
