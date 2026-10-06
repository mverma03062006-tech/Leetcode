class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        int ans=0;
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(1);
                cnt++;
            }
            else if(st.empty()&&s[i]==')'){
                ans++;
            }
            else {
                st.pop();
                cnt--;
            }
        }
        return ans+cnt;
    }

};