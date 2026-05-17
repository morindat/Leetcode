# include <iostream>
# include <vector>
using namespace std;

// Problem 7
// Linked List Cycle 2: MEDIUM
// Date: 07/1/26

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {};
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        if (!fast || !fast->next) return nullptr;

        ListNode* ptr = head;

        while (ptr != slow){
            ptr = ptr->next;
            slow = slow->next;
        }

        return ptr;
    }
};