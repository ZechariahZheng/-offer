# -*- coding:utf-8 -*-
class Solution:
    def GetUglyNumber_Solution(self, index):
        # write code here
        if index == 0:
            return 0
        all = [1]
        last = 1
        while index >= len(all) or (index < len(all) and all[index-1] > last*2):
            all.append(last*2)
            all.append(last*3)
            all.append(last*5)
            all = sorted(set(all))
            last = all[all.index(last)+1]
        return all[index-1]
S = Solution()
print(S.GetUglyNumber_Solution(7))