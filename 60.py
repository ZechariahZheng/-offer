# -*- coding:utf-8 -*-
class Solution:
    def maxInWindows(self, num, size):
        # write code here
        if size == 0:
            return []
        length = len(num)
        result = []
        for i in range(length-size+1):
            tmp = num[i:i+size]
            result.append(max(tmp))
        return result
All = [2,3,4,2,6,2,5,1]
S = Solution()
print(S.maxInWindows(All, 3))