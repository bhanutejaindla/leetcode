class Solution:
    def minOperations(self, s: str) -> int:
        mini = 10**4;
        expected = 0
        ans = 0
        s_list = list(s)
        for i in range(len(s_list)):
            if int(s_list[i]) == expected:
                expected = not expected
                continue
            else:
                ans += 1
                s_list[i] = str(expected)
                expected = not expected

        expected = 1
        ans1 = 0
        s_list1 = list(s)
        for i in range(len(s_list1)):
            if int(s_list1[i]) == expected:
                expected = not expected
                continue
            else:
                ans1 += 1
                s_list1[i] = str(expected)
                expected = not expected
        return min(ans, ans1)
            
        



        