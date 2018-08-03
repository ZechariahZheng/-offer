# -*- coding:utf-8 -*-
class Solution:
    def NumberOf1Between1AndN_Solution(self, n):
        # write code here
        result = 0
        for i in range(n+1):
            if '1' in str(i):
                result += str(i).count('1')
        return result
S = Solution()
print(S.NumberOf1Between1AndN_Solution(55))