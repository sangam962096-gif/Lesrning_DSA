class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.length();

        for( int i = 0  ; i < n ; i ++){
            //if it's an opening bracket, push to stack
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else {
               // If it's a closing bracket but stack is empty , its unbalanced
                if(st.empty()) return false;

                char ch =st.top();
                st.pop();

                // chech if the current closing bracket matches the top opening bracket
                if((s[i] == ')' && ch == '(') || 
                ( s[i] == ']'  && ch == '[') ||
                ( s[i] == '}' && ch == '{')) {
                continue;
                }
                else {
                return false;
                }
            }
        }
        // If stack is empty at the end all brackets were matched
        return st.empty();
    }
};