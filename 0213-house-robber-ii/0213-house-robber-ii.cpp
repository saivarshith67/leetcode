class Solution {
public:
    int dp[102][102]; // Use a 2D DP array to handle different ranges (s, e)

    Solution() {
        memset(dp, -1, sizeof(dp));
    }

    int solve(vector<int>& nums, int s, int e) {
        // Base case
        if (s > e) {
            return 0;
        }

        // Check memoization array
        if (dp[s][e] != -1) {
            return dp[s][e];
        }

        // Include starting index -> Rob the house
        int option1 = nums[s] + solve(nums, s + 2, e);

        // Exclude starting index -> Skip the house
        int option2 = solve(nums, s + 1, e);

        // Take the maximum of both options
        dp[s][e] = max(option1, option2);
        return dp[s][e];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        // Single element case
        if (n == 1) {
            return nums[0];
        }

        // Solve for two cases:
        // 1. Exclude the last house (rob houses from 0 to n-2)
        memset(dp, -1, sizeof(dp)); // Reset memoization array
        int option1 = solve(nums, 0, n - 2);

        // 2. Exclude the first house (rob houses from 1 to n-1)
        memset(dp, -1, sizeof(dp)); // Reset memoization array
        int option2 = solve(nums, 1, n - 1);

        // Return the maximum of the two cases
        return max(option1, option2);
    }
};
