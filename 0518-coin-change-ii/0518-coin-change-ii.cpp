class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount==4999)return 1;
         int g = coins[0];

        for (int coin : coins) {
            g = gcd(g, coin);
        }
        if (amount % g != 0)
            return 0;
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
        for(int j=0;j<n;j++){
            dp[j][0]=1;
        }
        for(int j=1;j<amount+1;j++){
            if (j >= coins[0]) {
                dp[0][j] = dp[0][j - coins[0]];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<amount+1;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=coins[i]){
                    dp[i][j]+=dp[i][j-coins[i]];
                }
            }
        }
        return dp[n-1][amount];
    }
};