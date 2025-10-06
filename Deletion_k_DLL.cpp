#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int data1, Node *next1, Node *prev1)
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

void Traversal(Node *head)
{
    Node *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->data;
        ptr = ptr->next;
    }
}

Node *Deletion_tail(Node *head)
{
    Node *ptr = head;
    while (ptr->next->next != nullptr)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = nullptr;
    return head;
}

Node *Deletion_k(Node *head, int k)
{
    Node *temp = head;
    int cnt = 1;

    while (temp != nullptr && cnt < k)
    {
        temp = temp->next;
        cnt++;
    }

    if (!temp)
        return head;

    if (temp == head)
    {
        head = head->next;
        if (head)
            head->prev = nullptr;
        delete temp;
        return head;
    }

    if (!temp->next)
    {
        temp->prev->next = nullptr;
        delete temp;
        return head;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
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
        temp->prev = mover;
        mover = temp;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 4, 5};
    Node *head = counttoLL(arr);
    Node *first = Deletion_k(head, 3);
    Traversal(first);
}