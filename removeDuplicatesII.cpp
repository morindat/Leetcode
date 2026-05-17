// Problem 15
// Remove Duplicates II: MEDIUM 
// Date: 15/01/26

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Dummy node to handle edge cases (like head being removed)
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            // Case 1: current value has duplicates
            if (curr->next && curr->val == curr->next->val) {
                int dupVal = curr->val;

                // Skip all nodes with duplicate value
                while (curr && curr->val == dupVal) {
                    curr = curr->next;
                }

                // Connect prev to the first non-duplicate node
                prev->next = curr;
            } 
            // Case 2: current value is unique
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};
