#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
struct Node
{
    std::string data;
    int inboundDegree;
    std::vector<Node*> adj;
    Node(std::string name): data{name}, inboundDegree{0} {}
};

std::vector<std::string> getProjectsOrdered(std::vector<std::string> projects, std::vector<std::vector<std::string> >dependencies)
{
    std::unordered_map<std::string,int> dtn;
    std::vector<Node*> nodes;
    std::vector<std::string> result;
    std::queue<Node*> Q;

    for(std::string s: projects)  // O(n)
    {
        nodes.push_back(new Node(s));
        dtn[s] = nodes.size()-1;
    }
    for(std::vector<std::string> v: dependencies)  // O(n)
    {
        std::string n1 = v[0];
        std::string n2 = v[1];

        nodes[dtn[n1]]->adj.push_back(nodes[dtn[n2]]);
        nodes[dtn[n2]]->inboundDegree++;
    }
    for(Node* node: nodes)  // O(n)
    {
        if(node->inboundDegree == 0)
        {
            Q.push(node);
            result.push_back(node->data);
        }
    }

    while(!Q.empty())  // O(n+m)
    {
        Node* node = Q.front();
        Q.pop();

        for(Node* neighbour: node->adj)
        {
            neighbour->inboundDegree--;
            if(neighbour->inboundDegree == 0)
            {
                Q.push(neighbour);
                result.push_back(neighbour->data);
            }
        }
    }

    if(result.size() != projects.size())
    {
        //throw CycleFoundException();
    }
    return result;
}


int main()
{
    std::vector<std::string> n;
    n.push_back("a");n.push_back("b");n.push_back("c");n.push_back("d");n.push_back("e");n.push_back("f");
    std::vector<std::string> d;
    std::vector<std::vector<std::string> > f;
    d.push_back("a");
    d.push_back("d");
    f.push_back(d);
    d.clear();
        d.push_back("f");
    d.push_back("b");
    f.push_back(d);
    d.clear();
        d.push_back("b");
    d.push_back("d");
    f.push_back(d);
    d.clear();
        d.push_back("f");
    d.push_back("a");
    f.push_back(d);
    d.clear();
        d.push_back("d");
    d.push_back("c");
    f.push_back(d);
    d.clear();

    std::vector<std::string> r = getProjectsOrdered(n, f);
    for(auto g: r){
        std::cout<<g<<' ';
    }
    return 0;
}
