class Solution {
public:
    int helper(int amount, int n, vector<int> &coins,vector<vector<int>> &dp)
    {
        //base case
        if(n == 0)
        {
            if(amount == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        if(dp[n][amount] != -1)
        {
            return dp[n][amount];
        }



        int lastElement = coins[n - 1];

        if(lastElement <= amount)
        {
            //2 options
            //1 can take
            int choice1 = helper(amount - lastElement, n, coins, dp);
            int choice2 = helper(amount, n - 1, coins, dp);
            int ans = choice1 + choice2;
            dp[n][amount] = ans;
            return ans;
        }
        else
        {
            int ans = helper(amount, n - 1, coins, dp);
            dp[n][amount] = ans;
            return ans;
        }
    }


    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return helper(amount, n, coins, dp);
    }
};