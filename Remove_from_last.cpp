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

// Node* Deletr_from_last(Node* head , int k)
// {

//     Node* temp = head;
//     int totalnode = 0;
//     while(temp != NULL)
//     {
//         totalnode++;
//         temp = temp->next;
//     }
//     temp = head;
//     int pos = totalnode-k+1;
//     int current = 1;
//     if(k > totalnode)
//     {
//         return head;
//     }
//     if(pos == 1)
//     {
//         Node* newnode = head->next;
//         delete head;
//         return newnode;
//     }


//     while(temp != nullptr && current < pos-1)
//     {
//         current++;
//         temp = temp->next;
//     }

//     Node* ptr = temp->next;
//     temp->next = ptr->next;
//     delete ptr;

//     return head;
    
// }

Node* Remove_last(Node* head , int k)
{
    Node* fastptr = head;
    Node* slowptr = head;

    for(int i = 1 ; i <= k ; i++)
    {
        fastptr = fastptr->next;
    }

    while(fastptr->next != nullptr)
    {
        fastptr = fastptr->next;
        slowptr = slowptr->next;
    }

    Node* delnode = slowptr->next;
    slowptr->next = delnode->next;
    delete delnode;
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
    vector<int> arr = {1,2,4,8,9,0};
    Node* head = counttoLL(arr);
    Node* first = Remove_last(head , 2);
    Traversal(first);
} 