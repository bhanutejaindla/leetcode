class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        prefix_x = [ [0] * n  for _ in range(m)]
        prefix_y = [ [0] * n  for _ in range(m)]
        ans = 0
        for i in range(m):
            for j in range(n):
                x = 1 if grid[i][j] == 'X' else 0
                y = 1 if grid[i][j] == 'Y' else 0
                prefix_x[i][j] = x
                prefix_y[i][j] = y
                if i > 0:
                    prefix_x[i][j] += prefix_x[i-1][j]
                    prefix_y[i][j] += prefix_y[i-1][j]
                if j > 0:
                    prefix_x[i][j] += prefix_x[i][j - 1]
                    prefix_y[i][j] += prefix_y[i][j - 1]
                if i > 0 and j > 0:
                    prefix_x[i][j] -= prefix_x[i - 1][j - 1]
                    prefix_y[i][j] -= prefix_y[i - 1][j - 1]
                
                if prefix_x[i][j] > 0 and prefix_x[i][j] == prefix_y[i][j]:
                    ans += 1
                    
        return ans   
                


        