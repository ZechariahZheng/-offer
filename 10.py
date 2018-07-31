# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.all = [0, 1, 2]
    def rectCover(self, number):
        # write code here
        if len(self.all) >= number+1:
            return self.all[number]
        else:
            for i in range(len(self.all), number+1):
                self.all.append(self.all[-1]+self.all[-2])
            return self.all[number]