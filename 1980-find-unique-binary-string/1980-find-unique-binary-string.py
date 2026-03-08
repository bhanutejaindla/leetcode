class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n = len(nums)
        st = set()
        for x in nums:
            st.add(x)
        a = ""
        for i in range(len(nums)):
            a += "0"
        if a not in st:
            return a
        for i in range(len(nums)):
            b = list(a)
            b[i] = "1"
            c = ''.join(b)
            if c not in st:
                return c
        return ""

        



        