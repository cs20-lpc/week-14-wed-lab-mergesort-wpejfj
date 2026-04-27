#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insertEnd(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* sortedMerge(Node* a, Node* b)
{
    // TODO:
    // Merge two sorted linked lists
  if (a == NULL) return b;
  if (b == NULL) return a;

  Node *res = NULL;

  if (a->data <= b->data) {
    res = a;
    res->next = sortedMerge(a->next, b);
  }
  else {
    res = b;
    res->next = sortedMerge(a, b->next);
  }
  return res;
   
}

void splitList(Node* source, Node*& front, Node*& back)
{
    // TODO:
    // Use slow/fast pointer method
    // Split list into two halves
  Node *f;
  Node *s;
  s = source;
  f = source->next;

  while (f != NULL) {
    f = f->next;
    if (f != NULL) {
      s = s->next;
      f = f->next;
    }
  }

  front = source;
  back = s->next;
  s->next = NULL;

}

void mergeSort(Node*& head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node* a;
    Node* b;

    // TODO:
    // Split list
    // Recursively sort both halves
    // Merge sorted lists
    splitList(head, a, b);
    mergeSort(a);
    mergeSort(b);
    head = sortedMerge(a, b);

}

int main()
{
    Node* head = NULL;

    int values[10] = {38, 27, 43, 3, 9, 82, 10, 5, 61, 14};

    for (int i = 0; i < 10; i++)
        insertEnd(head, values[i]);

    cout << "Before Sorting: ";
    display(head);

    mergeSort(head);

    cout << "After Sorting: ";
    display(head);

    return 0;
}
