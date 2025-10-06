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

// bool palindrome(Node* head)
// {
//     Node* temp = head;
//     stack<int>st;
//     while(temp != NULL)
//     {
//         st.push(temp->data);
//         temp = temp->next;
//     }
//     temp = head;

//     while(temp != nullptr)
//     {
//         if(temp->data != st.top())
//         {
//             return false;
//         }
//         temp = temp->next;
//         st.pop();

//     }
//     return true;
// }

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

bool palindrome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *secondhalf = reverse(slow->next);
    Node *first = head;
    Node *second = secondhalf;
    while (second != nullptr)
    {
        if (first->data != second->data)
        {
            return false;
        }
        first = first->next;
        second = second->next;
    }
    return true;
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
    vector<int> arr = {1, 2, 2, 1, 0};
    Node *head = counttoLL(arr);
    Traversal(head);
    cout << endl;
    if (palindrome(head))
    {
        cout << "The linked list is a palindrome.\n";
    }
    else
    {
        cout << "The linked list is NOT a palindrome.\n";
    }
}