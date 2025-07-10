class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        n = len(nums)
        output = []
        for _ in range(n):
            output.append(0)

        for i in range(n):
            for j in range(n):
                if ((i != j) and (nums[j] < nums[i])):
                    output[i] += 1

        return output