class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        freq = {}
        n = len(nums)//2
        for num in nums:
            freq[num]= freq.get(num, 0) +1

        for num , count in freq.items():
            if count >  n:
                return num
