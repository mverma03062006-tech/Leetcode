class Solution {
public:
bool check(unordered_map<char,int>& mp){
    for(int i=0;i<mp.size();i++){
        if(mp[i]>2)return false;
    }
    return true;
}
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int ans=0;
        int l=0,r=0;
        while(r<s.length()){
            mp[s[r]]++;
            while(!check(mp)){
                mp[s[l]]--;
                l++;
            }
            r++;
            ans=max(ans,r-l);
        }
        return ans;
    }
};