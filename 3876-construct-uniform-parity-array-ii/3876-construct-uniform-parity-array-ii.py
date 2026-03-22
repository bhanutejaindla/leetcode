class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        nums1.sort()
        even = 0
        n = len(nums1)
        for i in range(len(nums1)):
            if nums1[i]%2 == 0:
                even += 1
        odd = n - even
        if even == 0 or odd == 0:
            return True
        for i in range(1,n):
            if nums1[i]%2 != nums1[i - 1]%2 :
                if (nums1[i] - nums1[i - 1]) >= 1 and (nums1[i] - nums1[i - 1])%2 == nums1[i -1]%2:
                    nums1[i] = nums1[i] -  nums1[i - 1]
                else:
                    return False
        return True

        