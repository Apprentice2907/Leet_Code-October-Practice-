// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

// Example 1:


// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [0]
// Output: [0]







// Using stack structure 

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            if (curr->right) st.push(curr->right);
            if (curr->left) st.push(curr->left);
            if (!st.empty()) curr->right = st.top();
            curr->left = nullptr;
        }
    }
};





// Optimal solution 

class Solution {
public:
    TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};


