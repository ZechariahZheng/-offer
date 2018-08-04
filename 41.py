# -*- coding:utf-8 -*-
class Solution:
    def FindContinuousSequence(self, tsum):
        # write code here
        tmp = 0
        result = []
        for i in range(1, tsum//2+2):
            tmp = i
            print(i)
            for j in range(i+1, tsum//2+2):
                tmp += j
                if tmp == tsum:
                    result.append(list(range(i, j+1)))
                elif tmp > tsum:
                    break
        return result
S = Solution()
print(S.FindContinuousSequence(3))