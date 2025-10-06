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

Node* Deletion_same_in_LL(Node* head)
{
   Node* temp = head;
   while(temp !=nullptr && temp->next != nullptr)
   {
    Node* nextnode = temp->next;
    if(temp->data == nextnode->data)
    {
        temp->next = nextnode->next;
        if(nextnode->next != nullptr)
        {
        nextnode->next->prev = temp;
        }
        delete nextnode;
        nextnode = nextnode->next;
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
    vector<int> arr = {1,1,1,1,1,1};
    Node *head = counttoLL(arr);
    Node *first = Deletion_same_in_LL(head);
    Traversal(first);
}