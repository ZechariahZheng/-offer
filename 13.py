# -*- coding:utf-8 -*-
class Solution:
    def reOrderArray(self, array):
        # write code here
        array.sort()     #从小到大排序
        oushu = []; jishu = []
        for i in range(len(array)):
            if array[i]%2 == 0:
                oushu.append(array[i])
            else:
                jishu.append(array[i])
        return jishu+oushu
        
S = Solution()
test = [1,2,3,4,5,6,7]
print(S.reOrderArray(test))