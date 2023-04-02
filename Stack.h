#pragma once
#include <iostream>
#include <string>

using namespace std;

template<typename T>
struct Node {
    T data;
    static int count;
    Node<T>* next;

    Node() {
        count++;
    }

    ~Node() {
        count--;
    }
};

template<typename T>
int Node<T>::count = 0;

template<typename T>
class Stack {
private:
    Node<T>* top;
public:
    Stack() {
        top = NULL;
    }

    ~Stack() {
        while(!isEmpty()) {
            pop();
        }
    }

    int size() {
        return Node<T>::count;
    }

    void push(T d) {
        Node<T>* temp = new Node<T>();
        temp->data = d;
        temp->next = top;
        top = temp;
    }

    T pop() {
        if(!isEmpty()) {
            T value = top->data;
            Node<T>* oldTop = top;
            top = oldTop->next;
            delete oldTop;
            return value;
        }
        else {
            cout << "you can't pop from the empty stack." << endl;
        }
    }

    T peek() {
        if(!isEmpty()) {
            T value = top->data;
            return value;
        }
    }

    bool isEmpty() {
        return (top == NULL);
    }

    void toString() {
        if(isEmpty()) {
            cout << "Nothing in the stack." << endl;
        }
        else {
            Node<T>* current = top;
            while(current != NULL) {
                cout << current->data << endl;
                current = current -> next;
            }
        }
    }
};



