class Solution:
    def minAbsDiff(self, grid: List[List[int]], k: int) -> List[List[int]]:
        x = len(grid)
        y = len(grid[0])
        ans = [ [0] * (y - k + 1) for _ in range(x - k + 1)]
        for i in range(0, x - k + 1):
            for j in range(0, y - k + 1):
                a = []
                mini = float('inf')
                for m in range(i,i + k):
                    for n in range(j, j + k):
                        a.append(grid[m][n])
                a = sorted(set(a))
                if(len(a) == 1):
                    ans[i][j] = 0
                else:
                    for t in range(1,len(a)):
                        mini = min(mini, abs(a[t] - a[t - 1]))
                    ans[i][j] = mini
        return ans

                