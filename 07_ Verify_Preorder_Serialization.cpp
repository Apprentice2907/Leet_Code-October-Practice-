// One way to serialize a binary tree is to use preorder traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as '#'.

// For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a null node.

// Given a string of comma-separated values preorder, return true if it is a correct preorder traversal serialization of a binary tree.

// It is guaranteed that each comma-separated value in the string must be either an integer or a character '#' representing null pointer.

// You may assume that the input format is always valid.

// For example, it could never contain two consecutive commas, such as "1,,3".
// Note: You are not allowed to reconstruct the tree.

// Example 1:

// Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
// Output: true
// Example 2:

// Input: preorder = "1,#"
// Output: false
// Example 3:

// Input: preorder = "9,#,#,1"
// Output: false










// Using stack approach

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> nodes;
        stringstream ss(preorder);
        string node;
        while (getline(ss, node, ',')) nodes.push_back(node);

        stack<string> st;
        for (string& n : nodes) {
            st.push(n);
            while (st.size() >= 3) {
                string top1 = st.top(); st.pop();
                string top2 = st.top(); st.pop();
                string top3 = st.top();
                if (top1 == "#" && top2 == "#" && top3 != "#") {
                    st.pop();
                    st.push("#");
                } else {
                    st.push(top2);
                    st.push(top1);
                    break;
                }
            }
        }
        return st.size() == 1 && st.top() == "#";
    }
};










// Optimal solution

class Solution {
public:
 bool isValidSerialization(string preorder) {
       int n=preorder.size();
       int slot=1;
       for(int i=0;i<n;i++){
        if(preorder[i]==',')continue;
        int j=i;
        while(j<n && preorder[j]!=',')j++;
        string token=preorder.substr(i,j-i);
        i=j;
        slot--;
        if(slot<0)return false;
        if(token!="#")slot=slot+2;
       }
       return slot==0;
    }
};