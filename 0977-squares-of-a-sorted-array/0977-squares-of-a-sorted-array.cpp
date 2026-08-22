class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int p=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                p=i;
                break;
            }
        }
        int q=p-1;
        while(q>=0&&p<nums.size()){
            if(abs(nums[q])>abs(nums[p])){
                nums[p]*=nums[p];
                p++;
            }
            else {
                nums[q]*=nums[q];
                q--;
            }
        }
        while(q>=0){
            nums[q]*=nums[q];
            q--;
        }
        while(p<nums.size()){
            nums[p]*=nums[p];
            p++;
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};