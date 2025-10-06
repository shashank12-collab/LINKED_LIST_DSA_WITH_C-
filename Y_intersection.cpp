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

// Node* y_intersection(Node* head1 , Node* head2)
// {
//     map<Node* , int> mpp;
//     Node* temp = head1;
//     while(temp != nullptr)
//     {
//         mpp[temp] = 1;
//         temp = temp->next;
//     }

//     temp = head2;
//     while(temp != nullptr)
//     {
//         if(mpp.find(temp) != mpp.end())
//         {
//             return temp;
//         }
//         temp = temp->next;
//     }
//     return 0;
// }

// Node* collisionpoint(Node* t1 , Node* t2 ,int d)
// {
//     while(d)
//     {
//         d--;
//         t2 = t2->next;
//     }
//     while(t1 != t2)
//     {
//         t1 = t1->next;
//         t2 = t2->next;
//     }
//     return t1;
// }

// Node* Y_intersection(Node* head1 , Node* head2)
// {
//     Node* temp = head1;
//     int n1 = 0;
//     while(temp != nullptr)
//     {
//         n1++;
//         temp = temp->next;
//     }

//     int n2 = 0;
//     temp = head2;
//     while(temp != nullptr)
//     {
//         n2++;
//         temp = temp->next;
//     }

//     if(n1 < n2)
//     {
//       return collisionpoint(head1 , head2 , n2 - n1);  
//     }
//     else
//     {
//         return collisionpoint(head2 , head1 , n1 - n2 );
//     }
// }

Node* Y_intersection(Node* head1 , Node* head2)
{
    if(head1 == nullptr || head2 == nullptr)
    {
        return NULL;
    } 
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;

        if(temp1 == temp2)
        {
            return temp1;
        }

        if(temp1 == nullptr)
        {
            temp1 = head2;
        }
        if(temp2 == nullptr)
        {
            temp2 = head1;
        }
    }
    return temp1;
}

int main()
{
    Node* head1 = new Node(4);
    head1->next = new Node(1);

    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(1);

    Node* inter = new Node(8);
    inter->next = new Node(4);
    inter->next->next = new Node(5);

    head1->next->next = inter;
    head2->next->next->next = inter;
    Node* first = Y_intersection(head1 , head2);
    Traversal(first);
    cout << endl;
}