#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int d): data{d}, next{nullptr} {}
};

Node* getCycleStart(Node* head)
{
    if(head == nullptr){
        return nullptr;
    }

    Node* fast = head;
    Node* slow = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow){
            break;
        }
    }

    if(fast == nullptr || fast->next == nullptr)
    {
        return nullptr;

    }

    slow = head;
    while(fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}


int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node2;

    Node* node = getCycleStart(node1);
    if(node){
        cout<<node->data<<'\n';
    }
    else{
        cout<<"NULL";
    }
    return 0;
}
