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

bool  detect_loop(Node* h)
{
    Node* slow = h;
    Node* fast = h;

    while(fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast)
        {
            return true;
        }
    }
    return false;
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
    if(detect_loop(head)) {
        cout << "Loop detected!" << endl;
    } else {
        cout << "No loop found." << endl;
    }

    return 0;
}