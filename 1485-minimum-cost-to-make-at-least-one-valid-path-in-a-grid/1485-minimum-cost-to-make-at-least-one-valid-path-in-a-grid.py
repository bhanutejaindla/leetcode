from collections import deque
class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        directions=[(0,1),(0,-1),(1,0),(-1,0)]
        visited=[[False] * n for _ in range(m)]
        q=deque([(0,0,0)])
        while q:
            r, c, cost= q.popleft()
            if visited[r][c]:
                continue
            visited[r][c]=True
            if(r,c)==(m-1,n-1):
                return cost
            for i,(dr,dc) in enumerate(directions):
                print(f"{i}")
                nr,nc=r+dr,c+dc
                if 0<=nr< m and 0<=nc< n and not visited[nr][nc]:
                    if grid[r][c] == i+1:
                        q.appendleft((nr,nc,cost))
                    else:
                        q.append((nr,nc,cost+1))
        
        return -1
        