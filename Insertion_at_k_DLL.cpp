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

Node *insertion_k(Node *head, int num ,int index)
{
    int cnt = 0;
    if (head == NULL)
    {
        return new Node(num);
    }

    Node *temp = head;
    while (temp != nullptr && cnt < index - 1)
    {
        temp = temp->next;
        cnt++;
    }

        if(temp == nullptr) return head;

        Node* newnode = new Node(num);
        newnode->next = temp->next;
        newnode->prev = temp;

        if(temp->next != nullptr)
        {
            temp->next->prev = newnode;
        }
        temp->next = newnode;
        
    
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
    vector<int> arr = {1, 2, 4, 5};
    Node *head = counttoLL(arr);
    Node *first = insertion_k(head, 0, 4);
    Traversal(first);
}