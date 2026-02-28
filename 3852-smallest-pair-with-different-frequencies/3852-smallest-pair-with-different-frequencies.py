class Solution:
    def minDistinctFreqPair(self, nums: list[int]) -> list[int]:
        ans = []
        mp = {}
        for i in range(len(nums)):
            mp[nums[i]] = mp.get(nums[i], 0) + 1
        print(mp)
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if mp[nums[i]] != mp[nums[j]]:
                    a = min(nums[i], nums[j])
                    b = max(nums[i], nums[j])
                    ans.append([a, b])
        print(ans)
        ans.sort()
        if not ans:
            return [-1, -1]
        return ans[0]
        