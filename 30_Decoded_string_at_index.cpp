// You are given an encoded string s. To decode the string to a tape, the encoded string is read one character at a time and the following steps are taken:

// If the character read is a letter, that letter is written onto the tape.
// If the character read is a digit d, the entire current tape is repeatedly written d - 1 more times in total.
// Given an integer k, return the kth letter (1-indexed) in the decoded string.

// Example 1:

// Input: s = "leet2code3", k = 10
// Output: "o"
// Explanation: The decoded string is "leetleetcodeleetleetcodeleetleetcode".
// The 10th letter in the string is "o".
// Example 2:

// Input: s = "ha22", k = 5
// Output: "h"
// Explanation: The decoded string is "hahahaha".
// The 5th letter is "h".
// Example 3:

// Input: s = "a2345678999999999999999", k = 1
// Output: "a"
// Explanation: The decoded string is "a" repeated 8301530446056247680 times.
// The 1st letter is "a".






// My logic using stack and also help from leetcode solution 
// Optimal solution

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        stack<long long> chrlen;
        chrlen.push(0);
        for(size_t i=0;i<s.length();i++){
            if(isdigit(s[i])){
                long long length=chrlen.top()*(s[i]-'0');
                chrlen.push(length);
            } else{
                long long length =chrlen.top()+1;
                chrlen.push(length);
            }
        }
        size_t ln=chrlen.size();
        while(!chrlen.empty()){
            k %=chrlen.top();
            ln--;
            if(k==0 && isalpha(s[ln-1])){
                return string(1,s[ln-1]);
            }
            chrlen.pop();
        }
        return "";
    }
};