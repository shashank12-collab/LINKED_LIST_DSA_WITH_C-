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

Node* Insertion_k(Node* head, int index , int num)
{
    if(head == NULL)
    {
        return new Node(num);
    }
    
    if(index == 1)
    {
        Node* first = new Node(num , head);
        return first;
    }
    
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr)
    {
        cnt++;
     if(cnt == (index-1))
     {
        Node* first = new Node(num);
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
    Node* first = Insertion_k(head , 2 , 0);
    Traversal(first);
} 