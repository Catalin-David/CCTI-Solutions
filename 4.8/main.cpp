#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d): data{d}, left{nullptr}, right{nullptr} {}
};


struct Result
{
    Node* node;
    bool isAncestor;
    Result(Node* n, bool flag): node{n}, isAncestor{flag} {}
};

Result* commonAncestorHelper(Node* current, Node* p, Node* q)
{
    if(current == nullptr)
    {
        return new Result(nullptr, false);
    }

    if(current == p && current == q)
    {
        return new Result(current, true);
    }

    Result* rx = commonAncestorHelper(current->left, p, q);
    if(rx->isAncestor)
    {
        return rx;
    }

    Result* ry = commonAncestorHelper(current->right, p, q);
    if(ry->isAncestor)
    {
        return ry;
    }

    if(rx->node && ry->node)
    {
        return new Result(current, true);
    }
    else if(current == p || current == q)
    {
        bool isAncestor = rx->node || ry->node;
        return new Result(current, isAncestor);
    }
    else
    {
        return new Result(rx->node ? rx->node : ry->node, false);
    }
}

int commonAncestor(Node* root, Node* p, Node* q)
{
    Result* res = commonAncestorHelper(root, p, q);
    if(res->isAncestor)
    {
        return res->node->data;
    }
    else
    {
        return -1;
    }
}

int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->left = n2;
    n1->right = n3;
    n2->right = n4;
    cout<<commonAncestor(n1, n1, n4);
    return 0;
}
