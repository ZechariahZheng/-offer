# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.all = []
    def push(self, node):
        # write code here
        self.all.append(node)
    def pop(self):
        # return xx
        tmp = self.all[0]
        self.all.pop(0)
        return tmp