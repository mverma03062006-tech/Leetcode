class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // {start, end, weight, original index}
        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by ending time
        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x[1] != y[1])
                return x[1] < y[1];

            return x[0] < y[0];
        });

        vector<int> ending(n);

        for (int i = 0; i < n; i++)
            ending[i] = a[i][1];

        // Previous compatible interval
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {

            int pos = lower_bound(
                ending.begin(),
                ending.begin() + i,
                a[i][0]
            ) - ending.begin();

            prev[i] = pos;
        }

        // dp[k][i] = {maximum weight, indices}
        vector<vector<pair<long long, vector<int>>>> dp(
            5,
            vector<pair<long long, vector<int>>>(n + 1)
        );

        for (int k = 1; k <= 4; k++) {

            for (int i = 1; i <= n; i++) {

                // Option 1: Don't take current interval
                auto notTake = dp[k][i - 1];

                // Option 2: Take current interval
                auto take = dp[k - 1][prev[i - 1]];

                take.first += a[i - 1][2];

                take.second.push_back(a[i - 1][3]);

                // Sort indices because we compare lexicographically
                sort(take.second.begin(), take.second.end());

                // Choose better option
                if (take.first > notTake.first) {
                    dp[k][i] = take;
                }
                else if (take.first < notTake.first) {
                    dp[k][i] = notTake;
                }
                else {
                    // Same weight → lexicographically smaller
                    if (take.second < notTake.second)
                        dp[k][i] = take;
                    else
                        dp[k][i] = notTake;
                }
            }
        }

        return dp[4][n].second;
    }
};