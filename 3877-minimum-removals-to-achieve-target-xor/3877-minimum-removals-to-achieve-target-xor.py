class Solution:
    def minRemovals(self, nums: List[int], target: int) -> int:
        n = len(nums)
        
        dp = {0: 0}   # xor -> max length
        
        for num in nums:
            new_dp = dp.copy()
            for xor_val, length in dp.items():
                new_xor = xor_val ^ num
                new_dp[new_xor] = max(new_dp.get(new_xor, 0), length + 1)
            dp = new_dp
        
        if target not in dp:
            return -1
        
        return n - dp[target]