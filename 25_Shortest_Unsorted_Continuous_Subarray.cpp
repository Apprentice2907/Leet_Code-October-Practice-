// Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.
// Return the shortest such subarray and output its length.

// Example 1:
// Input: nums = [2,6,4,8,10,9,15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

// Example 2:
// Input: nums = [1,2,3,4]
// Output: 0

// Example 3:
// Input: nums = [1]
// Output: 0







// My logic using stack but 6% runtime only

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int left = n, right = 0;

      
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                left = min(left, st.top());
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                right = max(right, st.top());
                st.pop();
            }
            st.push(i);
        }

        return (right - left > 0) ? right - left + 1 : 0;
    }
};








// Leetcode optimal solution without stack

class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    const int n = nums.size();
    int mn = INT_MAX;
    int mx = INT_MIN;
    bool meetDecrease = false;
    bool meetIncrease = false;

    for (int i = 1; i < n; ++i) {
      if (nums[i] < nums[i - 1])
        meetDecrease = true;
      if (meetDecrease)
        mn = min(mn, nums[i]);
    }

    for (int i = n - 2; i >= 0; --i) {
      if (nums[i] > nums[i + 1])
        meetIncrease = true;
      if (meetIncrease)
        mx = max(mx, nums[i]);
    }

    int l;
    for (l = 0; l < n; ++l)
      if (nums[l] > mn)
        break;

    int r;
    for (r = n - 1; r >= 0; --r)
      if (nums[r] < mx)
        break;

    return l < r ? r - l + 1 : 0;
  }
};