class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        odd=0
        n=len(nums1)
        m=len(nums2)
        if n%2==0 and m%2==0:
            return 0
        elif n%2==1 and m%2==1:
            ans=0
            for i in nums1:
                ans=ans^i
            for x in nums2:
                ans=ans^x
            return ans
        elif n%2==1 and m%2==0:
            ans=0
            for x in nums2:
                ans=ans^x
            return ans
        elif n%2==0:
            ans=0
            for i in nums1:
                ans^=i
            return ans
        return 0
    
        