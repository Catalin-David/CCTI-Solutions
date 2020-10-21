#include <iostream>
#include <unordered_set>
using namespace std;

class Node
{
    Node* next;
    int data;
public:
    Node(int d)
    {
        data = d;
        next = nullptr;
    }

    int getData()
    {
        return data;
    }

    Node* getNext()
    {
        return next;
    }

    void setNext(Node* nextNode)
    {
        next = nextNode;
    }
};

class LinkedList
{
    Node* head;
public:
    LinkedList()
    {
        head = nullptr;
    }

    void addNode(int d)
    {
        if(nullptr == head)
        {
            head = new Node(d);
            return;
        }

        Node* currentNode = head;
        while(nullptr != currentNode->getNext())
        {
            currentNode = currentNode->getNext();
        }
        Node* newNode = new Node(d);
        currentNode->setNext(newNode);
    }

    void removeDuplicates()
    {
        unordered_set<int> uniqueNodes;
        Node* previousNode = nullptr;
        Node* currentNode = head;
        while(nullptr != currentNode)
        {
            int data = currentNode->getData();
            if(uniqueNodes.find(data) != uniqueNodes.end())
            {
                if(nullptr != currentNode->getNext())
                {
                    previousNode->setNext(currentNode->getNext());
                    delete currentNode;
                    currentNode = previousNode->getNext();
                }
                else
                {
                    previousNode->setNext(nullptr);
                    currentNode = nullptr;
                }
            }
            else
            {
                uniqueNodes.emplace(data);
                previousNode = currentNode;
                currentNode = currentNode->getNext();
            }
        }
    }

    void removeDuplicates2()
    {
        Node* node1 = head;
        while(nullptr != node1 && nullptr != node1->getNext())
        {
            Node* node2 = node1->getNext();
            Node* prev = node1;
            while(nullptr != node2)
            {
                if(node1->getData() == node2->getData())
                {
                    if(nullptr != node2->getNext())
                    {
                        prev->setNext(node2->getNext());
                        delete node2;
                        node2 = prev->getNext();
                    }
                    else
                    {
                        prev->setNext(nullptr);
                        node2 = nullptr;
                    }
                }
                else
                {
                    prev = node2;
                    node2 = node2->getNext();
                }
            }
            if(nullptr != node1)
                node1 = node1->getNext();
        }
    }


    void printValues()
    {
        Node* currentNode = head;
        while(nullptr != currentNode)
        {
            cout<<currentNode->getData()<<'\n';
            currentNode = currentNode->getNext();
        }
    }
};


int main()
{
    int n;
    LinkedList ll;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        ll.addNode(x);
    }
    ll.removeDuplicates2();
    ll.printValues();
    return 0;
}
