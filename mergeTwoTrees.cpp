# include <iostream>
using namespace std;

/**
 * Problem 152
 * Problem 39/45 of May 2026
 * Merge Two Sorted Lists: EASY
 * Date: 27/05/26
 * Time Complexity: O(n);
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    // The iterative solution
    

    // The Recursive solution
    ListNode* mergeLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1->val < list2->val) {
            list1->next = mergeLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeLists(list1, list2->next);
            return list2;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        dummy.next = nullptr;
        ListNode* temp = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        if (list1) {
            temp->next = list1;
        }

        if (list2) {
            temp->next = list2;
        }

        return dummy.next;
    }
};