#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node *ptr;
};

struct node *createnode() {
  int data;
  cout << "Enter Value:";
  cin >> data;
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->ptr = NULL;
  return newnode;
}



void display(struct node *node) {
  while (node != NULL) {
    cout << node->data << "  ";
    node = node->ptr;
  }
}


int main() {
  struct node *head = NULL;
  struct node *temp = NULL;

  int list_size;
  cout << "Enter The Length Of The List:";
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

  cout << "List Before Deletion: ";
  temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->ptr;
  }
  cout << endl;

  int val;
  cout << "Enter Value to Delete: ";
  cin >> val;


  while (head != NULL && head->data == val) {
    struct node *del = head;
    head = head->ptr;
    free(del);
  }

  temp = head;
  struct node *prev = NULL;

  while (temp != NULL) {
    if (temp->data == val) {
      prev->ptr = temp->ptr;
      free(temp);
      break;
    }
    prev = temp;
    temp = temp->ptr;
  }

  cout << "List After Deletion: ";
  temp = head;
display(temp);

return 0;
  }


