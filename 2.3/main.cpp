#include <iostream>
using namespace std;

struct Node
{
    Node* next;
    int data;
    Node(int d): data{d}, next{nullptr} {}
};

class LinkedList
{
    Node* head = nullptr;

public:
    void addNode(Node* newNode)
    {
        if(head == nullptr)
        {
            head = newNode;
            return;
        }

        Node* curr = head;
        while(curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    void printList()
    {
        Node* curr = head;

        while(curr != nullptr)
        {
            cout<<curr->data<<' ';
            curr = curr->next;
        }
    }

    bool removeCentralNode(Node* node)
    {
        if(node == nullptr || node->next == nullptr)
        {
            return false;
        }
        Node* nextNode = node->next;
        node->data = nextNode->data;
        node->next = nextNode->next;
        delete nextNode;

        return true;
    }
};


int main()
{
    LinkedList ll;
    Node* n1 = new Node(1);
    ll.addNode(n1);
    Node* n2 = new Node(2);
    ll.addNode(n2);
    Node* n3 = new Node(3);
    ll.addNode(n3);
    Node* n4 = new Node(4);
    ll.addNode(n4);
    Node* n5 = new Node(5);
    ll.addNode(n5);

    ll.removeCentralNode(n3);
    ll.printList();
    return 0;
}
