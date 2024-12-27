class Solution {
public:
    // Memoization array to store results for each state
    vector<string> dp[9][9];

    vector<string> solve(int numOpen, int numClose) {
        // If the result is already computed, return it
        if (!dp[numOpen][numClose].empty()) {
            return dp[numOpen][numClose];
        }

        vector<string> ans;

        // Base case: no parentheses left to add
        if (numOpen == 0 && numClose == 0) {
            ans.push_back("");
            return ans;
        }

        // Add an open parenthesis if possible
        if (numOpen > 0) {
            vector<string> openResults = solve(numOpen - 1, numClose);
            for (const string& s : openResults) {
                ans.push_back("(" + s);
            }
        }

        // Add a close parenthesis if valid (more closeCount than openCount)
        if (numClose > numOpen) {
            vector<string> closeResults = solve(numOpen, numClose - 1);
            for (const string& s : closeResults) {
                ans.push_back(")" + s);
            }
        }

        // Store the result in memoization array
        dp[numOpen][numClose] = ans;
        return ans;
    }

    vector<string> generateParenthesis(int n) {
        return solve(n, n);
    }
};
