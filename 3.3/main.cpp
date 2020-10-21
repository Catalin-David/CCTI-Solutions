#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Stack
{
public:
    struct Node
    {
        T data;
        Node* next;
        Node(T d): data{d}, next{nullptr} {}
    };

    int height = 0;
    Node* top = nullptr;

    T pop()
    {
        if(top == nullptr)
        {
            cout<<"Exception thrown\n";
            return T(0);
        }
        T item = top->data;
        top = top->next;
        height--;
        return item;
    }

    void push(T d)
    {
        Node* newNode = new Node(d);
        newNode->next = top;
        top = newNode;
        height++;
    }
};

template <class T>
class SetOfStacks
{
public:
    int stcap = 0;
    vector<Stack<T>*> stacks;
    SetOfStacks(int capacity)
    {
        // check capacity is at least 1
        stcap = capacity;
    }

    void push(T d)
    {
        if(stacks.size() == 0 || stacks.back()->height == stcap)
        {
            Stack<T>* newStack = new Stack<T>;
            newStack->push(d);
            stacks.push_back(newStack);
            return;
        }

        stacks.back()->push(d);
    }

    void pop()
    {
        if(stacks.size() == 0)
        {
            cout<<"Exception thrown\n";
            return;
        }
        stacks.back()->pop();
        if(stacks.back()->height == 0)
        {
            stacks.pop_back();
        }
    }

    T top()
    {
        if(stacks.size() == 0)
        {
            cout<<"Exception thrown\n";
            return T(0);
        }
        return stacks.back()->top->data;
    }
};

int main()
{
    SetOfStacks<int> st = SetOfStacks<int>(2);
    st.push(1);
    st.push(2);
    cout<<st.top()<<'\n';
    st.pop();
    cout<<st.top()<<'\n';
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<st.top()<<'\n';
    st.pop();
    st.pop();
    cout<<st.top()<<'\n';
    st.pop();
    st.pop();
    st.pop();
    cout<<st.top()<<'\n';
    return 0;
}
