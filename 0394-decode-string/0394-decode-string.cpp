class Solution {
public:
    string decodeString(string s) {
     stack<int>nums;
     stack<string>st;
     string ans="";
     int num=0;
     string s2="";
     for(int i=0;i<s.length();i++){
        if(isdigit(s[i])){
            num=num*10+s[i]-'0';
        }
        else if(s[i]=='['){
            nums.push(num);
            st.push(s2);
            s2="";
            num=0;
        }
        else if(s[i]==']'){
            int t=nums.top();
            nums.pop();
            string prev=st.top();
            st.pop();
            string temp="";
            while(t--){
                temp+=s2;
            }
            s2=prev+temp;
        }
        else{
            s2+=s[i];
        }
     }   
     return s2;
    }
};