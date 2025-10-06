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

Node* Deletion_tail(Node* head)
{
    Node* ptr = head;
    while(ptr->next->next != nullptr)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = nullptr;
    return head;
}

Node* Deletion_k(Node* head , int k)
{
    Node* temp = head;
    Node* prev = nullptr;
    int cnt = 0;

    while(temp != nullptr)
    {
        cnt++;

        if(cnt == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
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
    Node* first = Deletion_k(head, 3);
    Traversal(first);
} 