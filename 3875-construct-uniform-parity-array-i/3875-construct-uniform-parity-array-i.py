class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        even = 0
        n = len(nums1)
        for i in range(len(nums1)):
            if nums1[i]%2 == 0:
                even += 1
        odd = n - even
        return True

        
        

        