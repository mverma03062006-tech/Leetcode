class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans=-1;
        for(auto it:nums){
            mp[it]++;
        }
        if(k==nums.size()){
            return *max_element(nums.begin(),nums.end());
        }
        if(k==1){
            for(auto [x,frew]:mp){
                if(frew==1){
                    ans=max(ans,x);
                }
            }
        }
            if (mp[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if (mp[nums[nums.size()- 1]] == 1) {
            ans = max(ans, nums[nums.size()- 1]);
        }
        return ans;
    }
};