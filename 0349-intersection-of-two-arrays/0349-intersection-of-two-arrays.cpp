class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>n1,n2;
        for(int i=0;i<nums1.size();i++){
            if(!n1.count(nums1[i]))n1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            if(!n2.count(nums2[i]))n2.insert(nums2[i]);
        }
        vector<int>ans;
        for(int it:n1){
            if(n2.count(it))ans.push_back(it);
        }
        return ans;
    }
};