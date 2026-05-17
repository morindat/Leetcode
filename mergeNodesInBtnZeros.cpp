#include <iostream>
using namespace std;

// Problem 13
// Merge In Between Zeroes: MEDIUM 
// Date: 15/01/26

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;   // skip first zero
        ListNode* write = head;        // reuse zero nodes
        int sum = 0;

        while (curr) {
            if (curr->val == 0) {
                write->val = sum;
                sum = 0;

                // ADVANCE write ONLY if more data exists
                if (curr->next)
                    write = write->next;
            } else {
                sum += curr->val;
            }
            curr = curr->next;
        }

        write->next = nullptr;
        return head;
    }
};
