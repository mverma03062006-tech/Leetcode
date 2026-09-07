class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.length();
        int ans=0;
        int mod=1e9+7;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(s[i]!=s[j]){
                    dp[i]=(dp[i]+dp[j])%mod;
                }
            }
            ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};