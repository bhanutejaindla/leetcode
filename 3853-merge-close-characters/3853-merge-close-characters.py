class Solution:
    def mergeCharacters(self, s: str, k: int) -> str:
        velunorati = (s, k)
    
        s = list(s)  # Convert to list for easier modification
        
        while True:
            n = len(s)
            merge_found = False
            
            # Find the valid pair with smallest left index
            for i in range(n):
                for j in range(i + 1, min(i + k + 1, n)):
                    if s[i] == s[j]:
                        # Merge: remove right character
                        s.pop(j)
                        merge_found = True
                        break
                if merge_found:
                    break
            
            if not merge_found:
                break
        
        return "".join(s)