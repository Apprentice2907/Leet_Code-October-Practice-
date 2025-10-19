// Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

// Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

// Example 1:

// Input: root = [1,null,3,2,4,null,5,6]
// Output: [5,6,3,2,4,1]
// Example 2:

// Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]







// My logic using stack and help from GFG 68% runtime

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

class Pair 
{
    public:
    Node* node;
    int childrenIndex;
    Pair(Node* _node, int _childrenIndex)
    {
        node = _node;
        childrenIndex = _childrenIndex;
    }
};



class Solution {

private: 
    int currRootIdx =0;
    stack<Pair*> st;
    vector<int> post_order;
public:
    vector<int> postorder(Node* root) {
        while(root!=NULL || st.size()>0){
            if(root!=NULL){
                st.push(new Pair(root,currRootIdx));
                currRootIdx=0;

                if(root->children.size()>=1){
                    root=root->children[0];
                }
                else{
                    root=NULL;
                }
                continue;
            }
            Pair* curr=st.top();
            st.pop();
            post_order.push_back(curr->node->val);

            while(st.size()>0 && curr->childrenIndex ==st.top()->node->children.size()-1 ){
                curr=st.top();
                st.pop();
                post_order.push_back(curr->node->val);
            }
            if(st.size()>0){
                root=st.top()->node->children[curr->childrenIndex+1];
                currRootIdx=curr->childrenIndex+1;
            }
        }
        return post_order;
    }
};












// Leetcode optimal solution crazy stuff 🚬

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
static const bool __boost = []() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	return std::ios_base::sync_with_stdio(false);
	}();
const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;
void* operator new(size_t size) {
	constexpr std::size_t alignment = alignof(std::max_align_t);
	size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
	size_t total_size = size + padding;
	char* aligned_ptr = &buffer[buffer_pos + padding];
	buffer_pos += total_size;
	return aligned_ptr;
}
void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}

const auto __ = []() {
    struct Leetcode {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&Leetcode::_);
    return 0;
}();
class Solution {
public:
vector<int> res;
    vector<int> postorder(Node* root) {
        if(root) 
        {
            for(auto c: root->children)
            postorder(c);
            res.push_back(root->val);
        }
        return res;
    }
};










// Near optimal solution but logical and easy to understand 

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
    vector<int> postorder(Node* root) {
        vector<int> res;
        trav(root, res);
        return res;
    }

    void trav(Node* root, vector<int>& res){
        if(root){
            for(auto& child:root->children){
                trav(child, res);
            }
            res.push_back(root->val);
        }
    }
};