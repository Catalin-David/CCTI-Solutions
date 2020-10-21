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
    Node* head;
public:
    LinkedList(){
        head = nullptr;
    }

    LinkedList(Node* node){
        head = node;
    }

    void addNode(int d)
    {
        Node* newNode = new Node(d);
        if(nullptr == head)
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

    void recursiveMethod(Node* curr, int value, int currIdx, int &bigIdx, Node* &bigNode)
    {
        if(curr->next != nullptr)
        {
            recursiveMethod(curr->next, value, currIdx+1, bigIdx, bigNode);
        }

        if(curr->data < value)
        {
            while(bigNode != nullptr && bigNode->data < value)
            {
                bigNode = bigNode->next;
                bigIdx++;
            }
            if(bigNode != nullptr && bigIdx<currIdx)
            {
                int temp = bigNode->data;
                bigNode->data = curr->data;
                curr->data = temp;
            }
        }
    }

    void partitionByValue(int k)
    {
        if(head == nullptr)
        {
            return;
        }
        int bigIdx = 1;
        Node* bigNode = head;
        recursiveMethod(head, k, 1, bigIdx, bigNode);
    }

    void addNodeEnd(Node* node){
        if(head == nullptr){
            head = node;
            return;
        }
        Node* curr = head;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = node;
    }
    void addNodeStart(Node* node){
        node->next = head;
        head = node;
    }

    void partitionByValue2(int k){
        if(head == nullptr){
            return;
        }
        Node* h = head;
        Node* t = head;
        Node* curr = head;

        while(curr != nullptr){
            Node* next = curr->next;
            if(curr->data < k){
                curr->next = h;
                h = curr;
            }
            else{
                t->next = curr;
                t = curr;
            }

            curr = next;
        }
        t->next = nullptr;
        head = h;
    }
};


int main()
{
    LinkedList ll;
    ll.addNode(3);
    ll.addNode(5);
    ll.addNode(8);
    ll.addNode(5);
    ll.addNode(10);
    ll.addNode(2);
    ll.addNode(1);
    ll.partitionByValue2(5);
    ll.printList();
    return 0;
}
