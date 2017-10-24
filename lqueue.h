#include<iostream>
#ifndef LQUEUE_H
#define LQUEUE_H
template<typename T>
struct node {
    T element;
    node<T>* next;
};

template<typename T>
class lqueue {
    public:
        //Big 4
        lqueue();
        ~lqueue();
        lqueue(const lqueue&);
        lqueue& operator=(const lqueue&);

        void push(const T&);
        T pop();
        bool isEmpty() const;
        T front() const;
        T back() const;
        int size() const;
        void swapqueue(lqueue<T>&);
        void swap(int, int);

        void print(std::ostream& = std::cout);
        friend std::ostream& operator<<(std::ostream& os, lqueue<T>& _queue) {
            _queue.print(os);
            return os;
        }

    private:
        node<T>* head;
        node<T>* tail;
        void CopyQueue(const lqueue&);
        void DelQueue();
};
template<typename T>
lqueue<T>::lqueue() {
    head = tail = NULL;
}
template<typename T>
lqueue<T>::~lqueue() {
    DelQueue();
}
template<typename T>
lqueue<T>::lqueue(const lqueue<T>& s) {
    CopyQueue(s);
}
template<typename T>
lqueue<T>& lqueue<T>::operator=(const lqueue<T>& _queue) {
    if(this != &_queue) {
        DelQueue();
        CopyQueue(_queue);
    }
    return *this;
}
template <typename T>
void lqueue<T>::push(const T& element) {
    node<T>* temp = new node<T>;
    temp->element = element;
    temp->next = NULL;

    if(head == NULL) {
        head = tail = temp;
    }
    else if(head->next==NULL) {
        tail = temp;
        head->next = tail;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
};
template<typename T>
T lqueue<T>::pop() {
    if(head == tail) {
        node<T>* temp = head;
        T returnMe = temp->element;
        delete temp;
        head = tail = NULL;
        return returnMe;
    }
    else if(head) {
        node<T>* temp = head;
        T returnMe = temp->element;
        head = head->next;
        delete temp;
        return returnMe;
    }
};

template<typename T>
bool lqueue<T>::isEmpty() const {
    return (head == NULL && tail == NULL);
};

template<typename T>
T lqueue<T>::front() const {
    if(!isEmpty()) {
        return head->element;
    } else {
        std::cout<<"The queue is empty.\n";
    }
};

template<typename T>
T lqueue<T>::back() const {
    if(!isEmpty()) {
        return tail->element;
    } else {
        std::cout<<"The queue is empty.\n";
    }
};

template<typename T>
int lqueue<T>::size() const {
    int counter = 0;
    node<T>* temp = head;
    while(temp) {
        counter++;
        temp=temp->next;
    }
    return counter;
};

template<typename T>
void lqueue<T>::print(std::ostream& os) {
    while(!isEmpty()) {
        os<<pop()<<" ";
    }
};

template<typename T>
void lqueue<T>::DelQueue() {
    if(!isEmpty()) {
        node<T>* temp;
        while(head) {
            temp = head;
            head = head->next;
            delete[] temp;
        }
        if(tail)delete[] tail;

        head = tail = NULL;
    }
};

template<typename T>
void lqueue<T>::swapqueue(lqueue<T>& swapQueue){
    node<T>* tempHead = head;
    node<T>* tempTail = tail;

    head = swapQueue.head;
    tail = swapQueue.tail;

    swapQueue.head = tempHead;
    swapQueue.tail = tempTail;
}

template<typename T>
void lqueue<T>::swap(int index1, int index2) {
    if(index1 >= size() || index2 >= size() || index1 == index2) {
        return;
    }

    node<T>* temp = head;
    T firstElement;
    T secondElement;
    int i = 0;
    while(temp) {
        if(i == index1) {
            firstElement = temp->element;
        }
        if(i == index2) {
            secondElement = temp->element;
        }
        i++;
        temp = temp->next;
    }
    i=0;
    temp = head;
    while(temp) {
        if(i == index1) {
            temp->element = secondElement;
        }
        if(i == index2) {
            temp->element = firstElement;
        }
        i++;
        temp = temp->next;
    }
}

template<typename T>
void lqueue<T>::CopyQueue(const lqueue<T>& _queue) {
    if(!_queue.isEmpty()) {
        node<T>* tempHead = _queue.head;
        node<T>* helper;
        head = new node<T>;
        head->element = tempHead->element;
        head->next = NULL;
        tempHead = tempHead->next;

        if(tempHead) {
            tail = new node<T>;
            tail->element = tempHead->element;
            tail->next = NULL;
            tempHead = tempHead->next;
        }
        else {
                tail = NULL;
        }
        head->next = tail;
        while(tempHead) {
            helper = new node<T>;
            helper->element = tempHead->element;
            helper->next = NULL;
            tail->next = helper;
            tail = helper;
            tempHead = tempHead->next;
        }
    }
    else head = tail = NULL;
}

#endif // LQUEUE_H
