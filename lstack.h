#include<iostream>

#ifndef LSTACK_H
#define LSTACK_H

template<typename T>
struct node {
    T element;
    node<T>* next;
};

template<typename T>
class lstack {
    public:
        lstack();
        ~lstack();
        lstack(const lstack<T>&);
        lstack<T>& operator=(const lstack<T>&);

        void push(const T&);
        T pop();
        void swapstack(lstack<T>&);
        void swap(int, int);
        void reverseStack();

        T top() const;
        int size() const;
        bool isEmpty() const;

        void print(std::ostream& = std::cout);

        friend std::ostream& operator<<(std::ostream& os, lstack<T>& _stack) {
            _stack.print(os);
            return os;
        }

    private:
        node<T>* start;

        void CopyStack(const lstack<T>&);
        void DelStack();
};

template<typename T>
lstack<T>::lstack() {
    start = NULL;
};

template<typename T>
lstack<T>::~lstack() {
    DelStack();
};

template<typename T>
lstack<T>::lstack(const lstack<T>& _stack) {
    CopyStack(_stack);
};

template<typename T>
lstack<T>& lstack<T>::operator=(const lstack<T>& newStack) {
    if(this != &newStack) {
        DelStack();
        CopyStack(newStack);
    }
    return *this;
};

template<typename T>
void lstack<T>::CopyStack(const lstack<T>& _stack) {
    if(_stack.isEmpty()) {
            start = NULL;
    }
    else {
        node<T>* startCopy = _stack.start;
        start = new node<T>;
        start->element = startCopy->element;
        node<T>* helper = NULL;
        start->next = helper;
        helper = start;
        startCopy = startCopy->next;
        while(startCopy) {
            node<T>* temp = new node<T>;
            temp->element = startCopy->element;
            temp->next = NULL;
            helper->next = temp;
            helper = temp;
            startCopy = startCopy->next;
        }
    }
};

template<typename T>
void lstack<T>::DelStack() {
    node<T>* temp;
    while(!isEmpty()) {
        temp = start;
        start = start->next;
        delete temp;
    }
};

template<typename T>
void lstack<T>::push(const T& newElement) {
    node<T>* temp = new node<T>;
    temp->element = newElement;
    temp->next = start;
    start = temp;
};

template<typename T>
T lstack<T>::pop() {
    if(start) {
        T returnVal = start->element;
        node<T>* m = start;
        start = start->next;
        delete m;
        return returnVal;
    }
    else {
        std::cout<<"The stack is empty ";
    }
};

template<typename T>
void lstack<T>::reverseStack() {
    lstack<T>* temp = new lstack<T>();
    while(!isEmpty()) {
        temp->push(this->pop());
    }
    this->operator=(*temp);
}
template<typename T>
void lstack<T>::swap(int index1, int index2) {
    if(index1 >= this->size() || index2 >= this->size() || index1 == index2) {
        return;
    }
    node<T>* temp = start;
    T firstVal;
    T secondVal;
    int i = 0;

    while(temp) {
        if(i == index1) {
            firstVal = temp->element;
        }
        if(i == index2) {
            secondVal = temp->element;
        }
        temp=temp->next;
        i++;
    }
    temp = start;
    i=0;
    while(temp) {
        if(i == index1) {
            temp->element = secondVal;
        }
        if(i == index2) {
            temp->element = firstVal;
        }
        temp=temp->next;
        i++;
    }
};

template<typename T>
void lstack<T>::swapstack(lstack<T>& _stack) {
    node<T>* temp = start;
    start = _stack.start;
    _stack.start = temp;
}

template<typename T>
T lstack<T>::top() const {
    if(!isEmpty()) {
        return start->element;
    } else {
        std::cout<<"The stack is empty\n";
    }
}

template<typename T>
int lstack<T>::size() const {
    node<T>* temp = start;
    int counter = 0;
    while(temp) {
        counter++;
        temp = temp->next;
    }
    return counter;
};

template<typename T>
bool lstack<T>::isEmpty() const {
    return start == NULL;
};

template<typename T>
void lstack<T>::print(std::ostream& os) {
    while(!isEmpty()) {
        os<<this->pop()<<" ";
    }
}

#endif
