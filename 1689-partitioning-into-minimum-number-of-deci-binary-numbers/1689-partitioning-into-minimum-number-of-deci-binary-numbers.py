class Solution:
    def minPartitions(self, n: str) -> int:
        maxi = 0
        for i in range(len(n)):
            a = int(n[i])
            maxi = max(maxi, a)
        return maxi
        