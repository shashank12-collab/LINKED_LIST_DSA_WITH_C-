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

vector<pair<Node*, Node*>> pairs_sum(Node* head , int sum)
{
    // Node* temp = head;
    // vector<pair<Node* ,Node*>> result;
    // while(temp != nullptr )
    // {
    //     Node* temp2 = temp->next;
    //     while(temp2 != nullptr)
    //     {
    //         if(temp->data + temp2->data == sum)
    //     {
    //         result.push_back({temp , temp2});
    //     }
    //     temp2 = temp2->next;
    // }
    // temp = temp->next;
    // }
    // return result; 

    Node* low = head;
    Node* high = tail(head);
    vector<pair<Node* ,Node*>> result;

    while(low != nullptr && high != nullptr && low != high && high->next != low)
    {
        int s = low->data + high->data;
        if(s == sum)
        {
            result.push_back({low , high});
            low = low->next;
            high = high->prev;
        }
        else if(s > sum)
        {
            high = high->prev;
        }
        else
        {
            low = low->next;
        }
    }
    return result;
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
    vector<int> arr = {1,1,2,2,3};
    Node *head = counttoLL(arr);
    vector<pair<Node*, Node*>> first = pairs_sum(head , 4);
     if (!first.empty())
    {
        cout << "first found:\n";
        for (auto &p : first)
        {
            cout << p.first->data << " + " << p.second->data << " = 4\n";
        }
    }
    else
    {
        cout << "No pair found\n";
    }

    cout << "Full list: ";
    Traversal(head);
}