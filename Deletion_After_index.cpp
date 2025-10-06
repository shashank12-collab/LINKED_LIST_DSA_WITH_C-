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



Node* deletionafterindex(Node* head , int index)
{
    Node *temp = head;
    int cnt = 0;

    while(temp != nullptr && cnt < index)
    {
        temp = temp->next;
        cnt++;
    }

    if(temp == nullptr || temp->next == nullptr)
    {
        cout<<"Its the end there is no node after this"<<endl;
        return head;
    }

    Node* delnode = temp->next;
    temp->next = delnode->next;
    if(delnode->next != nullptr)
    {
    delnode->next->prev = temp;
    }
    delete delnode;
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
    vector<int> arr = {1, 2, 4, 5, 6, 8};
    Node *head = counttoLL(arr);
    head = deletionafterindex(head, 3);
    Traversal(head);
}