#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data1, Node *next1)
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

void Traversal(Node *head)
{
    Node *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->data;
        ptr = ptr->next;
    }
}

Node* tail(Node* head)
{
    if(head == nullptr) return nullptr;
    Node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    return temp;
}

//brute force
Node* merge_LL(Node* head1 ,Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;

    if(temp1 == nullptr)
    {
        return temp2;
    }
    if(temp2 == nullptr)
    {
        return temp1;
    }

    vector<Node*> arr3;

    while(temp1 != nullptr && temp2 != nullptr)
    {
        if(temp1->data <= temp2->data)
        {
            arr3.push_back(temp1);
            temp1 = temp1->next;
        }
        else
        {
            arr3.push_back(temp2);
            temp2 = temp2->next;
        }
    }
    while(temp1)
    {
        arr3.push_back(temp1);
        temp1= temp1->next;
    }

    while(temp2)
    {
        arr3.push_back(temp2);
        temp2 = temp2->next;
    }

    for(int i = 0 ; i < arr3.size() - 1 ; i++)
    {
        arr3[i]->next = arr3[i + 1];
    }
    arr3.back()->next = nullptr;

    return arr3[0];
}

Node* merge_LL(Node* head , Node* head1)
{
    Node* temp = head;
    Node* temp1 = head1;
    Node* dummy1 = new Node(-1);
    Node* tail = dummy1;
    if(temp == nullptr  )
    {
        return temp1;
    }

    if(temp1 == nullptr)
    {
        return temp;
    }
    
    while(temp != nullptr && temp1 != nullptr)
    {
        if(temp->data <= temp1->data)
        {
            tail->next = temp;
            temp = temp->next;
        }
        else
        {
            tail->next = temp1;
            temp1 = temp1->next;
        }
        tail = tail->next;
    }

    if (temp != nullptr) tail->next = temp;
    if (temp1 != nullptr) tail->next = temp1;

    Node* newhead = dummy1->next;
    delete dummy1;
    return newhead;
}


Node *counttoLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    Node *prev = nullptr;

    for (int i = 1; i <= arr.size() - 1; i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node *counttoLL1(vector<int> &arr2)
{
    Node *head1 = new Node(arr2[0]);
    Node *mover1 = head1;
    Node *prev1 = nullptr;

    for (int i = 1; i <= arr2.size() - 1; i++)
    {
        Node *temp = new Node(arr2[i]);
        mover1->next = temp;
        mover1 = temp;
    }
    return head1;
}

int main()
{
    vector<int> arr1 = {1,1,2,2,3};
    Node *head = counttoLL(arr1);
    vector<int> arr2 = {1,3,5,7,9};
    Node* head1 = counttoLL1(arr2);

    Node* first = merge_LL(head , head1);
    Traversal(first);

    return 0;
}