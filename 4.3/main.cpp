#include <iostream>
#include <vector>
#include <queue>

struct BSTNode
{
    int data;
    int level;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int d): data{d}, level{-1}, left{nullptr}, right{nullptr} {}
};

struct LLNode
{
    BSTNode* data;
    LLNode* next;
    LLNode(BSTNode* d): data{d}, next{nullptr} {}
};

class LinkedList
{
public:
    LLNode* head = nullptr;

    void add(BSTNode* node)
    {
        LLNode* newHead = new LLNode(node);
        newHead->next = head;
        head = newHead;
    }

    void toString()
    {
        LLNode* current = head;
        while(current)
        {
            std::cout<<current->data->data<<' ';
            current = current->next;
        }
        std::cout<<'\n';
    }
};

void createLinkedLists(BSTNode* root)
{
    std::vector<LinkedList*> linkedLists;
    std::queue<BSTNode*>Q;

    root->level = 0;
    Q.push(root);
    while(!Q.empty())
    {
        BSTNode* frontNode = Q.front();
        Q.pop();

        if(frontNode->level >= linkedLists.size())
        {

            linkedLists.push_back(new LinkedList());
        }

        linkedLists[frontNode->level]->add(frontNode);

        if(frontNode->left)
        {
            frontNode->left->level = frontNode->level+1;
            Q.push(frontNode->left);
        }

        if(frontNode->right)
        {
            frontNode->right->level = frontNode->level+1;
            Q.push(frontNode->right);
        }
    }

    for(LinkedList* list: linkedLists)
    {
        list->toString();
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
    a->right = c;
    b->left = d;
    d->right = e;
    c->right = f;

    createLinkedLists(a);
    return 0;
}
