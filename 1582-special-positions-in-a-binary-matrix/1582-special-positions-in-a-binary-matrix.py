class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])
        ans = 0
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1:
                    flag = True
                    for k in range(m):
                        if k != i and mat[k][j] == 1:
                            flag = False
                            break
                    if flag == False: continue
                    for x in range(n):
                        if x != j and mat[i][x] == 1:
                            flag = False
                            break
                    if flag == True:
                        ans += 1
        return ans

        
        