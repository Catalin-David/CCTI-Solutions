#include <iostream>
using namespace std;

template <class T>
class MyStack
{
public:
    struct SNode
    {
        T data;
        SNode* next;
        SNode(T d): data{d}, next{nullptr} {}
    };

    SNode* top = nullptr;

    void add(int d)
    {
        SNode* newTop = new SNode(d);
        newTop->next = top;
        top = newTop;
    }

    T peek(){
        if(isEmpty()){
            //throw EmptyStackException();
        }
        return top->data;
    }

    T pop()
    {
        if(isEmpty())
        {
            //throw EmptyStackException();
        }

        int result = top->data;
        top = top->next;

        return result;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

};

template <class T>
class MyQueue
{
public:
    MyStack<T> s1;
    MyStack<T> s2;

    void add(T d)
    {
        s1.add(d);
    }

    T peek(){
        shiftStacks();
        return s2.peek();
    }

    T remove()
    {
        shiftStacks();
        return s2.pop();
    }

    bool isEmpty(){
        return s1.isEmpty() && s2.isEmpty();
    }
private:
    void shiftStacks(){
        if(s2.isEmpty())
        {
            while(!s1.isEmpty())
            {
                s2.add(s1.pop());
            }
        }
    }
};


int main()
{
    MyQueue<int> q;
    q.add(1);
    q.add(2);
    cout<<q.remove()<<'\n';
    q.add(3);
    cout<<q.remove()<<'\n';
    cout<<q.peek()<<'\n';
    cout<<q.peek()<<'\n';
    return 0;
}
