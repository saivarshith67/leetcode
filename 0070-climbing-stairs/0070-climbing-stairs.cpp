class Solution {
public:
    int dp[46];
    Solution() {
        memset(dp, -1 , sizeof(dp));
    }

    int climbStairs(int n) {
        // if(n == 0)
        // {
        //     return 1; 
        //     /*
        //         1 return karne ka matlab y h ki tum n = 0 se n = 0 tak pahunchne ke
        //         kitne tarike h. Yani tum wahi step par khudke wahi pahunchgaya.
        //         agar hum 0 ko return krte h, iska matlab y h ki n = 0 s n = 0 tk pahunchne
        //         ka koi tarika nhi h.
        //         isliye hum 1 return kar rahe h.
        //     */
        // }
        // f(n) = no. ways to reach nth stairs
        if(n == 1)
        {
            return 1;
        }
        else if(n == 2)
        {
            return 2;
        }
        if (dp[n] !=  -1)
        {
            return dp[n];
        }

        else
        {
            dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
            return dp[n];
        }


        // int ans = climbStairs(n - 1) + climbStairs(n - 2);
        // return ans;
    }
};