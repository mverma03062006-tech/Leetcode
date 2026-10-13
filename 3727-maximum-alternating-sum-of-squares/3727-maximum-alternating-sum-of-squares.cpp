class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        int mid=nums.size()/2;
        long long sum=0;
        for(int i=mid;i<nums.size();i++){
            sum+=nums[i];
        }
        for(int i=0;i<mid;i++){
            sum-=nums[i];
        }
        return sum;
    }
};