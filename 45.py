# -*- coding:utf-8 -*-
class Solution:
    def IsContinuous(self, numbers):
        # write code here
        if not numbers:
            return False
        numbers = sorted(numbers)
        pre = -1
        distance = 0
        for n in numbers:
            if n==pre and n!=0:
                return False
            if n-pre>1 and pre>0:
                distance += n-pre-1
            pre = n
        if numbers.count(0) >= distance:
            return True
        else:
            return False
S = Solution()
if S.IsContinuous([1,3,2,5,4]):
    print("hello world")