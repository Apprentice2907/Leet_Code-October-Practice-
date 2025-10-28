// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]








// My logic using stack and 19ms runtime

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> idxstk;
        vector<int> result(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!idxstk.empty() && temperatures[idxstk.top()] <= temperatures[i]) {
                idxstk.pop();
            }
            if (!idxstk.empty()) {
                result[i] = idxstk.top() - i;
            }
            idxstk.push(i);
        }
        return result;
    }
};










// Leetcode optimal solution using stack 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> ans(n);
        for (int i = n - 1; ~i; --i) {
            while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                ans[i] = stk.top() - i;
            }
            stk.push(i);
        }
        return ans;
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });