
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

void display(struct node *head) {
  struct node *temp = head;
  do {
    cout << temp->data << " ";
    temp = temp->ptr;
  } while (temp != head);
  cout << endl;
}

struct node *insertnode(struct node *head, struct node *tail, int &list_size) {
  int choice;
  cout << "Enter Your Choice For Insertion (1 = Beginning, 2 = Any Position, 3 "
          "= End): "
       << endl;
  cin >> choice;
  struct node *newnode = createnode();

  if (choice == 1) {
    newnode->ptr = head;
    head = newnode;
    tail->ptr = head;
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

  if (choice == 3) {
    if (head == NULL) {
      head = newnode;
    } else {
      struct node *temp = tail;
      tail->ptr = newnode;
      tail = newnode;
      tail->ptr = head;
      list_size++;
      return head;
    }
  }

  cout << "Invalid Choice!" << endl;
  exit(1);
}

struct node *deletenode(struct node *head, struct node *tail, int &list_size) {
  int choice;
  cout << "Enter Your Choice For Deletion  (1 = Beginning, 2 = Any Position, 3 "
          "= End): "
       << endl;
  cin >> choice;

  if (choice == 1) {
    struct node *temp = head;
    head = temp->ptr;
    tail->ptr = head;
    list_size--;
    free(temp);
    return head;
  }

  if (choice == 2) {

    int pos;
    cout << "Enter The Position To Delete: " << endl;
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
      struct node *flag = temp->ptr;
      temp->ptr = flag->ptr;
      free(flag);
    }
    list_size--;
    return head;
  }

  if (choice == 3) {
    {
      struct node *temp = head;
      while (temp->ptr != tail) {
        temp = temp->ptr;
      }

      struct node *flag = temp;
      tail = flag;
      tail->ptr = head;
      free(flag->ptr);
      list_size--;
      return head;
    }
  }

  cout << "Invalid Choice!" << endl;
  exit(1);
}

int main() {
  struct node *head = NULL;
  struct node *tail = NULL;

  int list_size;
  cout << "Enter The Length Of The List: ";
  cin >> list_size;

  for (int i = 0; i < list_size; i++) {
    struct node *newnode = createnode();
    if (head == NULL) {
      head = tail = newnode;
    } else {
      tail->ptr = newnode;
      tail = newnode;
      tail->ptr = head;
    }
  }

  cout << "The Circular Linked List (Before Insertion): ";
  display(head);

  head = insertnode(head, tail, list_size);

  cout << "The Circular Linked List (After Insertion): ";
  display(head);
  head = deletenode(head, tail, list_size);
  cout << "The Circular Linked List (After Deletion): ";
  display(head);

  return 0;
}
