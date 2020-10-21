#include <iostream>
#include <vector>
#include <queue>

struct Node
{
    bool visited = false;
    std::vector<Node*> adj;
};

class Graph
{
public:
    std::vector<Node*> nodes;

    void addNode(Node* node)
    {
        nodes.push_back(node);
    }

    void addEdge(Node* n1, Node* n2)
    {
        n1->adj.push_back(n2);
    }

    bool findPath(Node* start, Node* destination)
    {
        if(start == destination)
        {
            return true;
        }
        std::queue<Node*> Q;
        Q.push(start);
        start->visited = true;
        while(!Q.empty())
        {
            Node* current = Q.front();;
            Q.pop();

            for(Node* neighbour: current->adj)
            {
                if(!neighbour->visited)
                {
                    neighbour->visited = true;
                    if(neighbour == destination)
                    {
                        refreshNodes();
                        return true;
                    }
                    else
                    {
                        Q.push(neighbour);
                    }
                }
            }
        }
        refreshNodes();
        return false;
    }

private:
    void refreshNodes(){
        for(Node* node: nodes){
            node->visited = false;
        }
    }
};

int main()
{
    Graph g;
    Node* a = new Node;g.addNode(a);
    Node* b = new Node;g.addNode(b);
    Node* c = new Node;g.addNode(c);
    Node* d = new Node;g.addNode(d);
    Node* e = new Node;g.addNode(e);
    g.addEdge(a, b);
    g.addEdge(c, b);
    g.addEdge(b, e);
    std::cout<<g.findPath(a, c)<<'\n';
    std::cout<<g.findPath(a, e)<<'\n';
    std::cout<<g.findPath(a, a)<<'\n';
    std::cout<<g.findPath(a, d)<<'\n';
    return 0;
}
