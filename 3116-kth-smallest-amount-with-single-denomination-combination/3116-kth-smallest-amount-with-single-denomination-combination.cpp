class Solution {
public:
    long long lcm(long long a, long long b) {
    return (a / __gcd(a, b)) * b;
}
    long long count(vector<int>& coins,long long x){
        long long ans=0;
        int n=coins.size();
        for(int mask=1;mask<(1<<n);mask++){
            long long l=1;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    l=lcm(l,coins[i]);
                    cnt++;
                }
            }
            if(l>x)continue;
            if(cnt%2)ans+=x/l;
            else ans-=x/l;
        }
        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low=1;
        long long high=1LL*(*min_element(coins.begin(),coins.end()))*k;
        while(high>low){
            long long mid=low+(high-low)/2;
            if(count(coins,mid)>=k)high=mid;
            else low=mid+1;
        }
    return low;
    }
};