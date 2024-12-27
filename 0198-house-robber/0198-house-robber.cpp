class Solution {
public:
    int dp[102];
    Solution() {
        memset(dp, -1, sizeof(dp));
    }

    int solve(vector<int> &nums, int s, int e)
    {
        if(s > e) 
        {
            return 0;
        }
        if(dp[s] != -1)
        {
            return dp[s];
        }

        //include first element
        int option1 = nums[s] + solve(nums, s+2, e);

        //exclude first element
        int option2 = 0 + solve(nums, s+1, e);

        int finalAns = max(option1, option2);
        dp[s] = finalAns;

        return finalAns;
    }

    int rob(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int finalAns = solve(nums, s, e);

        return finalAns;
        
    }
};