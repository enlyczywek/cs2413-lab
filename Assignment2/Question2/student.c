/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int checkAVL(struct TreeNode* root, long long min_value, long long max_value) {
    int left_height = 0;
    int right_height = 0;
    int height = 0;

    if (root == NULL) return 0;

    if ((root->val <= min_value) || (root->val >= max_value)) {
        return -1;
    }

    left_height = checkAVL(root->left, min_value, (long long)root->val);
    right_height = checkAVL(root->right, (long long)root->val, max_value);

    if ((left_height < 0) || (right_height < 0)) return -1;

    if (left_height > right_height){
         height = left_height;
    }
    else {
        height = right_height;
    }


    if (abs(left_height - right_height) > 1) return -1;
    else return height + 1;
    
    (void)root;
}

bool isAVL(struct TreeNode* root) {
    // TODO: implement
    // Hint: One common O(n) approach:
    // - Use a recursive helper that returns the subtree height,
    //   and returns -1 if subtree is invalid (BST violation or unbalanced).

    return checkAVL(root, (long long)LLONG_MIN, (long long)LLONG_MAX) >= 0;
}
