class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        ans = []
        m = len(grid)
        n = len(grid[0])
        for i in range(m):
            sum1 = 0
            for j in range(n):
                sum1 += grid[i][j]
            ans.append(sum1)
        a = 0
        totalsum = 0
        for i in range(len(ans)):
            totalsum += ans[i]
        for i in range(len(ans)):
            a += ans[i]
            if a == totalsum - a:
                return True
        ans = []
        m = len(grid)
        n = len(grid[0])
        for i in range(n):
            sum = 0
            for j in range(m):
                sum += grid[j][i]
            ans.append(sum)
        x = len(ans)
        a = 0
        totalsum = 0
        for i in range(len(ans)):
            totalsum += ans[i]
        for i in range(len(ans)):
            a += ans[i]
            if a == totalsum - a:
                return True
        return False
        
                
        