#include <bits/stdc++.h>
using namespace std;
struct node {
  int data;
  struct node *ptr;
};

struct node *createnode() {
  int data;
  cout << "Enter  Value:";
  cin >> data;
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->ptr = nullptr;
  return newnode;
}

void display(struct node *node) {
  while (node != nullptr) {
    cout << node->data << "  ";
    node = node->ptr;
  }
  cout << "\n";
}

int searchnode(struct node *temp) {
  int key_val;
  cout << "Enter The Value You Want To Search :";
  cin >> key_val;
  int count = 0;

  while (temp != nullptr) {
    count++;
    if (temp->data == key_val) {
      cout << "The Value Is Found In Postion : " << (count) << endl;
      return count;
    }
    temp = temp->ptr;
  }
  return -1;
}

int main() {
  struct node *head = nullptr;
  struct node *temp = nullptr;

  int list_size;
  cout << "Enter The Length Of The List:";
  cin >> list_size;

  for (int i = 0; i < list_size; i++) {
    struct node *newnode = createnode();
    if (head == nullptr)
      head = temp = newnode;

    else {

      temp->ptr = newnode;
      temp = newnode;
    }
  }

  temp = head;
  cout << "The Linked List Is:";
  display(temp);
  int flag = searchnode(head);
  if (flag == -1) {
    cout << "Value Not Found" << endl;
  }
  return 0;
}
