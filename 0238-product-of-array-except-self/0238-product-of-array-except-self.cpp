class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int count0=0;
        int id=-1;
        long long prod=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count0++;
                id=i;
            }
            else prod*=nums[i];
        }
        if(count0>1)return ans;
        else if(count0==1){
            ans[id]=prod;
        }
        else {
            for(int i=0;i<nums.size();i++){
                ans[i]=prod/nums[i];
            }
        }
        return ans;
    }
};