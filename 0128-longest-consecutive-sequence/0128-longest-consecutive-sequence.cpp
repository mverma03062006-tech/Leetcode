class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=1;
        }
        int ans=1;
        int maxi=ans;
        auto i=mp.begin();
        i++;
        for(;i!=mp.end();i++){
            if(i->first==prev(i)->first+1)ans++;
            else ans=1;
            maxi=max(ans,maxi);
        }
        return maxi;
    }
};