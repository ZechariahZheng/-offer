# -*- coding:utf-8 -*-
class Solution:
    def InversePairs(self, data):
        # write code here
        result = 0
        tmp = []
        for n in data:
            if len(tmp) > 0:
                for tmpN in tmp:
                    if tmpN > n:
                        result += 1
            tmp.append(n)
        return result%1000000007
S = Solution()
test = [1,2,3,4,5,6,7,0]
print(S.InversePairs(test))