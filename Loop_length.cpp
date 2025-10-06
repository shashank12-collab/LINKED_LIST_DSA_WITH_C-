#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;   
    
    Node* next;      

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node*  detect_loop(Node* h)
{
    Node* slow = h;
    Node* fast = h;

    while(fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast)
        {
            return slow;
        }
    }
    return nullptr;
}


int length_of_loop(Node* head)
{
    Node* intersection = detect_loop(head);
    Node* slow = intersection;
    int cnt = 1;

    while(slow->next != intersection)
    {
        cnt++;
        slow = slow->next;
    }
    return cnt;
}


int main() {
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    fifth->next = second; 

    int loopLength = length_of_loop(head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }

    return 0;
}