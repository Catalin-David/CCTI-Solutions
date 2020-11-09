#include <iostream>
#include <stack>
template <class T>
class MyStack
{
public:
    struct Node
    {
        T data;
        Node* next;
        Node(T d): data{d}, next{nullptr} {}
    };

    Node* top = nullptr;

    bool isEmpty()
    {
        return top == nullptr;
    }

    T peek()
    {
        if(isEmpty())
        {
            //throw EmptyStackException();
        }

        return top->data;
    }

    void add(T data)
    {
        Node* node = new Node(data);

        std::stack<T> helper;

        while(!isEmpty() && node->data > peek())
        {
            helper.push(pop());
        }

        node->next = top;
        top = node;

        while(helper.size() > 0)
        {
            Node* newTop = new Node(helper.top());
            helper.pop();
            newTop->next = top;
            top = newTop;
        }

    }

    T pop()
    {
        if(isEmpty())
        {
            //throw EmptyStackException();
        }
        T result = top->data;
        Node* newTop = top->next;
        delete top;
        top = newTop;
        return result;
    }

    void printAll()
    {
        Node* current = top;
        while(current)
        {
            std::cout<<current->data<<' ';
            current = current->next;
        }
        std::cout<<'\n';
    }
};

void sortStack(std::stack<int>& s){
    std::stack<int> r;

    while(!s.empty()){
        int tmp = s.top();
        s.pop();

        while(!r.empty()&& r.top() > tmp){

            s.push(r.top());
            r.pop();
        }

        r.push(tmp);
    }

    while(!r.empty()){
        s.push(r.top());
        r.pop();
    }
}
int main()
{/*
    MyStack<int> s;
    s.add(1);
    s.add(2);
    s.printAll();
    s.add(3);
    s.printAll();
    s.add(10);
    s.add(0);
    s.printAll();
    s.pop();
    s.pop();
    s.printAll();*/

    std::stack<int>s;

    s.push(5);
    s.push(10);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(15);
    sortStack(s);
    while(!s.empty()){
        std::cout<<s.top()<<' ';
        s.pop();
    }
    return 0;
}
