#ifndef MyStack_h
#define MyStack_h
#include <cstddef>

template<class INF, class FRIEND>
class ListNode {
private:
    INF d;
    ListNode* next;
    ListNode(void) { next = nullptr; }
    friend FRIEND;
    
    ListNode(const ListNode& other) : d(other.d), next(nullptr) {
        if (other.next != nullptr) {
            next = new ListNode(*other.next);
        }
    }
    
    ListNode& operator=(const ListNode& other) {
        if (this != &other) {
            d = other.d;
            delete next;
            next = nullptr;
            if (other.next != nullptr) {
                next = new ListNode(*other.next);
            }
        }
        return *this;
    }
};

template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF> > Node;
    Node* top;
    
public:
    MyStack(void) : top(nullptr) {}
    
    ~MyStack(void) {
        while (!empty()) {
            pop();
        }
    }
    
    MyStack(const MyStack& other) : top(nullptr) {
        if (other.top != nullptr) {
            top = new Node(*other.top);
        }
    }
    
    MyStack& operator=(const MyStack& other) {
        if (this != &other) {
            while (!empty()) {
                pop();
            }
            if (other.top != nullptr) {
                top = new Node(*other.top);
            } else {
                top = nullptr;
            }
        }
        return *this;
    }
    
    bool empty(void) {
        return top == nullptr;
    }
    
    bool push(INF n) {
        Node* newNode = new Node();
        newNode->d = n;
        newNode->next = top;
        top = newNode;
        return true;
    }
    
    bool pop(void) {
        if (empty()) return false;
        Node* temp = top;
        top = top->next;
        delete temp;
        return true;
    }
    
    INF top_inf(void) {
        if (empty()) throw "Stack is empty";
        return top->d;
    }
};

#endif