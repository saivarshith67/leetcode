"""
Approaches:
1) create an array from 1 to n iterate through nums if the number is present in the array then delete it else ignore after iterating it entirely what we have is the remaining -> O(n^2)
"""

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        hashset = set(nums)
        ans = []

        for i in range(1, len(nums) + 1):
            if i not in hashset:
                ans.append(i)

        return ans

        