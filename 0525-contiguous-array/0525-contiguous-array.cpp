class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        int ans=0;
        unordered_map<int,int>seen;
        seen[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)sum++;
            else sum--;
            if(seen.count(sum))ans=max(ans,i-seen[sum]);
            else seen[sum]=i;
        }
        return ans;
    }
};