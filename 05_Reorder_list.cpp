// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

// Example 1:


// Input: head = [1,2,3,4]
// Output: [1,4,2,3]
// Example 2:


// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]
 









// Optimal solution using stack


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* curr=head;
        stack<ListNode*> st;
        int len=0;
        while(curr){
            st.push(curr);
            curr=curr->next;
            len++;
        }
        curr=head;
        for(int i=0;i<len/2;i++){
            ListNode* topNode=st.top();
            st.pop();
            topNode->next=curr->next;
            curr->next=topNode;
            curr=topNode->next;
        }
        if (curr) curr->next = nullptr;

    }
};