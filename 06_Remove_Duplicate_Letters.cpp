// Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

// Example 1:

// Input: s = "bcabc"
// Output: "abc"
// Example 2:

// Input: s = "cbacdcbc"
// Output: "acdb"






// Using stack approach and also optimal solution

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0);
        vector<int> instack(26,false);
        for(char c:s) freq[c-'a']++;
        stack<char> st;
        for(char c:s){
            freq[c-'a']--;
            if(instack[c-'a']) continue;
            while(!st.empty() && st.top()>c && freq[st.top()-'a']>0){
                instack[st.top()-'a']=false;
                st.pop();
            }
            st.push(c);
            instack[c-'a']=true;
        }
        string result;
        while(!st.empty()){
            result=st.top()+result;
            st.pop();
        }
        return result;
    }
};