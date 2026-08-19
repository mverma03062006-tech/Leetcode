class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int,vector<int>>mp;
        
        for (auto &x : reservedSeats)
            mp[x[0]].push_back(x[1]);

         int ans = (n - mp.size()) * 2;

         for (auto &[row, seats] : mp) {
            bool left = false, mid = false, right = false;

            for (int seat : seats) {
                if (seat >= 2 && seat <= 5)
                    left = true;

                if (seat >= 4 && seat <= 7)
                    mid = true;

                if (seat >= 6 && seat <= 9)
                    right = true;
            }
            if (!left && !right)
                ans += 2;
            else if (!left || !right)
                ans += 1;
            else if (!mid)
                ans += 1;
        }

    
        return ans;
    }
};