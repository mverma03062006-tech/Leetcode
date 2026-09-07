class Solution {
public:
    bool helper(vector<int>& nums,vector<int>& bucket,int target,int idx,int k){
        if(idx==nums.size()){
            return true;
        }
        for(int i=0;i<k;i++){
            if(bucket[i]+nums[idx]>target)continue;
            if(i>0&&bucket[i]==bucket[i-1])continue;
                bucket[i]+=nums[idx];
                if(helper(nums,bucket,target,idx+1,k))return true;
                bucket[i]-=nums[idx];
                if(bucket[i]==0)break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0)return false;
        int target=sum/k;
        for(int x:nums){
            if(x>target)return false;
        }
        sort(nums.rbegin(),nums.rend());
        vector<int>bucket(k,0);
        return  helper(nums,bucket,target,0,k);
    }
};