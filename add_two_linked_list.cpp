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

void Traversal1(Node* head1)
{
    Node* ptr1 = head1;
    while(ptr1 != nullptr)
    {
        cout << ptr1->data;
        ptr1 = ptr1->next;
    }
}

void Traversal2(Node* head2)
{
    Node* ptr2 = head2;
    while(ptr2 != nullptr)
    {
        cout << ptr2->data;
        ptr2 = ptr2->next;
    }
}

Node* Add_two_ll(Node* head1 , Node* head2)
{
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummynode = new Node(-1);
    Node* current = dummynode;
    int carry = 0;
    while(t1 != NULL || t2 != NULL)
    {

    int sum = carry;

    if(t1) sum += t1->data;
    if(t2) sum += t2->data; 

    Node* newNode = new Node(sum % 10);
    carry = sum /10;

    current->next = newNode;
    newNode->prev = current;
    current = current->next;
    
    if(t1) t1 = t1->next;
    if(t2) t2 = t2->next;
    }

    if(carry)
    {
        Node* NewNode = new Node(carry);
        current->next = NewNode;
    }
    return dummynode->next;

}

Node* counttoLL1(vector<int> & arr1)
{
    Node* head1 = new Node(arr1[0]);
    Node* mover1 = head1;
    Node* prev = nullptr;

    for(int i = 1 ; i <= arr1.size() - 1; i++)
    {
        Node* temp1 = new Node(arr1[i]);
        mover1->next = temp1;
        temp1->prev = mover1;
        mover1 = temp1;
    }
    return head1;
}

Node* countToLL2(vector<int>& arr2)
{
    Node* head2 = new Node(arr2[0]);
    Node* mover2 = head2;
    for(int i = 1 ; i <= arr2.size() - 1; i++)
    {
        Node* temp2 = new Node(arr2[i]);
        mover2->next = temp2;
        temp2->prev = mover2;
        mover2 = temp2; 
    }
    return head2;
}

int main()
{

    vector<int> arr1 = {1,2,3,5};
    vector<int> arr2 = {4,3,2,1};
    Node* head1 = counttoLL1(arr1);
    Node* head2 = countToLL2(arr2);
    Node* head = Add_two_ll(head1 , head2);
    Traversal1(head);
    return 0;
}