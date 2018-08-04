# -*- coding:utf-8 -*-
class Solution:
    def LeftRotateString(self, s, n):
        # write code here
        left = s[:n]
        right = s[n:]
        return right+left
S = Solution()
print(S.LeftRotateString("abcXYZdef", 3))