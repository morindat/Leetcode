# include <vector>

// Problem 20
// Split Linked List In Parts: HARD MEDIUM
// Date: 20/01/26

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    std::vector<ListNode*> splitListToParts(ListNode* head, int k) {
        std::vector<ListNode*> result(k, nullptr);

        // Step 1: get length
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }

        // Step 2: compute sizes
        int baseSize = n / k;
        int extra = n % k;

        curr = head;

        // Step 3: split
        for (int i = 0; i < k && curr; i++) {
            result[i] = curr;
            int partSize = baseSize + (i < extra ? 1 : 0);

            // move to end of this part
            for (int j = 1; j < partSize; j++) {
                curr = curr->next;
            }

            // cut
            ListNode* nextPart = curr->next;
            curr->next = nullptr;
            curr = nextPart;
        }

        return result;
    }
};
