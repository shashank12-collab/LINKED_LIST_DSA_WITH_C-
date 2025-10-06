#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *child;

    Node(int data1, Node *next1, Node *child1)
    {
        data = data1;
        next = next1;
        child = child1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        child = nullptr;
    }
};

void Traversal(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

Node *convertarr2LL(vector<int> &arr)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;

    for (int i = 0; i < arr.size(); i++)
    {
        temp->child = new Node(arr[i]);
        temp = temp->child;
    }
    return dummy->child;
}

// brute force
//  Node* flatten(Node* head)
//  {
//      vector<int>arr;

//     while(head)
//     {
//         Node* temp2 = head;
//         while(temp2 != nullptr)
//         {
//             arr.push_back(temp2->data);
//             temp2 = temp2->child;
//         }
//         head = head->next;
//     }

//     sort(arr.begin() , arr.end());
//     return convertarr2LL(arr);
// }

Node *merge(Node *list1, Node *list2)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data <= list2->data)
        {
            temp->child = list1;
            temp = list1;
            list1 = list1->child;
        }
        else
        {
            temp->child = list2;
            temp = list2;
            list2 = list2->child;
        }
        temp->next = nullptr;
    }
    if (list1)
        temp->child = list1;
    if (list2)
        temp->child = list2;

    return dummy->child;
}

Node *flatten(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *newhead = flatten(head->next);
    head = merge(head, newhead);
    return head;
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

int main()
{
    // Create a linked list with child pointers
    Node *head = new Node(5);
    head->child = new Node(14);

    head->next = new Node(10);
    head->next->child = new Node(4);

    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);

    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    Node *first = flatten(head);
    Traversal(first);
    return 0;
}