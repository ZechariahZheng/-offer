# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.data = []
    def Insert(self, num):
        # write code here
        self.data.append(num)
        sorted(self.data)
    def GetMedian(self):
        # write code here
        length = len(self.data)
        if length%2 == 0:
            return (self.data[length//2]+self.data[length//2-1])/2.0
        else:
            return self.data[int(length//2)]