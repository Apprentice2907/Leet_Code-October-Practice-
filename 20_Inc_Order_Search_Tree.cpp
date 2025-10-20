// Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

// Example 1:

// Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
// Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
// Example 2:

// Input: root = [5,1,7]
// Output: [1,null,5,null,7]







// My logic using stack and also optimal solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    stack<int> stk;
    void insert(TreeNode** head,int n){
        TreeNode* temp=new TreeNode(n);
        temp->right=*head;
        *head=temp;
        
    }
    void inorder(TreeNode*root){
        if(root==NULL)
            return;
        inorder(root->left);
        
        stk.push(root->val);
        
        inorder(root->right);
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        int n=stk.top();
        stk.pop();
        TreeNode* ans=new TreeNode(n);
        while(!stk.empty()){
            insert(&ans,stk.top());
            stk.pop();
        }
        return ans;
    }
};











// Leetcode and My optimal solution using inorder traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail=NULL) {
        if (root == nullptr)
        return tail;

        TreeNode* ans = increasingBST(root->left, root);
        root->left = nullptr;
        root->right = increasingBST(root->right, tail);
        return ans;
    }
};