# include <stack>

// Problem 19
// Add Numbers II: MEDIUM
// Date: 18/01/26

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> st1, st2;

        while (l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* head = nullptr;

        while (!st1.empty() || !st2.empty() || carry) {
            int x = 0, y = 0;

            if (!st1.empty()) {
                x = st1.top();
                st1.pop();
            }
            if (!st2.empty()) {
                y = st2.top();
                st2.pop();
            }

            int sum = x + y + carry;
            carry = sum / 10;

            ListNode* node = new ListNode(sum % 10);
            node->next = head;
            head = node;
        }

        return head;
    }
};
