template <class T>
class Stack
{
public:
    struct Node
    {
        T data;
        Node* next;
        Node(T d): data{d}, next{nullptr} {}
    } ;

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
    set<int> av;
    SetOfStacks(int capacity)
    {
        // check capacity is at least 1
        stcap = capacity;
    }

    void push(T d)
    {
        if(stacks.size() == 0 || av.size() == 0)
        {
            Stack<T>* newStack = new Stack<T>();
            newStack->push(d);
            stacks.push_back(newStack);
            if(stcap > 1)
            {
                av.emplace(stacks.size()-1);
            }
            return;
        }
        set<int>::iterator it = av.begin();
        Stack<T>* st = stacks[*it];
        st->push(d);
        if(stcap == st->height)
        {
            av.erase(it);
        }
    }

    void pop()
    {
        int index = getTopIndex();
        if(index >= 0)
        {
            popAt(index);
        }
    }

    void popAt(int index)
    {
        if(index >= stacks.size())
        {
            cout<<"Exception\n";
            return;
        }
        Stack<T>* st = stacks[index];
        if(st->height != 0)
        {
            st->pop();
        }
        av.emplace(index);
    }

    T top()
    {
        if(stacks.size() == 0)
        {
            cout<<"Exception thrown\n";
            return T(0);
        }
        int index = getTopIndex();
        if(index != -1){
            return stacks[getTopIndex()]->top->data;
        }
        return T(0);
    }

    int getTopIndex()
    {
        for(int i=stacks.size() - 1; i>=0; i--)
        {
            if(stacks[i]->height != 0)
            {
                return i;
            }
        }
        return -1;
    }
};
