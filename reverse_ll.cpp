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

Node* Reverse_LL(Node* head)
{
    Node* prev = nullptr;
    Node* temp = head;
    Node* first = nullptr;

    while(temp != nullptr)
    {
        first = temp->next;
        temp->next = prev;
        prev = temp;
        temp = first;
    }
    return prev;
}

Node* findkthnode(Node* head , int k)
{
    k -= 1;
    while(head != nullptr && k > 0)
    {
        k--;
        head = head->next;
    }
    return head;
}

Node* Kreverse(Node* head,int k )
{
   Node* temp = head;
   Node* prevnode = nullptr;
   while(temp != nullptr)
   {
    Node* kthnode = findkthnode(temp , k);
    if(kthnode == nullptr)
    {
        if(prevnode) prevnode->next = temp;
        break;
    }

    Node* nextnode = kthnode->next;
    kthnode->next = nullptr;
    Reverse_LL(temp);
    if(temp == head)
    {
        head = kthnode;
    }
    else
    {
        prevnode->next = kthnode;
    }
    prevnode= temp;
    temp = nextnode;
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
    Node* front = Kreverse(head , 2);
    Traversal(front);
} 