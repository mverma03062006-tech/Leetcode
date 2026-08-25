class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int l=0,r=0;
        int pro=1;
        while(r<nums.size()){
            pro*=nums[r];
            while(l<=r&&pro>=k){
                pro/=nums[l];
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
};