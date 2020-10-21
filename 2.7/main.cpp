#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int d): data{d}, next{nullptr} {}
};

class LinkedList
{
public:
    Node* head = nullptr;
    int length = 0;

    LinkedList(Node* node){
        head = node;
        length = 1;
    }

    void reverseList()
    {
        if(head == nullptr || head->next == nullptr)
        {
            return;
        }

        Node* newHead = nullptr;
        Node* nextNode = nullptr;

        while(head)
        {
            nextNode = head->next;
            head->next = newHead;
            newHead = head;
            head = nextNode;
        }

        head = newHead;
    }

    Node* getReversedListCopy(){
        if(head == nullptr){
            return nullptr;
        }

        Node* newHead = new Node(head->data);
        Node* currNode = head->next;
        while(currNode){
            Node* newNode = new Node(currNode->data);
            newNode->next = newHead;
            newHead = newNode;
            currNode = currNode->next;
        }

        return newHead;
    }

};

Node* getIntersection(LinkedList &l1, LinkedList &l2)
{
    int len1 = l1.length, len2 = l2.length;
    Node* currNode1 = l1.head;
    Node* currNode2 = l2.head;
    if(len1 > len2)
    {
        for(int i=1; i<= len1-len2; i++)
        {
            currNode1 = currNode1->next;
        }
    }
    else
    {
        for(int i=1; i<=len2-len1; i++)
        {
            currNode2 = currNode2->next;
        }
    }

    while(currNode1 && currNode2 && currNode1 != currNode2)
    {
        currNode1 = currNode1->next;
        currNode2 = currNode2->next;
    }

    return currNode1;
}

Node* getIntersection1(LinkedList &l1, LinkedList &l2)
{
    Node* currNode1 = l1.getReversedListCopy();
    Node* currNode2 = l2.getReversedListCopy();
    Node* result = nullptr;
    while(currNode1 && currNode2 && currNode1 == currNode2)
    {
        result = currNode1;
        currNode1 = currNode1->next;
        currNode2 = currNode2->next;
    }
    return result;
}

Node* getTailAndSetSize(Node* head, int& length){
    length = 0;
    if(head == nullptr){
        return nullptr;
    }
    length = 1;
    Node* tail = head;
    while(tail->next){
        tail = tail->next;
        length++;
    }
    return tail;
}

Node* getKthNode(Node* head, int k){
    Node* current = head;
    while(k > 0 && current){
        current = current->next;
        k--;
    }
    return current;
}

Node* getIntersection2(Node* head1, Node* head2){
    int len1, len2;
    Node* tail1 = getTailAndSetSize(head1, len1);
    Node* tail2 = getTailAndSetSize(head2, len2);

    if(tail1 != tail2){
        return nullptr;
    }

    Node* shorter = len1 < len2 ? head1 : head2;
    Node* longer = len1 < len2 ? head2 : head1;

    longer = getKthNode(longer, abs(len1-len2));

    while(shorter != longer){
        shorter = shorter->next;
        longer = longer->next;
    }

    return longer;
}

int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    node2->next = node3;
    node1->next = node3;
    node3->next = node4;
    node5->next = node1;

    LinkedList l1 = LinkedList(node1);
    LinkedList l2 = LinkedList(node2);

    Node* node = getIntersection2(node5, node2);
    cout<<node->data<<'\n';
    return 0;
}
