class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        m = len(mat)
        n = len(target)
        flag = [True] * 4
        for i in range(n):
            for j in range(n):
                if mat[i][j] != target[i][j]:
                    flag[0] = False
                if mat[i][j] != target[j][n - i -1]:
                    flag[1] = False
                if mat[i][j] != target[n - i - 1][n - j -1]:
                    flag[2] = False
                if mat[i][j] != target[n - j - 1][i]:
                    flag[3] = False
        

        return flag[0] or flag[1] or flag[2] or flag[3]  
        