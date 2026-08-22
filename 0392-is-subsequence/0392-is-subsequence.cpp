class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(j<t.length()&&i<s.length()){
            if(s[i]==t[j]){
                i++,j++;
            }
            else {
                while(j<t.length()&&s[i]!=t[j]){
                    j++;
                }
            }
        }
        if(i!=s.length())return false;
        return true;
    }
};