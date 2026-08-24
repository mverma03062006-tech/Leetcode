class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>prefix(nums.size(),0);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        unordered_map<int,int>rem;
        for(int i=0;i<prefix.size();i++){
             int r = ((prefix[i] % k) + k) % k;
            rem[r]++;
        }
        int ans=0;
        for(auto it:rem){
            if(it.first==0)ans+=it.second;
            int n=it.second;
            ans+=n*(n-1)/2;
        }
        return ans;
    }
};