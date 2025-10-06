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

// Node* Reverse_LL(Node* head)
// {
//     Node* prev = nullptr;
//     Node* temp = head;
//     Node* first = nullptr;

//     while(temp != nullptr)
//     {
//         first = temp->next;
//         temp->next = prev;
//         prev = temp;
//         temp = first;
//     }
//     return prev;

// }

Node* reverse(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* newnode = reverse(head->next);
    Node* front = head->next; 
    front->next  = head;
    head->next = NULL;

    return newnode;
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
    Node* front = reverse(head);
    Traversal(front);
} 