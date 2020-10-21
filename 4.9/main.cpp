#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d): data{d}, left{nullptr}, right{nullptr} {}
};

list<deque<int>> weaveLists(deque<int>& left, deque<int>& right, deque<int>& prefix);

list<deque<int>> getAllLists(Node* root)
{
    list<deque<int>> result;
    if(!root)
    {
        result.emplace_back();
        return result;
    }

    deque<int> prefix;
    prefix.push_back(root->data);

    auto leftSub = getAllLists(root->left);
    auto rightSub = getAllLists(root->right);

    for(auto &left: leftSub)
    {
        for(auto &right: rightSub)
        {
            auto joins = weaveLists(left, right, prefix);
            result.splice(result.end(), move(joins));
        }
    }
    return result;
}

list<deque<int>> weaveLists(deque<int>& left, deque<int>& right, deque<int>& prefix)
{
    list<deque<int>> result;

    if(left.empty() || right.empty())
    {
        deque<int> r(prefix);
        r.insert(r.end(), left.begin(), left.end());
        r.insert(r.end(), right.begin(), right.end());

        result.push_back(move(r));
        return result;
    }

    prefix.push_back(left.front());
    left.pop_front();
    result.splice(result.end(), weaveLists(left, right, prefix));
    left.push_front(prefix.back());
    prefix.pop_back();

    prefix.push_back(right.front());
    right.pop_front();
    result.splice(result.end(), weaveLists(left, right, prefix));
    right.push_front(prefix.back());
    prefix.pop_back();
}



int main()
{
    Node* node1 = new Node(2);
    Node* node2 = new Node(1);
    Node* node3 = new Node(3);

    node1->left = node2;
    node1->right = node3;

    list<deque<int>> result = getAllLists(node1);
    for(auto it: result){
        for(auto it1: it){
            cout<<it1<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
