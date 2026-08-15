class Solution {
public:
    bool check(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)return false;
        }
        return true;
    }
    int longestSubsequence(vector<int>& nums) {
        int ans=nums.size();
        int x=nums[0];
        for(int i=1;i<nums.size();i++){
            x=x^nums[i];
        }
        if(check(nums)){
            return 0;
        }
        if(x==0){
            return ans-1;
        }
        else return ans;
    }
};