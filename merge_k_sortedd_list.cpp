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

//brute force
// Node* merge_k_linked_list(vector<Node*>& lists)
// {
//     vector<int> values;

//     for(int i = 0 ; i < lists.size() ; i++)
//     {
//         Node* temp = lists[i];
//         while(temp != nullptr)
//         {
//             values.push_back(temp->data);
//             temp = temp->next;
//         }
//     }

//     sort(values.begin() , values.end());

//     Node* dummy = new Node(-1);
//     Node* current = dummy;

//     for(int i = 0 ; i < values.size() ; i++)
//     {
//         current->next = new Node(values[i]);
//         current = current->next;
//     }
//     return dummy->next;
// }

//better 
// Node* merge2head(Node* head , Node* head1)
// {
//     Node* temp = head;
//     Node* temp1 = head1;
//     Node* dummy1 = new Node(-1);
//     Node* tail = dummy1;
//     if(temp == nullptr  )
//     {
//         return temp1;
//     }

//     if(temp1 == nullptr)
//     {
//         return temp;
//     }
    
//     while(temp != nullptr && temp1 != nullptr)
//     {
//         if(temp->data <= temp1->data)
//         {
//             tail->next = temp;
//             temp = temp->next;
//         }
//         else
//         {
//             tail->next = temp1;
//             temp1 = temp1->next;
//         }
//         tail = tail->next;
//     }

//     if (temp != nullptr) tail->next = temp;
//     if (temp1 != nullptr) tail->next = temp1;

//     Node* newhead = dummy1->next;
//     delete dummy1;
//     return newhead;
// }


// Node* merge_k_linked_list(vector<Node*>& lists)
// {
//     Node* head = lists[0];
//     for(int i = 1 ; i < lists.size() ; i++)
//     {
//        head = merge2head(head , lists[i]); 
//     }
//     return head;
// }

// Optimal approach
Node* merge_k_linked_list(vector<Node*>& lists)
{
    auto cmp = [](pair<int, Node*> a, pair<int, Node*> b) {
        return a.first > b.first;  
    };
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, decltype(cmp)> pq(cmp);

    for(int i = 0 ; i < lists.size() ; i++)
    {
        if(lists[i])
        {
            pq.push({lists[i]->data , lists[i]});
        }
    }

    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        temp->next = it.second;
        temp = temp->next;
        if(it.second->next)
        {
            pq.push({it.second->next->data , it.second->next});
        }
    }
    return dummy->next;
}


Node* createList(vector<int> arr) {
    if (arr.empty()) return NULL;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

Node *counttoLL1(vector<int> &arr2)
{
    Node *head1 = new Node(arr2[0]);
    Node *mover1 = head1;
    Node *prev1 = nullptr;

    for (int i = 1; i <= arr2.size() - 1; i++)
    {
        Node *temp = new Node(arr2[i]);
        mover1->next = temp;
        mover1 = temp;
    }
    return head1;
}

int main() {
    vector<int> arr1 = {1, 4, 5};
    vector<int> arr2 = {1, 3, 4};
    vector<int> arr3 = {2, 6};

    Node* l1 = createList(arr1);
    Node* l2 = createList(arr2);
    Node* l3 = createList(arr3);

    vector<Node*> lists = {l1, l2, l3};
    Node* first = merge_k_linked_list(lists);
    Traversal(first);

    return 0;
}