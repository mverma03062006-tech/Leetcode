class Solution {
public:
    bool ispalindrome(string s){
        string s2=s;
        reverse(s2.begin(),s2.end());
        return s2==s;
    }
    void recur(string s,vector<vector<string>>& ans,vector<string>& temp){
        if(s.size()==0){
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<s.size();i++){
            string part=s.substr(0,i+1);
            if(ispalindrome(part)){
                temp.push_back(part);
                recur(s.substr(i+1),ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string >>ans;
        vector<string>temp;
        recur(s,ans,temp);
        return ans;
         
    }
};