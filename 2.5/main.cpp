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
private:
    Node* head;
    Node* tail;
    int length;
public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    LinkedList(Node* node)
    {
        head = node;
        tail = node;
        length = 1;
    }

    void addTail(int d)
    {
        length++;
        Node* node = new Node(d);
        if(nullptr == tail)
        {
            head = node;
            tail = node;
            return;
        }

        tail->next = node;
        tail = node;
    }

    void addHead(int d)
    {
        length++;
        Node* node = new Node(d);
        if(nullptr == head)
        {
            head = node;
            tail = node;
            return;
        }
        node->next = head;
        head = node;
    }

    void printList()
    {
        Node* curr = head;
        while(curr != nullptr)
        {
            cout<<curr->data<<' ';
            curr = curr->next;
        }
        cout<<'\n';
    }

//    LinkedList operator+(const LinkedList& other)
//    {
//        LinkedList result;
//        Node* ptr1 = head;
//        Node* ptr2 = other.head;
//        int tran = 0;
//        while(ptr1 != nullptr || ptr2 != nullptr)
//        {
//            int sum = tran;
//            if(ptr1 != nullptr)
//            {
//                sum = sum + ptr1->data;
//                ptr1 = ptr1->next;
//            }
//            if(ptr2 != nullptr)
//            {
//                sum = sum + ptr2->data;
//                ptr2 = ptr2->next;
//            }
//            result.addTail(sum%10);
//            tran = 0;
//            if(sum > 9)
//            {
//                tran = 1;
//            }
//        }
//        return result;
//    }

    void recursiveAddition(LinkedList& res, Node* ptr1, Node* ptr2, int& tran)
    {
        if(ptr1 != nullptr)
        {
            recursiveAddition(res, ptr1->next, ptr2->next, tran);

            int sum = ptr1->data + ptr2->data + tran;
            res.addHead(sum%10);
            tran = 0;
            if(sum > 9)
            {
                tran = 1;
            }
        }
    }

    LinkedList operator+(LinkedList& other)
    {
        int tran = 0;
        while(length < other.length){
            addHead(0);
        }
        while(other.length < length){
            other.addHead(0);
        }
        LinkedList result;
        recursiveAddition(result, head, other.head, tran);
        if(tran){
            result.addHead(1);
        }

        return result;
    }

};


int main()
{
    LinkedList l1;
    l1.addHead(7);
    l1.addHead(1);
    l1.addHead(6);
    LinkedList l2;
    l2.addHead(5);
    l2.addHead(9);
    l2.addHead(6);
    LinkedList l3 = l1 + l2;
    l3.printList();
    return 0;
}
