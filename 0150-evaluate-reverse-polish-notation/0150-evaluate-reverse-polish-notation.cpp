class Solution {
public:
    int convert(string s){
        int a=0;
        if(s[0]=='-'){
            for(int i=1;i<s.length();i++){
            a*=10;
            a+=s[i]-'0';
        } 
        return -a;
        }
        for(int i=0;i<s.length();i++){
            a*=10;
            a+=s[i]-'0';
        }
        return a;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int ans=0;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(tokens[i]=="+")st.push(a+b);
                 if(tokens[i]=="-")st.push(b-a);
                  if(tokens[i]=="*")st.push(a*b);
                   if(tokens[i]=="/")st.push(b/a);
            }
            else {
                int x=convert(tokens[i]);
                st.push(x);
            }
        }
        return st.top();
    }
};