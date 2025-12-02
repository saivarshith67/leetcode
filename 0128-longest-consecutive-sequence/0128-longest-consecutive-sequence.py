class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        """
        if left neighbour doesn't exist in the set => start of the sequence
        if left neigbhour exist in the set => not start of the sequence => skip
        if right neighbour exist in the set => continue checking for it's right neighbout in the set
        """

        hash_set = set(nums)
        longest = 0
        for num in hash_set:
            # start of sequence
            if num - 1 not in hash_set:

                length = 0

                while (num + length) in hash_set:
                    length += 1

                longest = max(longest, length)


        return longest