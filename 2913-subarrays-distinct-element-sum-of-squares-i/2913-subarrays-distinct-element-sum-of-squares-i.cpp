class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int>map;
            for(int j=i;j<nums.size();j++){
                map[nums[j]]++;
                int val=map.size()*map.size();
                   ans+=val;
            }
            
            map.clear();
         
        }
        return ans;
    }
};