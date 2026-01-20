
#include <bits/stdc++.h>
#include <cstddef>

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

struct node *insertnode(struct node *head, int &list_size) {
  int choice;
  cout << "Enter Your Choice (1 = Beginning, 2 = Any Position, 3 = End): "
       << endl;
  cin >> choice;
  struct node *newnode = createnode();

  if (choice == 1) {
    newnode->ptr = head;
    head = newnode;
    list_size++;
    return head;
  }

  if (choice == 2) {

    int pos;
    cout << "Enter The Position To Insert: " << endl;
    cin >> pos;

    if (choice == 2 && (pos < 1 || pos > list_size + 1)) {
      cout << "Invalid Position." << endl;
      exit(0);
    }

    {
      struct node *temp = head;
      for (int i = 1; i < pos - 1; i++) {
        temp = temp->ptr;
      }
      newnode->ptr = temp->ptr;
      temp->ptr = newnode;
    }
    list_size++;
    return head;
  }

  if (choice == 3 ) {
    if (head == NULL) {
      head = newnode;
    } else {
      struct node *temp = head;
      while (temp->ptr != NULL) {
        temp = temp->ptr;
      }
      temp->ptr = newnode;
    }
    list_size++;
    return head;
  }

  cout << "Invalid Choice!" << endl;
  exit(1);
}

int main() {
  struct node *head = NULL;
  struct node *temp = NULL;

  int list_size;
  cout << "Enter The Length Of The List: ";
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

  cout << "The Linked List (Before Insertion): ";
  display(head);

  head = insertnode(head, list_size);

  cout << "The Linked List (After Insertion): ";
  display(head);

  return 0;
}
