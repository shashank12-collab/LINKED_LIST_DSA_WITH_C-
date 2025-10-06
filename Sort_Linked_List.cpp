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
    while (ptr != nullptr)
    {
        cout << ptr->data;
        if (ptr->next) cout << " -> ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Node* sort_LL(Node* head)
// {
//     if (!head) return head;
//     vector<int>arr3;
//     Node* temp = head;
//     while(temp != nullptr)
//     {
//         arr3.push_back(temp->data);
//         temp = temp->next;
//     }

//     sort(arr3.begin() , arr3.end());

//     temp = head;
//     int i = 0;
//     while(temp != nullptr)
//     {
//         temp->data = arr3[i];
//         i++;
//         temp = temp->next;
//     }
//     return head;
// }

Node* Middle_element(Node* head)
{
    Node* fast = head;
    Node* slow = head;

    while (fast && fast->next && fast->next->next) 
    {
    slow = slow->next;
    fast = fast->next->next;
    }
    return slow;
}

Node* merge_LL(Node* l1, Node* l2)
{
    Node dummy(-1);
    Node* tail = &dummy;

    while (l1 && l2)
    {
        if (l1->data <= l2->data)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1) tail->next = l1;
    if (l2) tail->next = l2;

    return dummy.next;
}


Node* Merge_sort(Node* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node* middle = Middle_element(head);
    Node* leftnode = head;
    Node* right = middle->next;
    middle->next = nullptr;

    Node* leftsorted = Merge_sort(leftnode);
    Node* rightsorted = Merge_sort(right);

    return merge_LL(leftsorted , rightsorted);
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

    vector<int> arr = {5,3,6,1,11,3};
    Node* head = counttoLL(arr);
    Node* front = Merge_sort(head);
    Traversal(front);
} 