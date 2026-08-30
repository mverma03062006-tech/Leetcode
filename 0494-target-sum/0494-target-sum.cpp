class Solution {
public:
    void recursion(vector<int>& nums,int target,int idx,int sum,int& ans){
        if(idx==nums.size()){
            if(sum==target)ans++;
            return;
        }
        recursion(nums,target,idx+1,sum+nums[idx],ans);
        recursion(nums,target,idx+1,sum-nums[idx],ans);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        recursion(nums,target,0,0,ans);
        return ans;
    }
};