#include <gtest/gtest.h>
#include "sem2.hpp"

// Тесты методов и функций
// isCycle
TEST(isCycle, cycle_case) {
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node2 = new Node<int>(2);
    Node<int>* node3 = new Node<int>(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = node2;

    LinkedList<int>* list = new LinkedList<int>(node1);

    ASSERT_TRUE(list->isCycle());
}

TEST(isCycle, not_cycle_case) {
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node2 = new Node<int>(2);
    Node<int>* node3 = new Node<int>(3);
    node1->next = node2;
    node2->next = node3;

    LinkedList<int>* list = new LinkedList<int>(node1);

    ASSERT_FALSE(list->isCycle());
}

// reverseLinkedList
TEST(reverseLinkedList, Basic_case_1) {
    LinkedList<int> list;
    LinkedList<int> valid_output;
    
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    valid_output.push_back(4);
    valid_output.push_back(3);
    valid_output.push_back(2);
    valid_output.push_back(1);

    list.reverseLinkedList();

    ASSERT_EQ(valid_output, list);
}

TEST(reverseLinkedList, empty_case) {
    LinkedList<int> list;
    LinkedList<int> valid_output;

    list.reverseLinkedList();

    ASSERT_EQ(valid_output, list);
}

// middleNode
TEST(middleNode, Basic_case_1) {
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node2 = new Node<int>(2);
    Node<int>* node3 = new Node<int>(3);
    Node<int>* node4 = new Node<int>(4);
    Node<int>* node5 = new Node<int>(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    LinkedList<int>* list = new LinkedList<int>(node1);

    ASSERT_EQ(node3, list->middleNode());
}

TEST(middleNode, Basic_case_2) {
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node2 = new Node<int>(2);
    Node<int>* node3 = new Node<int>(3);
    Node<int>* node4 = new Node<int>(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    LinkedList<int>* list = new LinkedList<int>(node1);

    ASSERT_EQ(node3, list->middleNode());
}

TEST(middleNode, empty_case) {
    LinkedList<int>* list = new LinkedList<int>(nullptr);

    ASSERT_EQ(nullptr, list->middleNode());
}

// isSubsequence_ptrs
TEST(isSubsequence_ptrs, Basic_case_1) {
    std::string str1 = "abd";
    std::string str2 = "uabqdw";

    ASSERT_TRUE(isSubsequence_ptrs(str1, str2));
}

TEST(isSubsequence_ptrs, Basic_case_2) {
    std::string str1 = "abd";
    std::string str2 = "ubaqdw";

    ASSERT_FALSE(isSubsequence_ptrs(str1, str2));
}

TEST(isSubsequence_ptrs, Basic_case_3) {
    std::string str1 = "";
    std::string str2 = "ubaqdw";

    ASSERT_TRUE(isSubsequence_ptrs(str1, str2));
}

// isSubsequence_queue
TEST(isSubsequence_queue, Basic_case_1) {
    std::string str1 = "abd";
    std::string str2 = "uabqdw";

    ASSERT_TRUE(isSubsequence_queue(str1, str2));
}

TEST(isSubsequence_queue, Basic_case_2) {
    std::string str1 = "abd";
    std::string str2 = "ubaqdw";

    ASSERT_FALSE(isSubsequence_queue(str1, str2));
}

TEST(isSubsequence_queue, Basic_case_3) {
    std::string str1 = "";
    std::string str2 = "uabqdw";

    ASSERT_TRUE(isSubsequence_queue(str1, str2));
}

// isPalindrome
TEST(isPalindrome, Basic_case_1) {
    std::string str = "abba";

    ASSERT_TRUE(isPalindrome(str));
}

TEST(isPalindrome, Basic_case_2) {
    std::string str = "abbacool";

    ASSERT_FALSE(isPalindrome(str));
}

TEST(isPalindrome, empty_case) {
    std::string str = "";

    ASSERT_TRUE(isPalindrome(str));
}

// mergeTwoLists
TEST(mergeTwoLists, Basic_case_1) {
    LinkedList<int>* list1 = new LinkedList<int>();
    LinkedList<int>* list2 = new LinkedList<int>();
    LinkedList<int> valid_output;
    
    list1->push_back(3);
    list1->push_back(6);
    list1->push_back(8);

    list2->push_back(4);
    list2->push_back(7);
    list2->push_back(9);
    list2->push_back(11);

    valid_output.push_back(3);
    valid_output.push_back(4);
    valid_output.push_back(6);
    valid_output.push_back(7);
    valid_output.push_back(8);
    valid_output.push_back(9);
    valid_output.push_back(11);

    auto output = mergeTwoLists<int>(list1, list2);

    ASSERT_EQ(valid_output, output);
}

TEST(mergeTwoLists, empty_case) {
    LinkedList<int> list1;
    LinkedList<int> list2;
    LinkedList<int> valid_output;

    auto output = mergeTwoLists<int>(&list1, &list2);

    ASSERT_EQ(valid_output, output);
}