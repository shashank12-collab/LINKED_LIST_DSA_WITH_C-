#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int data1 ,Node* next1 , Node* prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1 )
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }

};

void Traversal(Node* head)
{
    Node* ptr = head;
    while(ptr != nullptr)
    {
        cout << ptr->data;
        ptr = ptr->next;
    }
}

Node* Deletion_k(Node* head , int k)
{
     if(head->data == k)
        {
        Node* ptr = head;
        head = ptr->next;
        free(ptr);
        return head;
        }

    Node* temp = head;
    Node* prev = nullptr;
    // int num;

    while(temp != nullptr && temp->data != k)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev =temp->prev;

    delete temp;
    return head;
}

Node* counttoLL(vector<int> & arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;
    Node* prev = nullptr;

    for(int i = 1 ; i <= arr.size() - 1; i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }
    return head;
}

int main()
{
    vector<int> arr = {1,2,4,5};
    Node* head = counttoLL(arr);
    Node* first = Deletion_k(head, 5);
    Traversal(first);
} 