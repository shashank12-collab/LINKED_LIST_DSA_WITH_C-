#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next; 
    Node *random;       
    Node() : data(0), next(nullptr), random(nullptr){}; 
    Node(int x) : data(x), next(nullptr), random(nullptr) {} 

    Node(int x, Node *nextNode, Node *randomNode) :
            data(x), next(nextNode), random(randomNode) {}  
};





// Function to print the cloned linked list
void printClonedLinkedList(Node *head) {
    while (head != nullptr) {
        cout << "Data: " << head->data;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
         // Move to the next node
        head = head->next;  
    }
}

Node* Copy(Node* head)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        Node* copynode = new Node(temp->data);
        copynode->next = temp->next;   //yha pe hum ne next ka connection bna diya hai
        temp->next = copynode;
        temp = temp->next;
    }
}

Node* connect(Node* head)
{
    Node* temp = head;
    while(temp != nullptr)
    {
       Node* copyNode = temp->next;
       copyNode->random = temp->random->next;      //yha pe random ka connection bna diya hai 
       temp = temp->next->next;
    }
}

Node* mergecopy(Node* head)
{
    Node* temp = head;
    Node* dummy = new Node(-1);
    Node* tail = dummy;
    while(temp != nullptr)
    {
        tail->next = temp->next;
        tail->next = tail->next->next;
    }
    return dummy->next;
}

Node* copy_Linked_list(Node* head)
{
    if(!head)
    {
        return nullptr;
    }

    Copy(head);
    connect(head);

    return mergecopy(head);
}

Node* copy_Linked_lists(Node* head)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        Node* copynode = new Node(temp->data);
        copynode->next = temp->next;
        temp->next = copynode;
        temp = copynode->next;
    }

    temp = head;
    while(temp != nullptr)
    {
        Node* copyNode = temp->next;
        copyNode->random = temp->random->next;
        temp = temp->next->next;
    }

    temp = head;
    Node* dummy = new Node(-1);
    Node* result = dummy;
    while(temp != nullptr)
    {
        result->next = temp->next;
        result->next = result->next->next;
    }

    return dummy->next;
}

int main() {
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);
    Node* clonedList = copy_Linked_lists(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

    return 0;
}
