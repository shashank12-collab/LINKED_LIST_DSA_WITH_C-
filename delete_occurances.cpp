#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

void Traversal(Node *head)
{
    Node *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->data;
        ptr = ptr->next;
    }
}

Node* Deletion_occurances(Node* head,int key)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        if(temp->data == key)
        {
          if(temp == head)
          {
            head = head->next;
          }
          Node* nextnode = temp->next;
          Node* prevnode = temp->prev;

          if(nextnode)
          {
            nextnode->prev = prevnode;
          }
          if(prevnode)
          {
            prevnode->next = nextnode;
          }
          delete temp;
          temp = temp->next;
        }
        else
        {
            temp = temp->next;
        }
    } 
    return head;
}

Node *counttoLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    Node *prev = nullptr;

    for (int i = 1; i <= arr.size() - 1; i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 1, 5};
    Node *head = counttoLL(arr);
    Node *first = Deletion_occurances(head, 1);
    Traversal(first);
}