class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            long long count=0;
            int k=i;
            while(k<nums.size()&&nums[k]==0){
                count++;
                k++;
            }
            ans+=(count*(count+1))/2;
            if(count>0)i+=count-1;
        }
        return ans;
    }
};