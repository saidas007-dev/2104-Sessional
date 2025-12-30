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
  newnode->ptr = NULL;

  return newnode;
}

int main() {
  struct node *head = NULL;
  struct node *temp = NULL;

  int list_size;
  cout << "Enter The Length Of The List:";
  cin >> list_size;

  for (int i = 0; i < list_size; i++) {
    struct node *newnode = createnode();
    if (head == NULL)
      head = temp = newnode;

    else {

      temp->ptr = newnode;
      temp = newnode;
    }
  }

  temp = head;
  int val;
  int count = 0;
  cout << "Enter Key  Value : ";
  cin >> val;
  while (temp != NULL) {
    count++;
    if (val == temp->data) {
      cout << "Value :  " << val << "  Is Found In " << count << " Position";
      return 0;
      ;
    }
    temp = temp->ptr;
  }
  cout << "Value Not Found." << endl;
  return 0;
}
