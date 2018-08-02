# -*- coding:utf-8 -*-
class Solution:
    def GetLeastNumbers_Solution(self, tinput, k):
        # write code here
        if k > len(tinput) or k == 0:
            return []
        newinput = sorted(tinput)
        result = []
        for i in range(len(newinput)):
            if i != k-1:
                result.append(newinput[i])
            else:
                result.append(newinput[i])
                return result