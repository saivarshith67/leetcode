class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.size() == 0 && target == 0)
        {
            //empty subset with target = 0 => 1 way
            return 1;
        }

        if(nums.size() == 0 && target != 0)
        {
            return 0;
        }


        //using '-' sign => add that element to target
        //using '+' sign => subtract that element from target

        //2 choices 
        // either using + or - sign
        int lastElement = nums.back();

        //use + sign
        nums.pop_back();
        int choice1 = findTargetSumWays(nums, target-lastElement);
        int choice2 = findTargetSumWays(nums, target+lastElement);
        nums.push_back(lastElement);
        int ans = choice1 + choice2;
        return ans;

        
    }
};