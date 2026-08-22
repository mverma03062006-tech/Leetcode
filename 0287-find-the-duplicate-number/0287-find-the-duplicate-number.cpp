class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans;
        vector<int> arr(n,0);
        
        for(int i=0;i<n;i++){
            int p=nums[i];
            arr[p]++;
        }
        for(int i=0;i<n;i++){
            if(arr[i]>1){
                ans = i;
            }
        }
        return ans;
    }
};