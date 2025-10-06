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

// Node* Middle_element(Node* head)
// {
//     int count = 1;
//     Node* temp = head;

//     if (head == NULL || head->next == NULL) {
//         return head;
//     }

//     while(temp->next != nullptr)
//     {
//         count++;
//         temp = temp->next;
//     }

//     int mid = count / 2 + 1;

//     temp = head;
//     int current = 1;

//     while(temp != nullptr && current < mid)
//     {
//         current++;
//         temp = temp->next;
//     }
//     return temp;

// }

Node* Middle_element(Node* head)
{
    Node* fast = head;
    Node* slow = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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
    vector<int> arr = {1, 2, 2, 1, 0, 3};
    Node *head = counttoLL(arr);
    Node* first = Middle_element(head);
    Traversal(first);
    cout << endl;
}