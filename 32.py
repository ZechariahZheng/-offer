# -*- coding:utf-8 -*-
import itertools

class Solution:
    def PrintMinNumber(self, numbers):
        # write code here
        all = list(itertools.permutations(numbers))
        result = ''
        for i in range(len(all)):
            tmp = ''
            for n in all[i]:
                tmp += str(n)
            if i == 0 or tmp < result:
                result = tmp
        return result
S = Solution()
print(S.PrintMinNumber([3,32,321]))