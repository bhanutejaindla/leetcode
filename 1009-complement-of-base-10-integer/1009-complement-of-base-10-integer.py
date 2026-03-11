class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n == 0:
            return 1
        binary_str = bin(n)[2:]
        complement_str = "".join("0" if bit == '1' else '1' for bit in binary_str)

        return int(complement_str,2)
        