#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d): data{d}, left{nullptr}, right{nullptr} {}
};

int countPaths(Node* node, int sum, int goal , unordered_map<int, int>& mp);

int paths(Node* root, int sum)
{
    unordered_map<int, int> freq;
    freq[0] = 1;
    return countPaths(root, 0, sum, freq);
}

int countPaths(Node* node, int sum, int goal, unordered_map<int, int>& freq)
{
    if(!node)
    {
        return 0;
    }

    int newSum = sum + node->data;
    freq[newSum]++;

    int result = freq[newSum-goal];
    result += countPaths(node->left, newSum, goal, freq);
    result += countPaths(node->right, newSum, goal, freq);

    freq[newSum]--;

    return result;
}

int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(1);
    Node* n3 = new Node(1);
    Node* n4 = new Node(1);
    Node* n5 = new Node(1);

    n1->left = n2;
    n1->right = n3;
    n2->right = n4;
    n3->left = n5;

    cout<<paths(n1, 3);
    return 0;
}
