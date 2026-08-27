class Solution {
public:
    bool check(int k,vector<vector<int>>& dp,int r,int c, int m ,int n){
        if(k+r>m)return false;
        if(c+k>n)return false;
        for(int i=r;i<k+r;i++){
            for(int j=c;j<k+c;j++){
                if(dp[i][j]==0)return false;
            }
        }
        return true;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=matrix[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==1){
                    int k=2;
                    while(true){
                        if(check(k,dp,i,j,m,n)){
                            dp[i][j]++;
                            k++;
                        }
                        else break;
                    }
                }
            }
        }
    int ans=0;
     for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};