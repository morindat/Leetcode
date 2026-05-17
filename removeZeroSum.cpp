#include <unordered_map>
using namespace std;

// Problem 14
// Remove Zero Sum Consecutive Nodes: MEDIUM 
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // Dummy node to handle head removal cleanly
        ListNode dummy(0);
        dummy.next = head;

        unordered_map<int, ListNode*> prefixMap;
        int prefixSum = 0;

        // First pass: record LAST occurrence of each prefix sum
        for (ListNode* curr = &dummy; curr; curr = curr->next) {
            prefixSum += curr->val;
            prefixMap[prefixSum] = curr;
        }

        // Second pass: skip zero-sum sublists
        prefixSum = 0;
        for (ListNode* curr = &dummy; curr; curr = curr->next) {
            prefixSum += curr->val;
            curr->next = prefixMap[prefixSum]->next;
        }

        return dummy.next;
    }
};
