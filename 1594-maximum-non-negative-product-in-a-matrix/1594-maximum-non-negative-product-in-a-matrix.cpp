class Solution {
public:
    const long long MOD = 1e9+7;

    pair<long long,long long> helper(vector<vector<int>>& grid,
                                    vector<vector<pair<long long,long long>>>& dp,
                                    int i, int j, int m, int n) {
        
        // base case
        if(i == m-1 && j == n-1) {
            return {grid[i][j], grid[i][j]};
        }

        if(dp[i][j].first != LLONG_MIN) return dp[i][j];

        long long curr = grid[i][j];

        long long maxVal = LLONG_MIN;
        long long minVal = LLONG_MAX;

        // move right
        if(j + 1 < n) {
            auto [maxR, minR] = helper(grid, dp, i, j+1, m, n);

            long long a = curr * maxR;
            long long b = curr * minR;

            maxVal = max(maxVal, max(a,b));
            minVal = min(minVal, min(a,b));
        }

        // move down
        if(i + 1 < m) {
            auto [maxD, minD] = helper(grid, dp, i+1, j, m, n);

            long long a = curr * maxD;
            long long b = curr * minD;

            maxVal = max(maxVal, max(a,b));
            minVal = min(minVal, min(a,b));
        }

        return dp[i][j] = {maxVal, minVal};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<pair<long long,long long>>> dp(
            m, vector<pair<long long,long long>>(n, {LLONG_MIN, LLONG_MIN})
        );

        auto [maxProd, minProd] = helper(grid, dp, 0, 0, m, n);

        if(maxProd < 0) return -1;

        return maxProd % MOD;
    }
};