class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int l=0,h=numbers.size()-1;
        while(l<h){
            if(numbers[h]+numbers[l]==target){
                ans={l+1,h+1};
                return ans;
            }
            else if(numbers[l]+numbers[h]<target){
                l++;
            }
            else h--;
        }
        return ans;
    }
};