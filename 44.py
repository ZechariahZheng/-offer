# -*- coding:utf-8 -*-
class Solution:
    def ReverseSentence(self, s):
        # write code here
        result = s.split(' ')
        return ' '.join(result[::-1])