class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int size = nums.size();
        int i = 1;
        int j = 0; //position of unique element;
        while(i < size)
        {
            if(nums[i] == nums[j])
            {
                i++;
            }
            else
            {
                j++;
                nums[j] = nums[i];
                i++;
            }
        }
        int k = j + 1;
        return k;
    }
};