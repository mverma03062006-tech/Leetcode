class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int >st;
        st.push(0);

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(0);
            }
            else {
                int val=st.top();
                st.pop();
                int x;

                if(val==0)x=1;
                else x=2*val;
                st.top()+=x;
            }
        }
        return st.top();
    }
};