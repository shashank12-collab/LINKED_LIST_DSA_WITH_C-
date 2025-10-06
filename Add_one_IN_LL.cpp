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

// Node* Add_One_In_LL(Node* head)
// {
//     head =  reverse(head);
//     Node* temp = head;
//     int carry = 1;

//     while(temp != NULL)
//     {
//         temp->data = temp->data + carry;
//         if(temp->data < 10)
//         {
//             carry = 0;
//             break;
//         }
//         else
//         {
//             temp->data = 0;
//             carry = 1;
//         }
//         temp = temp->next;
//     }

//     if(carry == 1)
//     {
//         Node* newnode = new Node(1);
//         head = reverse(head);
//         newnode->next = head;
//         return newnode;
//     }
    
//     head = reverse(head);
//     return head;
// }

int helper(Node* temp)
{
    if(temp == nullptr)
    {
        return 1;
    }

    int carry = helper(temp->next);
    temp->data = temp->data + carry;

    if(temp->data < 10)
    {
        return 0;
    }

    temp->data = 0 ;
    return 1;
}

Node* Addone(Node* head)
{
    int carry = helper(head);
    if(carry == 1)
    {
        Node* newnode = new Node(1);
        newnode->next = head;
        return newnode;
    }  
    return head;  
}


Node *counttoLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i <= arr.size() - 1; i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 2, 1, 9};
    Node *head = counttoLL(arr);
    Node* first = Addone(head);
    Traversal(first);
}