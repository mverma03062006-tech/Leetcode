class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0,count=0;
        int ans=0;
                while(r<nums.size()){
            if(nums[r]==0)count++;
            if(count==2){
                while(nums[l]!=0){
                    l++;
                }
                l++;
                count=1;
            }
            ans=max(ans,r-l);
            r++;
        }
        return ans;
    }
};