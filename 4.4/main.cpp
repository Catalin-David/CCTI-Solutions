#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode* left = nullptr;
    BSTNode* right = nullptr;
};

int postOrder(BSTNode* current)
{
    int left_depth=0, right_depth=0;
    if(current->left)
    {
        left_depth = postOrder(current->left);
    }
    if(current->right)
    {
        right_depth = postOrder(current->right);
    }

    if(left_depth == -1 || right_depth == -1 || abs(left_depth - right_depth) > 1)
    {
        return -1;
    }

    return max(left_depth, right_depth)+1;
}

bool isTreeBalanced(BSTNode* root)
{
    return postOrder(root) != -1;
}


int main()
{
    BSTNode* a = new BSTNode;
    cout<<isTreeBalanced(a)<<'\n';
    BSTNode* b = new BSTNode;
    a->left = b;
    cout<<isTreeBalanced(a)<<'\n';
    BSTNode* c = new BSTNode;
    b->right = c;
    cout<<isTreeBalanced(a)<<'\n';
    BSTNode* d = new BSTNode;
    a->right = d;
    cout<<isTreeBalanced(a)<<'\n';
    return 0;
}
