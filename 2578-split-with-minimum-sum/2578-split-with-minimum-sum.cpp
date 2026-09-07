class Solution {
public:
    int splitNum(int num) {
        vector<int>digits;
        while(num>0){
            digits.push_back(num%10);
            num/=10;
        }
        sort(digits.begin(),digits.end());
        int nums1=0,nums2=0;
        for(int i=0;i<digits.size();i++){
            if(i%2==0)nums1=nums1*10+digits[i];
            else nums2=nums2*10+digits[i];
        }
        return nums1+nums2;
    }
};