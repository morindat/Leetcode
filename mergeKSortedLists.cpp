# include <vector>
# include <queue>
using namespace std;

// Problem 30
// Merge K sorted Lists: HARD
// 30/01/26

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (ListNode* head : lists) {
            ListNode* cur = head;
            while (cur != nullptr) {
                pq.push(cur->val);
                cur = cur->next;
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            int val = pq.top(); pq.pop();
            tail->next = new ListNode(val);
            tail = tail->next;
        }

        return dummy.next;
    }
};