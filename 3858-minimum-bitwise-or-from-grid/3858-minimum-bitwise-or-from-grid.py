class Solution:
    def minimumOR(self, grid: List[List[int]]) -> int:
        res = 0
        for bi in range(20, -1, -1):
            b = 1 << bi
            mask = res | b - 1
            for r in grid:
                if all((a & mask) < a for a in r):
                    res |= b
                    break
        return res
        