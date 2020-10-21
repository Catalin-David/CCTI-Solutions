#include <iostream>

struct BSTNode
{
    int data;
    BSTNode* parent;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int d): data{d}, left{nullptr}, right{nullptr}, parent{nullptr} {}
};

BSTNode* findSuccessor(BSTNode* node)
{
    if(node->right)
    {
        BSTNode* successor = node->right;
        while(successor->left)
        {
            successor = successor->left;
        }
        return successor;
    }
    else
    {
        BSTNode* parentNode = node->parent;
        while(parentNode)
        {
            if(parentNode->left == node)
            {
                return parentNode;
            }
            node = parentNode;
            parentNode = parentNode->parent;
        }
        return nullptr;
    }
}


int main()
{
    BSTNode* a = new BSTNode(1);
    BSTNode* b = new BSTNode(2);
    BSTNode* c = new BSTNode(3);
    BSTNode* d = new BSTNode(4);
    BSTNode* e = new BSTNode(5);
    BSTNode* f = new BSTNode(6);
    a->left = b;
    b->parent = a;
    a->right = c;
    c->parent = a;
    b->right = d;
    d->parent = b;
    c->left = e;
    e->parent = c;
    c->right = f;
    f->parent = c;
    std::cout<<findSuccessor(a)->data<<'\n';
    std::cout<<findSuccessor(b)->data<<'\n';
    std::cout<<findSuccessor(c)->data<<'\n';
    std::cout<<findSuccessor(d)->data<<'\n';
    std::cout<<findSuccessor(e)->data<<'\n';
    return 0;
}
