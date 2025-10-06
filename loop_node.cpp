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

void PrintCycle(Node* start) {
    if (start == nullptr) {
        cout << "No cycle\n";
        return;
    }
    Node* temp = start;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != start);
    cout << endl;
}

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
           Node* loopdata = h;
            while(loopdata != slow)
            {
                loopdata = loopdata->next;
                slow = slow->next;
            }
            return loopdata;
        }
    }
    return nullptr;
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

    Node* first = detect_loop(head);
    PrintCycle(first);

    return 0;
}