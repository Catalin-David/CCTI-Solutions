#include <iostream>
using namespace std;

template <class T>
class MyStack
{
public:
    struct StackNode
    {
        T data;
        T minimum;
        StackNode* next;
        StackNode(int d, int m): data{d}, minimum{m}, next{nullptr} {}
    };

    StackNode* top = nullptr;

    T pop()
    {
        if(top == nullptr)
        {
            throw exception();
        }
        T item = top->data;
        top = top->next;
        return item;
    }

    void push(T d)
    {
        T minimum = d;
        if(top != nullptr)
        {
            T currentMin = top->data;
            minimum = minimum < currentMin ? minimum : currentMin;
        }

        StackNode* newNode = new StackNode(d, minimum);

        newNode->next = top;
        top = newNode;
    }

    T min()
    {
        if(top == nullptr)
        {
            throw exception();
        }

        return top->minimum;
    }
};


int main()
{
    MyStack<int> st;

    st.push(10);
    cout<<st.min()<<'\n';
    st.push(5);
    cout<<st.min()<<'\n';
    st.push(7);
    cout<<st.min()<<'\n';
    st.pop();
    st.pop();
    st.push(8);
    cout<<st.min()<<'\n';
    return 0;
}
