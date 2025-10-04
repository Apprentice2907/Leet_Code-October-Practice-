// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Example 1:

// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1









class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n=matrix.size(),m=matrix[0].size(),ans=0;
        vector<int> h(m,0);
        for(int i=0;i<n;i++){
            stack<int> st;
            for(int j=0;j<=m;j++){
                if(j<m) h[j]=matrix[i][j]=='1' ? h[j]+1:0;
                while(!st.empty() &&(j==m|| h[st.top()]>h[j])){
                    int height=h[st.top()]; st.pop();
                    int width=st.empty() ? j:j-st.top()-1;
                    ans=max(ans,height*width);
                }
                st.push(j);
            }
        }
        return ans;
    }
};









// Optimal solution

class Solution {
public:

 int hist(vector<int>& heights) {
        int n = heights.size();
        stack<int> st; 
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
           
            int h = (i == n ? 0 : heights[i]);
            
            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                
                int width;
                if (st.empty()) {
                    width = i; 
                } else {
                    width = i - st.top() - 1; 
                }
                
                maxArea = max(maxArea, height * width);
            }
            
            st.push(i);
        }
        
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
         if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
    
        vector<int> height(n, 0);
        int maxarea = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    height[j] += 1;
                } else {
                    height[j] = 0;  
                }
            }
            maxarea = max(maxarea, hist(height));
        }
        return maxarea;
    }
};