#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int key;
    int value;
    Node* next;
    Node(int k, int v): key{k}, value{v}, next{nullptr} {}
};

class HashTable
{
    Node** elements = nullptr;
    int capacity = 0;
    int size = 0;

public:
    void put(int key, int value)
    {
        Node* node = getNodeForKey(key);
        if(node){
            node->value = value;
        }
        else{
            Node* newNode = new Node(key, value);
            add(newNode);
        }
    }

    int get(int key){
        Node* node = getNodeForKey(key);
        if(node == nullptr){
            // throw an error;
        }
        return node->value;
    }

    int remove(int key){
        int result;
        int index = hash(key);
        if(elements[index]->key == key){
            result = elements[index]->value;
            elements[index] = elements[index]->next;
        }
        else{
            Node* prev = elements[index];
            Node* current = prev->next;

            while(current){
                if(current->key == key){
                    prev->next = current->next;
                    result = current->value;
                    break;
                }
                current = current->next;
            }
        }

        return result;
    }

    void iterate(){
        for(int i=0; i<capacity; i++){
            Node* current = elements[i];

            while(current){
                cout<<current->key<<' '<<current->value<<'\n';
                current = current->next;
            }
        }
    }

private:
    void add(Node* node)
    {
        if(elements == nullptr)
        {
            elements = new Node*[2];
            elements[0] = elements[1] = nullptr;
            capacity = 2;
        }

        int index = hash(node->key);
        insertAtIndex(index, node);
    }

    Node* getNodeForKey(int key){
        int index = hash(key);
        if(index < 0 || index >= capacity){
            return nullptr;
        }
        Node* current = elements[index];
        while(current){
            if(current->key == key){
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    int hash(int key)
    {
        if(capacity == 0){
            return -1;
        }
        if(key>=0){
            return key%capacity;
        }
        return (-key)%capacity;
    }

    void insertAtIndex(int index, Node* newNode)
    {
        newNode->next = elements[index];
        elements[index] = newNode;
        size++;
        resize();
    }

    void resize()
    {
        if(size <= capacity * 7 / 10)
        {
            return;
        }

        vector<Node*> nodes;
        for(int i=0; i<capacity; i++)
        {
            Node* current = elements[i];
            while(current)
            {
                nodes.push_back(current);
                current = current->next;
            }
        }
        capacity = capacity * 2;
        size = 0;
        elements = new Node*[capacity];
        for(int i=0; i<capacity; i++){
            elements[i] = nullptr;
        }

        for(Node* node : nodes)
        {
            add(node);
        }
    }
};


int main()
{
    HashTable t;
    t.put(1, 2);
    t.put(5, 4);
    t.put(12, 25);
    t.put(7, 0);
    t.put(7, 7);
    t.iterate();
    cout<<t.get(7)<<'\n';
    cout<<t.remove(12)<<'\n';
    t.iterate();
    return 0;
}
