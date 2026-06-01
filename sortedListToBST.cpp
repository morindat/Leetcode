#include <algorithm>
#include <vector>
using namespace std;

/**
 * Problem 165
 * Problem 2/45 of June 2026
 * Convert Sorted List To Binary Search Tree: MEDIUM
 * Date: 1/06/26
 * Time Complexity: O(n log n) for the find middle soln. O(n) for the other solutions
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Find Middle and Use it as root
class Solution {
private:
    ListNode* findMiddle(ListNode* head) {
        if (!head) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev) prev->next = nullptr;

        return slow; // the middle
    }

    TreeNode* buildBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);

        ListNode* mid = findMiddle(head);
        TreeNode* root = new TreeNode(mid->val);

        root->left = buildBST(head);
        root->right = buildBST(mid->next);

        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head);
    }
};

// Inorder Simulation
class Solution {
private:
    ListNode* current;

    int findLength(ListNode* head) {
        int length = 0;

        while (head) {
            length++;
            head = head->next;
        }
        
        return length;
    }

    TreeNode* buildBST(int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;

        // Build left subtree first (inorder construction)
        TreeNode* left = buildBST(start, mid - 1);
        TreeNode* root = new TreeNode(current->val);
        root->left = left;

        // Current node is the next element in list
        current = current->next;

        // Build right subtree
        root->right = buildBST(mid + 1, end);
        
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        current = head;
        int length = findLength(head);
        return buildBST(0, length - 1);
    }
};

// Naive solution (still optimal if you ask me)
// Convert List to array and then to tree

class Solution {
private:
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;

        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }

        return buildBST(nums, 0, nums.size() - 1);
    }
};