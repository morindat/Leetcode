# include <iostream>
# include <vector>
# include <stack>
using namespace std;

// Problem 6
// Sum of Min Subarray: MEDIUM
// Date: 06/1/26

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (prev->next && prev->next->next){
            // at any given moment we will have a list in this structure
            // prev->a->b->next
            // where we need to reverse a and b
            // so storing them in some var is ideal
            ListNode* a = prev->next;
            ListNode* b = a->next;

            // swapping
            // we need b->a, a->prev
            // so we can go ahead and say prev next is b, initial prev next is a
            // a next to b next
            // now we need to link and b, and since we reverse the situation then bnext to a
            prev->next = b;
            a->next = b->next;
            b->next = a;

            // advance the head/prev
            prev = a;
        }

        return dummy.next;
    }
};

// Your presence graces our humble abode. It is our honour to host your highness.