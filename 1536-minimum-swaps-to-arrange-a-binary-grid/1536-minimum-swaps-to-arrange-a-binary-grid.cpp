class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailing(n);

        // Step 1: Count trailing zeros
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) {
                cnt++;
            }
            trailing[i] = cnt;
        }

        int swaps = 0;

        // Step 2: Fix each row
        for (int i = 0; i < n; i++) {
            int required = n - i - 1;
            int j = i;

            // Find row with enough trailing zeros
            while (j < n && trailing[j] < required) {
                j++;
            }

            if (j == n) return -1;  // Not possible

            // Bubble up
            while (j > i) {
                swap(trailing[j], trailing[j - 1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};