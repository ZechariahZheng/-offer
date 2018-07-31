# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.all = [1, 1, 2]
    def jumpFloorII(self, number):
        # write code here
        if len(self.all) >= number+1:
            return sel.all[number]
        else:
            for i in range(len(self.all), number+1):
                tmp = 0
                for j in range(1, len(self.all)):
                    tmp += self.all[j]
                self.all.append(tmp)
            return self.all[number]