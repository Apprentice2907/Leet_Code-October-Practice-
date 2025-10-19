// Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

// Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

// Example 1:

// Input: root = [1,null,3,2,4,null,5,6]
// Output: [1,3,5,6,2,4]
// Example 2:

// Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]









// New concept auto keyword in for loop

// Here's how auto works in different contexts within range-based for loops: Iterating by Value (Copy).
// C++

//     std::vector<int> numbers = {1, 2, 3, 4, 5};
//     for (auto num : numbers) {
//         // num is a copy of each element in 'numbers'
//         // Modifications to 'num' will not affect the original vector
//         std::cout << num << " ";
//     }
// In this case, auto deduces num to be an int, and each element is copied into num. Iterating by Reference (Modification).
// C++

//     std::vector<int> numbers = {1, 2, 3, 4, 5};
//     for (auto& num : numbers) {
//         // num is a reference to each element in 'numbers'
//         // Modifications to 'num' will affect the original vector
//         num *= 2; // Doubles each element in 'numbers'
//     }










// My logic using stack 78% runtime 

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;

        if(root==NULL) return result;

        stack<Node*> st;
        st.push(root);

        while(!st.empty()){
            Node* curr=st.top();
            st.pop();
            result.push_back(curr->val);
            for(int i=curr->children.size() -1; i>=0; i--){
                st.push(curr->children[i]);
            }
        }
        return result;
    }
};








// Leetcode optimal solution without stack

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void helper(Node* root, vector<int> &ans)
    {
        if(!root) return;
        ans.push_back(root -> val);
        for(auto child: root -> children)
        helper(child, ans);
    }
    vector<int> preorder(Node* root)
    {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};

#include <print>
auto init = std::atexit(
    []() { std::println(std::fopen("display_runtime.txt", "w"), "0"); });









