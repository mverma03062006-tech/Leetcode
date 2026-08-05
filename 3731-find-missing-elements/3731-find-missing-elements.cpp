class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            int c=1;
            while(nums[i]>nums[i-1]+c){
                ans.push_back(nums[i-1]+c);
                c++;
            }
        }
        return ans;
    }
};