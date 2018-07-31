# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.all = [0, 1, 1]
    def Fibonacci(self, n):
        # write code here
        if len(self.all) >= n+1:
            return self.all[n]
        else:
            for i in range(len(self.all), n+1):
                self.all.append(self.all[-1]+self.all[-2])
            return self.all[n]

S = Solution()
print(S.Fibonacci(4))