#include <iostream>
#include <vector>

struct BSTNode
{
    int data = -1;
    int level = -1;
    BSTNode* left = nullptr;
    BSTNode* right = nullptr;
};

void createBST(BSTNode* currentNode, int maxLevel, int& nodesCreated, int maxNodes){
    if(currentNode->level < maxLevel){
        if(nodesCreated < maxNodes){
            BSTNode* left = new BSTNode;
            currentNode->left = left;
            left->level = currentNode->level+1;
            nodesCreated++;
            createBST(left, maxLevel, nodesCreated, maxNodes);
        }

        if(nodesCreated < maxNodes){
            BSTNode* right = new BSTNode;
            currentNode->right = right;
            right->level = currentNode->level+1;
            nodesCreated++;
            createBST(right, maxLevel, nodesCreated, maxNodes);
        }
    }
}

void updateBST(BSTNode* currentNode, std::vector<int>& numbers, int& currentIndex){
    if(currentNode->left){
        updateBST(currentNode->left, numbers, currentIndex);
    }

    currentNode->data = numbers[currentIndex];
    currentIndex++;

    if(currentNode->right){
        updateBST(currentNode->right, numbers, currentIndex);
    }
}

BSTNode* buildBST(std::vector<int>& numbers)
{
    int length = numbers.size(), maxLevel = 0;
    if(length == 0)
    {
        //throw ArraySizeException();
        return nullptr;
    }

    BSTNode* root = new BSTNode;
    root->level = 0;

    while(length > (1<<maxLevel)-1)
    {
        maxLevel++;
    }

    int currentIndex = 0;
    int nodesCreated = 1;
    createBST(root, maxLevel-1, nodesCreated, length);
    updateBST(root, numbers, currentIndex);

    return root;
}

BSTNode* createBST2(std::vector<int>& numbers, int low, int high, int level){
    if(low>high){
        return nullptr;
    }
    int mid = (low+high)/2;
    BSTNode* node = new BSTNode;
    node->data = numbers[mid];
    node->level = level;
    node->left = createBST2(numbers, low, mid-1, level+1);
    node->right = createBST2(numbers, mid+1, high, level+1);
    return node;
}

BSTNode* buildBST2(std::vector<int>& numbers){
    if(numbers.size()==0){
        //throw ArraySizeException();
        return nullptr;
    }

    return createBST2(numbers, 0, numbers.size()-1, 0);
}

void dfs(BSTNode* currentNode){
    std::cout<<currentNode->level<<' '<<currentNode->data<<'\n';

    if(currentNode->left){
        dfs(currentNode->left);
    }

    if(currentNode->right){
        dfs(currentNode->right);
    }
}
int main()
{
    std::vector<int> numbers;
    for(int i=1; i<=10; i++){
        numbers.push_back(i);
        //BSTNode* root = buildBST(numbers);
        //dfs(root);
        //std::cout<<'\n';
        BSTNode* root = buildBST2(numbers);
        dfs(root);
        std::cout<<'\n';
    }

    return 0;
}
