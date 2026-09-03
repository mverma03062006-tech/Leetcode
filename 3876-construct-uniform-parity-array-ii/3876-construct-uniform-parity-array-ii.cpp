class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int cntodd=0,mini=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==1)cntodd++;
            mini=min(mini,nums1[i]);
        }
        return mini%2==1||cntodd==0;
    }
};