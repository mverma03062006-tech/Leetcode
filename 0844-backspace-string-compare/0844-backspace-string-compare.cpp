class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(!st1.empty())st1.pop();
            }
            else st1.push(s[i]);
        }
         stack<char>st2;
        for(int i=0;i<t.length();i++){
            if(t[i]=='#'){
                if(!st2.empty())st2.pop();
            }
            else st2.push(t[i]);
        }
        string s1="",t1="";
        while(!st1.empty()&&!st2.empty()){
            s1+=st1.top();
            t1+=st2.top();
            st1.pop();
            st2.pop();
        }
        if(!st1.empty()||!st2.empty())return false;
        return s1==t1;
    }
};