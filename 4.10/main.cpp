#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d): data{d}, left{nullptr}, right{nullptr} {}
};

bool subTree(Node* n1, Node* n2);
bool matchTree(Node* n1, Node* n2);

bool containsTree(Node* n1, Node* n2)
{
    if(!n2)
    {
        return true;
    }
    return subTree(n1, n2);
}

bool subTree(Node* n1, Node* n2)
{
    if(!n1)
    {
        return false;
    }
    if(n1->data == n2->data && matchTree(n1, n2))
    {
        return true;
    }

    return subTree(n1->left, n2) || subTree(n1->right, n2);
}

bool matchTree(Node* n1, Node* n2)
{
    if(!n1 &&! n2)
    {
        return true;
    }
    else if(!n1 || !n2)
    {
        return false;
    }
    else
    {
        return n1->data == n2->data && matchTree(n1->left, n2->left) && matchTree(n1->right, n2->right);
    }
}

int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->left = n3;
    n1->right = n2;
    n2->left = n4;

    Node* n5 = new Node(2);
    Node* n6 = new Node(4);
    n5->left = n6;
    cout<<containsTree(n1, n5);
    return 0;
}
