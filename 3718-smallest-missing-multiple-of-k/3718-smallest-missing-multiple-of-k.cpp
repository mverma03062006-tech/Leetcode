class Solution {
public:
    bool find(vector<int>& nums,int ans){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ans)return  true;
        }
        return false;
    }
    int missingMultiple(vector<int>& nums, int k) {
        int ans=k;
        for(int i=2;i<=101;i++){
            if(!find(nums,ans))return ans;
            ans=k*i;
        }
        return ans;
    }
};