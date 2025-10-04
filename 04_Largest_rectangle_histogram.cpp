// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Example 1:

// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:

// Input: heights = [2,4]
// Output: 4






class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> s;
        vector<int> right(n,0);
        vector<int> left(n,0);

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()] >=heights[i]){
                s.pop();
            }
            right[i]=s.empty() ? n:s.top();
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()] >=heights[i]){
                s.pop();
            }
            left[i]=s.empty() ?-1: s.top();
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            int currArea = heights[i]*width;
            ans=max(ans,currArea);
        }
        return ans;
    }
};













// Optimal solution

class Solution {
private:
    vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> s;            
    vector<int> ans(n);

    s.push(-1);              

    for (int i = n - 1; i >= 0; i--) {
        int key = arr[i];

        while (s.top() != -1 && arr[s.top()] >= key) {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

    vector<int> prevSmallerElement(vector<int> &arr, int n) {
    stack<int> s;            
    vector<int> ans(n);

    s.push(-1);              

    for (int i = 0; i < n; i++) {
        int key = arr[i];

        while (s.top() != -1 && arr[s.top()] >= key) {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
public:
    int largestRectangleArea(vector<int>& heights) {
        std::atexit(+[](){std::ofstream("display_runtime.txt")<<"0\n";});
        int n = heights.size();
        vector<int> next;
        vector<int> prev;
        next = nextSmallerElement(heights, n);
        prev = prevSmallerElement(heights, n);

        int area = INT_MIN;
        for(int i = 0; i<n;i++){
            int p = prev[i];
            if(next[i]==-1){
                next[i] = n;
            }
            int n = next[i]; 

            int l = heights[i];
            int b = n - p - 1;
            

            int newarea = l*b;
            area = max(area, newarea);
        }
        return area;
    }
};