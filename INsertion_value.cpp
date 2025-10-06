#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int data1 , Node* next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
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

Node* insertion_el(Node* head, int el , int num)
{
    if(head == NULL)
    {
        return  new Node(el);
    }

    if(head->data == num)
    {
        Node* first = new Node(el , head);
        return first;
    }
    
    Node* temp = head;
    while(temp->next != nullptr)
    {
     if(temp->next->data == num)
     {
        Node* first = new Node(el);
        first->next = temp->next;
        temp->next = first;
        break;
     }
     temp = temp->next;
    }
    return head;
}

Node* counttoLL(vector<int> & arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1 ; i <= arr.size() - 1; i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main()
{
    vector<int> arr = {1,2,4,5};
    Node* head = counttoLL(arr);
    Node* first = insertion_el(head , 5 , 2);
    Traversal(first);
} 