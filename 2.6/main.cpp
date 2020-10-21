#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int d): data{d}, next{nullptr} {}
};

class LinkedList
{
public:
    Node* head = nullptr;

    void add(int d)
    {
        Node* node = new Node(d);
        if(head == nullptr)
        {
            head = node;
            return;
        }
        Node* current = head;
        while(current->next != nullptr)
        {
            current = current->next;
        }
        current->next = node;
    }

    void printList()
    {
        Node* current = head;
        while(current != nullptr)
        {
            cout<<current->data<<'\n';
            current = current->next;
        }
    }

};

void solve(Node* &head, int& hi, Node* tail, int ti, bool& result)
{
    if(tail->next != nullptr)
    {
        solve(head, hi, tail->next, ti+1, result);
    }

    if(hi < ti)
    {
        if(head->data != tail->data)
        {
            result = false;
        }
        head = head->next;
        hi++;
    }

}

bool isPalindrome(LinkedList& ll)
{
    bool result = true;
    Node* head = ll.head;
    Node* tail = ll.head;
    int hi=1, length=1;
    if(head == nullptr)
    {
        return false;
    }

    solve(head, hi, tail, 1, result);

    return result;
}

bool isPalindrome1(LinkedList& ll)
{
    Node* fast = ll.head;
    Node* slow = ll.head;

    stack<int> st;
    while(fast != nullptr && fast->next != nullptr)
    {
        st.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast != nullptr)
    {
        slow = slow->next;
    }
    while(!st.empty())
    {
        if(slow->data != st.top())
        {
            return false;
        }
        slow = slow->next;
        st.pop();
    }
    return true;
}

int main()
{
    LinkedList ll;
    ll.add(1);
    cout<<isPalindrome1(ll)<<'\n';
    ll.add(2);
    cout<<isPalindrome1(ll)<<'\n';
    ll.add(3);
    cout<<isPalindrome1(ll)<<'\n';
    ll.add(2);
    cout<<isPalindrome1(ll)<<'\n';
    ll.add(1);
    cout<<isPalindrome1(ll)<<'\n';
    //cout<<isPalindrome(ll)<<'\n';
    return 0;
}
