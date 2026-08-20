class Solution {
public:
    int longestPalindrome(string s) {
        bool odd=false;
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int ans=0;
        for(auto it:mp){
            if(it.second%2==0)ans+=it.second;
            else {
                ans+=it.second-1;
                odd=true;
            }
        }
        return odd?ans+1:ans;
    }
};