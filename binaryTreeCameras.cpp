# include <iostream>
using namespace std;

/**
 * Problem 128
 * Problem 15/45 of May 2026
 * Serialize And Deserialize Binary Tree: HARD
 * Date: 20/05/26
 * Time Complexity: O(n);
 * How I know this is hard hard, it is giving strong n-polygon Triangulation 
 * Damn, giving me flashbacks of Design and Analysis of Algorithms
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int cameras;    

    /**
     * 0 -> Not covered
     * 1 -> Covered but no camera on that node
     * 2 -> Covered and camera is actually there
     */

    int dfs(TreeNode* root) {
        if (!root) return 1;

        int left = dfs(root->left);
        int right = dfs(root->right);

        //.. if any of the children in not covered, add a camera
        if (left == 0 || right == 0) {
            cameras++;
            return 2;
        }

        //.. if any is covered, there is a camera somewhere
        if (left == 2 || right == 2) {
            return 1;
        }

        //.. otherwise return 0, both are covered
        return 0;
    }

public:
    int minCameraCover(TreeNode* root) {
        cameras = 0;

        if (dfs(root) == 0) {
            cameras++;
        }

        return cameras;
    }
};