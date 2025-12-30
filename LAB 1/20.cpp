
#include <bits/stdc++.h>
#include <cstddef>
using namespace std;
struct node {
  int data;
  struct node *ptr;
};

struct node *createnode() {
  int data;
  cout << "Enter  Value:";
  cin >> data;
  struct node *newnode = (struct node *)malloc(sizeof(struct node *));
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

  int max = head->data;
  int min = head->data;

  while (head != NULL) {
    if (head->data > max)
      max = head->data;

    if (head->data < min)
      min=head->data;
head=head->ptr;

  }
cout<<"The Max value is : "<<max <<"   "<<"The Min value Is :  "<< min;
  return 0;
}
