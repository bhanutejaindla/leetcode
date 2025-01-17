class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        ans=0
        for x in derived:
            ans^=x
        return ans==0
        