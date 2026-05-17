
// Problem 16
// Sort List: MEDIUM
// Date: 16/01/26


struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Lmao I am just gonna merge sort them.
        if (!head || !head->next) return head;

        ListNode* left = head;
        ListNode* right = getMid(head);
        ListNode* temp = right->next;
        right->next = nullptr;
        right = temp;

        left = sortList(left);
        right = sortList(right);

        return mergeList(left, right);

    }
private:
    ListNode* getMid(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeList(ListNode* left, ListNode* right){
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (left && right){
            if (left->val < right->val){
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        tail->next = left ? left : right;
        
        return dummy.next;
    }
};

/* 
Super easy.
 classic merge sort algorithm works
 break the list into two and sort them recursively
 then merge them into one
That is it..
*/