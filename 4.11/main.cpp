#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    int children;
    Node(int d): data{d}, left{nullptr}, right{nullptr}, children{0} {}
};

class RandomTree
{
    Node* root = nullptr;
public:
    void add(Node* node)
    {
        if(!root)
        {
            root = node;
        }
        else
        {
            recursiveAdd(root, node);
        }
    }

    void recursiveAdd(Node* current, Node* newNode)
    {
        current->children++;
        if(newNode->data <= current->data)
        {
            if(current->left)
            {
                recursiveAdd(current->left, newNode);
            }
            else
            {
                current->left = newNode;
            }
        }
        else
        {
            if(current->right)
            {
                recursiveAdd(current->right, newNode);
            }
            else
            {
                current->right = newNode;
            }
        }
    }

    int getRandom(int x)
    {
        int nrNodes = getSize();
        if(!nrNodes)
        {
            return -1; // Exception should be thrown
        }
        int randomValue = rand()%nrNodes;
        if(x != -1){
            randomValue = x;
        }
        //cout<<nrNodes<<' '<<randomValue<<'\n';
        return getRandomRecursive(root, randomValue);
    }

    int getRandomRecursive(Node* node, int randomValue)
    {
        int leftChildren = node->left ? node->left->children+1 : 0;
        if(randomValue < leftChildren)
        {
            return getRandomRecursive(node->left, randomValue);
        }
        else if(randomValue > leftChildren)
        {
            return getRandomRecursive(node->right, randomValue-1-leftChildren);
        }
        else
        {
            return node->data;
        }
    }

    int getSize()
    {
        int answer = 0;
        if(root)
        {
            answer = 1 + root->children;
        }
        return answer;
    }
};


int main()
{
    RandomTree t;
    t.add(new Node(4));
    t.add(new Node(3));
    t.add(new Node(5));
    t.add(new Node(1));
    t.add(new Node(2));
    t.add(new Node(8));
    t.add(new Node(7));
    for(int i=0; i<7; i++){
        cout<<t.getRandom(i)<<' ';
    }
    cout<<t.getRandom(-1);
    return 0;
}
