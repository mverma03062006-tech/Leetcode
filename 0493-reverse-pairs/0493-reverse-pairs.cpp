class Solution {
public:
void conquer(int left,int right,int mid,int &count,vector<int>& nums){
   int j = mid + 1;
        for(int i = left; i <= mid; i++){
            while(j <= right && (long long)nums[i] > 2LL * nums[j]) j++;
            count += (j - (mid + 1));
        }
    vector<int> temp;
    int i = left;
    j = mid + 1;

    // Merge two sorted halves
    while(i <= mid && j <= right) {
        if(nums[i] <= nums[j])
            temp.push_back(nums[i++]);
        else
            temp.push_back(nums[j++]);
    }

    // Copy remaining elements
    while(i <= mid) temp.push_back(nums[i++]);
    while(j <= right) temp.push_back(nums[j++]);

    // Copy back to original array
    for(int k = 0; k < temp.size(); k++)
        nums[left + k] = temp[k];
}
    void divide(int left,int  right,vector<int>& nums,int &count){
        if(left>=right)return ;
        int mid=left+(right-left)/2;
        divide(left,mid,nums,count);
        divide(mid+1,right,nums,count);
        conquer(left,right,mid,count,nums);
    }
    int reversePairs(vector<int>& nums) {
        int count=0;
       int  n=nums.size();
       int s=0,e=n-1;
       int mid=s+(e-s)/2;
       divide(s,e,nums,count);
        return count;
    }
};