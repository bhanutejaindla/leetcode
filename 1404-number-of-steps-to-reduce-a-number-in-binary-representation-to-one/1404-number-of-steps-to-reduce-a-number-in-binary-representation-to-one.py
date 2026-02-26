class Solution:
    def numSteps(self, s: str) -> int:
        decimal_num = int(s,2)
        cnt = 0
        while decimal_num != 1:
            if decimal_num % 2 == 1:
                decimal_num += 1
            else:
                decimal_num //=2
            cnt += 1
        return cnt

        