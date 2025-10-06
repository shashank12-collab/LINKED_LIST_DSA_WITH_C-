#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
    
    Node(int data1 , Node* next1 , Node* prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
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
// Node* Sort012(Node* head)
// {
//    Node* low = head;
//    Node* mid = head;
//    Node* high = head;

//    while(high->next != nullptr)
//    {
//     high = high->next;
//    }

//     Node* current = head;

//     while(mid != high->next)
//     {
//         if(mid->data == 0)
//         {
//             swap(low->data , mid->data);
//             low = low->next;
//             mid = mid->next;
//         }
//         else if(mid->data == 1)
//         {
//             mid = mid->next;
//         }
//         else
//         {
//             swap(high->data , mid->data);
//             high = high->prev;

//         }
//     }
//     return head;
   
// }

Node* Sort012(Node* head)
{
    int cnt0 = 0 ;
    int cnt1 = 0 ;
    int cnt2 = 0 ;
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp->data == 0) cnt0++;
        
        if(temp->data == 1) cnt1++;
        
        if(temp->data == 2) cnt2++;
       
        temp = temp->next;
    }

    temp = head;

    while(cnt0--)
    {
        temp->data = 0;
        temp= temp->next;
    } 
    while(cnt1--)
    {
        temp->data = 1;
        temp= temp->next;
    } 
    while(cnt2--)
    {
        temp->data = 2;
        temp= temp->next;
    }
    return head; 
}

Node* counttoLL(vector<int> & arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;
    Node* prev = nullptr;

    for(int i = 1 ; i <= arr.size() - 1; i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }
    return head;
}


int main()
{
    vector<int> arr = {0 , 1 , 0 , 2 , 0 , 1 , 0 , 2};
    Node* head = counttoLL(arr);
    Node* first = Sort012(head);
    Traversal(first);
} 