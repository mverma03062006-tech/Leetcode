class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int, int> find;
        int sum = 0;
        bool flag = false;
        for (int i = 0; i < nums.size(); i++) {

            find[nums[i]]++;

            if (!flag) {
                sum += nums[i];

                if (i + 1 < nums.size() &&nums[i] + 1 != nums[i + 1]) {
                    flag = true;
                }
            }
        }

        int ans = sum;

        while (find.find(ans) != find.end()) {
            ans++;
        }

        return ans;
    }
};