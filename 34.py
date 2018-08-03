# -*- coding:utf-8 -*-
class Solution:
    def FirstNotRepeatingChar(self, s):
        # write code here
        for char in s:
            if s.count(char) == 1:
                return s.index(char)
        return -1