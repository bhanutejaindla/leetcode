class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        n=len(arr)
        count=0
        for i in range(0,n):
            for j in range (i,n):
                for k in range(j,n):
                    if i<j and j<k:
                        x=abs(arr[i]-arr[j])
                        y=abs(arr[i]-arr[k])
                        z=abs(arr[j]-arr[k])
                        if x<=a and y<=c and z<=b:
                            count+=1
        return  count
        