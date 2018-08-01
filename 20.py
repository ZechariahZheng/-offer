# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.all = []
    def push(self, node):
        # write code here
        self.all.append(node)
    def pop(self):
        # write code here
        self.all.pop()
    def top(self):
        # write code here
        return self.all[-1]
    def min(self):
        # write code here
        return min(self.all)