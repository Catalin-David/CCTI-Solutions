#include <iostream>
#include <vector>
#include <limits>
struct BTNode
{
    int data;
    BTNode* left;
    BTNode* right;
    BTNode(int d): data{d}, left{nullptr}, right{nullptr} {}
};

bool dfs(BTNode* current, int low, int high){
    bool result_left = true, result_right = true;
    if(current->left){
        result_left = dfs(current->left, low, current->data);
    }
    if(current->right){
        result_right = dfs(current->right, current->data, high);
    }
    return result_left && result_right && low <= current->data && current->data < high;
}

bool isBinarySearchTree(BTNode* root)
{
    return dfs(root, INT_MIN, INT_MAX);
}

int main()
{
    BTNode* a = new BTNode(1);
    std::cout<<isBinarySearchTree(a)<<'\n';
    BTNode* b = new BTNode(2);
    //a->left = b;
    a->right = b;
    std::cout<<isBinarySearchTree(a)<<'\n';

    BTNode* c = new BTNode(4);
    //a->left = c;
    //b->left = c;
    b->right = c;
    std::cout<<isBinarySearchTree(a)<<'\n';
    return 0;
}
