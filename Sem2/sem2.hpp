#ifndef SEM2_HPP
#define SEM2_HPP

#include <string>
#include "classes.hpp"

bool isSubsequence_queue(std::string a, std::string b) {
    Queue<char>* q = new Queue<char>();
    for (int i = 0; i < a.length(); i++) {
        q->push(a[i]);
    }

    for (int i = 0; i < b.length(); i++) {
        if (q->peek() == b[i]) {
            q->pop();
        }
    }
    return q->getSize() == 0;
}

bool isSubsequence_ptrs(std::string a, std::string b) {
    int i = 0, j = 0;
    while (i < a.length() && j < b.length()) {
        if (a[i] == b[j]) {
            i++;            
        }
        j++;
    }
    return i == a.length();
}

template <typename T>
LinkedList<T> mergeTwoLists(LinkedList<T>* list1, LinkedList<T>* list2) {
    Node<T>* head1 = list1->getHead();
    Node<T>* head2 = list2->getHead();

    Node<T>* dummy = new Node<T>();
    Node<T>* current = dummy;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    if (head1 != nullptr) {
        current->next = head1;
    } else {
        current->next = head2;
    }

    return LinkedList<T>(dummy->next);
}

bool isPalindrome(std::string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

#endif