class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int>mp;
        int sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                mp[grid[i][j]]++;
                sum+=grid[i][j];
            }
        }
        vector<int>ans;
        for(auto it: mp){
            if(it.second==2)ans.push_back(it.first);
        }
        int val=grid.size()*grid.size();
        int total=(val*(val+1))/2;
        int missing=total-(sum-ans[0]);
        ans.push_back(missing);
        return ans;
    }
};