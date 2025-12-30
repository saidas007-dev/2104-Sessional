
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


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

struct node *sort_list(struct node *head, int list_size) {

  struct node *flag_node = head;

  for (int i = 0; i < list_size - 1; i++) {
    for (int j = 0; j < list_size - i - 1; j++) {
      int val;
      if (flag_node->data > flag_node->next->data) {
        val = flag_node->data;
        flag_node->data = flag_node->next->data;
        flag_node->next->data = val;
      }
    }
  }

  return head;
}

int main() {
  int list_size;
  cout << "Enter List Size: ";
  cin >> list_size;
  struct node *head = nullptr;
  struct node *tail = nullptr;
  for (int i = 0; i < list_size; i++) {
    struct node *newnode = createnode();
    if (head == nullptr) {
      head = tail = newnode;
    } else {
      newnode->prev = tail;
      tail->next = newnode;
      tail = newnode;
    }
  }

  cout << "The List Before Insertion :" << endl;
  printlist(head);

  struct node *node = sort_list(head, list_size);
  list_size++;
  cout << "List After Sorting :";
  printlist(node);
  return 0;
}
