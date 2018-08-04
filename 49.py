# -*- coding:utf-8 -*-
class Solution:
    def StrToInt(self, s):
        # write code here
        try:
            return int(s)
        except Exception as e:
            return 0