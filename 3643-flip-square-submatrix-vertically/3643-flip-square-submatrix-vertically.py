class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        m = x + k 
        n = y + k 
        for i in range(x, x + k//2):
            for j in range(y,n):
                new_x = m - 1 - (i - x )
                print(new_x)
                grid[i][j], grid[new_x][j] = grid[new_x][j], grid[i][j]
        
        return grid