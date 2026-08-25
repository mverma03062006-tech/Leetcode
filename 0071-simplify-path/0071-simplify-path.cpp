class Solution {
public:
    string simplifyPath(string path) {
        string ans="";
        stack<string>st;
        string news="";
        for(int i=0;i<path.length();i++){
           if(path[i]=='/'&&i+1<path.length()&&path[i+1]=='/'){
            continue;
           }
            news+=path[i];
        }
        path=news;
        vector<string>s;
        string cur="/";
        for(int i=1;i<path.length();i++){
            cur+=path[i];
            if(path[i]=='/'){
                cur.pop_back();
                s.push_back(cur);
                cur="/";
            }
        }
         if(cur != "/")
            s.push_back(cur);
       for(int i=0;i<s.size();i++){

        if(s[i] == "/" || s[i] == "/.")
                continue;

            else if(s[i] == "/..") {
                if(!st.empty())
                    st.pop();
            }

            else {
                st.push(s[i]);
            }
       }
       while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        if(ans == "")
            return "/";
       return ans;
    }
};