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

bool isCircular(struct node *head) {
  if (!head)
    return false;

  node *curr = head;
  node *next = head;

  while (next && next->ptr) {
    curr = curr->ptr;
    next = next->ptr->ptr;
    if (curr == next)
      return true;
  }
  return false;
}

void display(struct node *head) {
  if (!head) {
    cout << "List Is Empty." << endl;
    return;
  }

  node *temp = head;
  bool circular = isCircular(head);

  do {
    cout << temp->data << " ";
    temp = temp->ptr;
  } while (temp && temp != head);

  cout << endl;
}

int main() {
  node *linear_head = NULL, *linear_temp = NULL;
  node *circular_head = NULL, *circular_tail = NULL;

  int list_size;
  cout << "Enter The Length Of The List: ";
  cin >> list_size;

  int choice;
  cout << "Enter Your Choice (1 = Linear, 2 = Circular): ";
  cin >> choice;

  if (choice == 1) {
    for (int i = 0; i < list_size; i++) {
      node *newnode = createnode();
      if (!linear_head)
        linear_head = linear_temp = newnode;
      else {
        linear_temp->ptr = newnode;
        linear_temp = newnode;
      }
    }
  } else if (choice == 2) {
    for (int i = 0; i < list_size; i++) {
      node *newnode = createnode();
      if (!circular_head)
        circular_head = circular_tail = newnode;
      else {
        circular_tail->ptr = newnode;
        circular_tail = newnode;
      }
    }
    if (circular_tail)
      circular_tail->ptr = circular_head;
  }

  cout << "\nLinear Linked List: ";
  display(linear_head);

  cout << "Circular Linked List: ";
  display(circular_head);

  cout << "\nLinear List Circular? " << (isCircular(linear_head) ? "YES" : "NO")
       << endl;
  cout << "Circular List Circular? "
       << (isCircular(circular_head) ? "YES" : "NO") << endl;

  return 0;
}
