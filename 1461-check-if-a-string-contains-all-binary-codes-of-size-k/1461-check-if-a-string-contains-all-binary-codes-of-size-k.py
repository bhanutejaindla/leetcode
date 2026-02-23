class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:

        my_set = set()
        n = len(s)
        for i in range(n):
            if i + k <= n:
                my_set.add(s[i:i + k])
                
        return len(my_set) == 2**k


        