class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=1000001;
        int l=0,r=0;
        int sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(target<=sum){
                ans=min(ans,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return ans==1000001?0:ans;
    }
};