class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        n=len(s)
        if n==1:
            return False
        if n%2!=0:
            return False
        count=0
        for i in range(0,n):
            if(s[i]=='(' or locked[i]=="0"):
                count+=1
            else:
                count-=1
            if(count<0):
                return False
        count=0
        for i in range(0,n):
            if(s[n-i-1]==')' or locked[n-i-1]=="0"):
                count+=1
            else:
                count-=1
            if(count<0):
                return False
        return True
        
        
        