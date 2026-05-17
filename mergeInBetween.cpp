#include <iostream>
using namespace std;

// Problem 12
// Merge In Between Linked List: MEDIUM (EASY according to me)
// Date: 15/01/26

// Struct definition of linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // Step 1: find node just before index a
        ListNode* prevA = list1;
        for (int i = 1; i < a; i++) {
            prevA = prevA->next;
        }

        // Step 2: find node just after index b
        ListNode* afterB = list1;
        for (int i = 0; i <= b; i++) {
            afterB = afterB->next;
        }

        // Step 3: connect prevA to list2
        prevA->next = list2;

        // Step 4: find tail of list2
        ListNode* tail2 = list2;
        while (tail2->next) {
            tail2 = tail2->next;
        }

        // Step 5: connect tail of list2 to afterB
        tail2->next = afterB;

        return list1;
    }
};
