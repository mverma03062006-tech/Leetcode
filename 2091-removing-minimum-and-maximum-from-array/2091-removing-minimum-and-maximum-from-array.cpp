class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=nums[0],minidx=0;
        int maxi=nums[0],maxidx=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>maxi)maxi=nums[i],maxidx=i;
            if(nums[i]<mini)mini=nums[i],minidx=i;
        }
        int right,left;
        if(maxidx>minidx)right=maxidx,left=minidx;
        else left=maxidx,right=minidx;
        int n=nums.size();
        return min(right+1,min(n-right+left+1,n-left));
    }
};