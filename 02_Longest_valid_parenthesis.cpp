// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

 

// Example 1:

// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
// Example 2:

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
// Example 3:

// Input: s = ""
// Output: 0





class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxLen=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            } else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                } else{
                    maxLen =max(maxLen,i-st.top());
                }
            }
        }
        return maxLen;
    }

};










// Optimal solution

class Solution {
public:
    int longestValidParentheses(string s) {
        //create an dp array
        vector<int>dp(s.length(),0);
        int maximumLength=0;
        for(int i=1; i<s.length(); i++){
            if(s[i]==')'){
                //there would be 2 cases regarding this indi.. case
                //case 1 --> s[i-1]=='('
                if(s[i-1]=='('){
                    dp[i]= (i>=2? dp[i-2]: 0)+2;
                }
                else if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='('){
                    dp[i]=dp[i-1]+2;
                    if(i-dp[i-1]-2>=0){
                        dp[i]=dp[i]+dp[i-dp[i-1]-2];
                    }
                }
                maximumLength=max(maximumLength,dp[i]);
            }
        }
        return maximumLength;
    }
};