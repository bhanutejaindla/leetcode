class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        ans = []
        for i in range(n):
            flag = False
            for j in range(i + 1, n):
                if prices[i] >= prices[j]:
                    flag = True
                    ans.append(prices[i]-prices[j])
                    break
            if flag == False:
                ans.append(prices[i])
        return ans
        