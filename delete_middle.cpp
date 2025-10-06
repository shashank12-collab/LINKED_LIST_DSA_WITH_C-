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

Node* middle_element(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    while(fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = slow->next;
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
    Node* first = middle_element(head);
    Traversal(first);
}