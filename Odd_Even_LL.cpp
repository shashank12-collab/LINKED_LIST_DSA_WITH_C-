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

Node* Odd_Even(Node* head)
{
    Node* odd = head;
    Node* even = head->next;
    Node* EvenHead = head->next;
    
    while(even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = EvenHead;
    return head;
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

int main()
{

    vector<int> arr1 = {1,2,3,5};
    Node* temp = counttoLL1(arr1);
    Node* head = Odd_Even(temp);
    Traversal1(head);
    return 0;
}