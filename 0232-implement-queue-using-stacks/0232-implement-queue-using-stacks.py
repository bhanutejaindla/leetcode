class MyQueue:

    def __init__(self):
        self.ans = []
        

    def push(self, x: int) -> None:
        self.ans.append(x)
        

    def pop(self) -> int:
        return self.ans.pop(0)
        

    def peek(self) -> int:
        return self.ans[0]
        

    def empty(self) -> bool:
        if(len(self.ans) == 0):
            return True
        return False
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()