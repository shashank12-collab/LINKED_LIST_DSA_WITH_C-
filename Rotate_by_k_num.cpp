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

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newnode = reverse(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;

    return newnode;
}
// brute force
Node *reverse(Node *start, Node *end)
{
    Node *prev = nullptr;
    Node *curr = start;
    Node *next = nullptr;

    while (curr != end)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* rightRotate(Node* head , int k){
    vector<int>arr;
    Node* temp = head;
    int length = 0;
    while(temp != nullptr){
        length++;
        arr.push_back(temp->data);
        temp = temp->next;
    }
    int firsthalf = length - k;
    reverse(arr.begin() , arr.begin()+firsthalf);
    reverse(arr.begin()+firsthalf , arr.end());
    reverse(arr.begin() , arr.end());

    temp = head;
    int i =0;
    while(temp != nullptr){
        temp->data = arr[i++];
        temp = temp->next;
    }
    return head;
}    
// Node *rotate(Node *head, int k)
// {
//     Node *temp = head;
//     Node *tail = head;
//     if (!head || !head->next || k == 0) return head; 
//     int length = 1;
//     while (tail->next != nullptr)
//     {
//         tail = tail->next;
//         length++;
//     }

//     if (k % length == 0)
//     {
//         return head;
//     }
//     k = k % length;
//     tail->next = head;
//     Node *newlast = head;
//     for (int i = 1; i < length - k; i++)
//     {
//         newlast = newlast->next;
//     }
//     head = newlast->next;
//     newlast->next = nullptr;
//     return head;
// }

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
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = counttoLL(arr);
    Node *first = rightRotate(head, 2);
    Traversal(first);
}