class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        n = len(s)
        if n == 1:
            return True
        cnt = 0
        if s[0] == '1':
            cnt += 1
        cnt1 = 1
        for i in range(1,n):
            if s[i] == '1':
                cnt += 1
            if s[i] == '1' and s[i - 1] == '1':
                cnt1 += 1
            
        if cnt == cnt1:
            return True
        return False

        