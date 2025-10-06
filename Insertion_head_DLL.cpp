#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
    
    Node(int data1 , Node* next1 , Node* prev1)
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

void Traversal(Node* head)
{
    Node* ptr = head;
    while(ptr != nullptr)
    {
        cout << ptr->data;
        ptr = ptr->next;
    }
}

Node* insertion_head(Node* head,int num)
{
    Node* first = new Node(num);
    first->next = head;
    head->prev = first;
    first->prev = nullptr;
    return first;
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
    Node* first = insertion_head(head , 0);
    Traversal(first);
} 