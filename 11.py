# -*- coding:utf-8 -*-
class Solution:
    def NumberOf1(self, n):
        # write code here
        BinN = bin(n & 0b11111111111111111111111111111111)
        return BinN.count('1')

S = Solution()
print(S.NumberOf1(-1))