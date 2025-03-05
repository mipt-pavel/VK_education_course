#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node() : data(0), next(nullptr), prev(nullptr) {} 
    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    LinkedList(Node<T>* head) : head(head) {}

    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    bool operator==(const LinkedList& other) const {
        Node<T>* current1 = head;
        Node<T>* current2 = other.head;

        while (current1 != nullptr || current2 != nullptr) {
            if (current1 == nullptr || current2 == nullptr) {
                return false;
            }
            if (current1->data != current2->data) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }

        return true;
    }

    void push_front(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    void push_back(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    Node<T>* getHead() const {
        return head;
    }

    void print() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "\n";
    }

    void reverseLinkedList() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;
    
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
    
        head = prev;
    }

    void removeElement(T val) {
        Node<T>* dummy = new Node<T>();
        dummy->next = head;
        Node<T>* prev = dummy;
        Node<T>* current = head;

        while (current != nullptr) {
            if (current->data == val) {
                prev->next = current->next;
            } else {
                prev = current;
            }
            current = current->next;
        }

        head = dummy->next;
    }

    bool isCycle() {
        Node<T>* slow = head;
        Node<T>* fast = head->next;
    
        if (slow == nullptr || fast == nullptr) {
            return false;
        }
    
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }

    Node<T>* middleNode() {
        Node<T>* slow = head;
        Node<T>* fast = head;
    
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
    
        return slow;
    }
};

template <typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    Queue() : head(nullptr), tail(nullptr), size(0) {
        Node<T>* node1 = new Node<T>();
        Node<T>* node2 = new Node<T>();
        head = node1;
        tail = node2;
        head->next = tail;
        tail->prev = head;
    }

    ~Queue() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(T val) {
        Node<T>* newNode = new Node<T>(val);

        newNode->next = head->next;
        newNode->prev = head;

        head->next->prev = newNode;
        head->next = newNode;

        size++;
    }

    void pop() {
        if (head == tail) {
            std::cout << "Очередь пуста" << std::endl;
            return;
        }

        Node<T>* pop_result = tail->prev;
        tail->prev = pop_result->prev;

        pop_result->prev->next = pop_result->next;

        pop_result->next = nullptr;
        pop_result->prev = nullptr;

        size--;
    }

    T peek() {
        if (head == tail) {
            std::cout << "Очередь пуста" << std::endl;
            return -1;
        }

        return tail->prev->data;
    }

    int getSize() {
        return size;
    }
};

#endif