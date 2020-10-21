#include <iostream>
using namespace std;

struct Node
{
    Node* next;
    int data;
    Node(int d) : data{d}, next{nullptr} {}
};

class LinkedList
{
    Node* head;

public:

    LinkedList(){
        head = nullptr;
    }

    void addNode(int d)
    {
        Node* node = new Node(d);

        if(head == nullptr)
        {
            head = node;
            return;
        }

        Node* curr = head;
        while(curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = node;
    }

    Node* getKthLast(int k)
    {
        int counter = k;
        Node* current = head;
        Node* runner = head;
        while(counter > 1 && nullptr != runner)
        {
            runner = runner->next;
            counter--;
        }
        if(nullptr == runner)
        {
            return nullptr;
        }

        while(runner->next != nullptr)
        {
            runner = runner->next;
            current = current->next;
        }

        return current;
    }

};


int main()
{
    LinkedList ll;
    for(int i=1; i<=15; i++){
        ll.addNode(i);
    }

    Node* node = ll.getKthLast(7);
    if(nullptr == node){
        cout<<"NULL NODE";
    }
    else{
        cout<<node->data<<'\n';
    }
    return 0;
}
