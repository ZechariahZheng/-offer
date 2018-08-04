# -*- coding:utf-8 -*-
class Solution:
    def FindNumbersWithSum(self, array, tsum):
        # write code here
        result = []
        for i, n in enumerate(array):
            for m in array[i:]:
                if n+m == tsum:
                    result.append([n,m])
        if result:
            return result[0]
        else:
            return result