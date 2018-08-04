# -*- coding:utf-8 -*-
class Solution:
    # 返回[a,b] 其中ab是出现一次的两个数字
    def FindNumsAppearOnce(self, array):
        # write code here
        result = []
        for n in array:
            if array.count(n) == 1:
                result.append(n)
            if len(result) == 2:
                break
        result