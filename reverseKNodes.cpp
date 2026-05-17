// Problem 24
// Reverse Nodes in k-Group: HARD
// Date: 25/01/26
// Was in a tournament yesterday, came late and was unable to work that night

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;

        // check if the list is long enough

        for (int i = 0; i < k; i++){
            if (!current) return head;
            current = current->next;
        }

        // reverse the first k elements
        current = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        for (int i = 0; i < k; i++){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        // recurse
        head->next = reverseKGroup(current, k);

        return prev;
    }
};