class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0,sum=0;
        unordered_map<int,int>mp;
        int r=0,l=0;
        while(r<nums.size()){
            mp[nums[r]]++;
            sum+=nums[r];
             while (mp[nums[r]] > 1) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                sum -= nums[l];
                l++;
            }

            if (mp.size() == k) {
                ans = max(ans, sum);

                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return ans;
    }
};