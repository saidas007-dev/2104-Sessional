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
  struct node *newnode = (struct node *)malloc(sizeof(struct node ));
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
    if (head == NULL)
      head = temp = newnode;

    else {

      temp->ptr = newnode;
      temp = newnode;
    }
  }
cout<<"List Before Insertion :";
   temp = head;
  cout << "The Linked List Is:";
  display(temp);
cout<<endl;

cout<<"Creating a New Node:"<<endl;
struct node* new_node=createnode();
new_node->ptr=head;
head=new_node;


cout<<"List After  Insertion :";
  temp = head;
  cout << "The Linked List Is:";
  display(temp);
  return 0;
}
