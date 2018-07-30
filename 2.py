# -*- coding:utf-8 -*-
class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        result = ""
        for i in range(len(s)):
            if s[i] == ' ':
                result += "%20"
            else:
                result += s[i]
        return result