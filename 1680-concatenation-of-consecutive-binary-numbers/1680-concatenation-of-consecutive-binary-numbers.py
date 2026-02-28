class Solution:
    def concatenatedBinary(self, n: int) -> int:
        ans = " "
        for i in range(1,n + 1):
            a = bin(i)
            ans += a[2:]
        
        decimal_number = int(ans, 2)
        return decimal_number % (10**9 + 7)

        