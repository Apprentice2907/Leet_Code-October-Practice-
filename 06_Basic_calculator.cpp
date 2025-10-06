// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

// Example 1:

// Input: s = "1 + 1"
// Output: 2
// Example 2:

// Input: s = " 2-1 + 2 "
// Output: 3
// Example 3:

// Input: s = "(1+(4+5+2)-3)+(6+8)"
// Output: 23







// Using stack approach and also optimal solution

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result=0;
        int num=0;
        int sign=1;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(isdigit(c)){
                num=num*10+(c-'0');
            }
            else if (c=='+'){
                result+=sign*num;
                num=0;
                sign=1;
            }
            else if (c=='-'){
                result+=sign*num;
                num=0;
                sign=-1;
            }
            else if(c=='('){
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
            }
            else if(c==')'){
                result += sign * num;
                num = 0;
                result *= st.top(); 
                st.pop();
                result += st.top(); 
                st.pop();

            }
        }
        result+=sign*num;
        return result;
    }
};







