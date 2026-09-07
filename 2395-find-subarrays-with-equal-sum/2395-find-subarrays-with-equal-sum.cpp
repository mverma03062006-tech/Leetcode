class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        vector<int>sum(nums.size()-1,0);
        for(int i=0;i<nums.size()-1;i++){
            sum[i]=nums[i]+nums[i+1];
        }
        sort(sum.begin(),sum.end());
        for(int i=0;i<nums.size()-2;i++){
            if(sum[i]==sum[i+1])return true;
        }
        return false;
    }
};