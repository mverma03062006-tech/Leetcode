class Solution {
public:
    bool isValid(string s) {
      int n=s.length();
      int j=n;
      char si='(',sic=')',c='{',cci='}',sq='[',sqc=']';
      stack<char> st;
      int i=0;
      while(j>0){
           if(s[i]==si){
            i++;
            st.push(si);
           }
           if(s[i]==c){
            i++;
            st.push(c);
           }
           if(s[i]==sq){
            i++;
            st.push(sq);
           }
           if(s[i]==sic){
            if(st.empty()){
                return false;
            }
            else if(st.top()==si){
                st.pop();
            }
            else if(st.top()==c||st.top()==sq){
                return false;
            }
            i++;
           }

           if(s[i]==cci){
            if(st.empty()){
                return false;
            }
            else if(st.top()==c){
                st.pop();
            }
            else if(st.top()==si||st.top()==sq){
                return false;
            }
            i++;
           }

           if(s[i]==sqc){
            if(st.empty()){
                return false;
            }
            else if(st.top()==sq){
                st.pop();
            }
            else if(st.top()==c||st.top()==si){
                return false;
            }
            i++;
           }
            j--;

      }
      if(st.empty()){
        return true;
      }
        else return false;
      
    }
};