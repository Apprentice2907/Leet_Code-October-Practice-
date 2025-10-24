// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself. 

// Example 1:

// Input: l1 = [7,2,4,3], l2 = [5,6,4]
// Output: [7,8,0,7]
// Example 2:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [8,0,7]
// Example 3:

// Input: l1 = [0], l2 = [0]
// Output: [0]









// My logic using stack and 33% runtime

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* head = nullptr;
        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            carry = sum / 10;
            sum = sum % 10;
            ListNode* newNode = new ListNode(sum);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};









// Optimal solution leetcode but without stack

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
ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // store next node
        curr->next = prev;   // reverse the link
        prev = curr;         // move prev one step ahead
        curr = next;         // move curr one step ahead
    }

    return prev;  // prev will be new head
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       //step 1
ListNode* c1=reverse(l1);
ListNode* c2=reverse(l2);
//step2
ListNode* head=new ListNode(-1);
int carry=0;
ListNode* itr=head;
//step 3:calculation
while(c1!=NULL || c2!=NULL || carry!=0)
{
int sum=carry+(c1!=NULL?c1->val:0)+(c2!=NULL?c2->val:0);
int ld=sum%10;
carry=sum/10;
itr->next=new ListNode (ld);
itr=itr->next;
if(c1!=NULL)c1=c1->next;
if(c2!=NULL)c2=c2->next;
}
return reverse(head->next); 
    }
};