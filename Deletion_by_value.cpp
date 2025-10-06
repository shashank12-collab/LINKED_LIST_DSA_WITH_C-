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

Node* Sort012(Node* head)
{
    Node* zeronum = new Node(-1);
    Node* onenum = new Node(-1);
    Node* twonum = new Node(-1);

    Node* zero = zeronum;
    Node* one = onenum;
    Node* two = twonum;

    Node* current = head;
    while(current != nullptr)
    {
        if(current->data == 0)
        {
            zero->next = current;
            zero = current;
        }
        if(current->data == 1)
        {
            one->next = current;
            one = current;
        }
        if(current->data == 2)
        {
            two->next = current;
            two = current;
        }
        current = current->next;
    }

    zero->next = (onenum->next)?onenum->next:twonum->next;
    one->next = (twonum->next)?twonum->next:NULL;
    two->next = NULL;

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
    vector<int> arr = {1,2};
    Node* head = counttoLL(arr);
    Node* first = Sort012(head);
    Traversal(first);
} 