# -*- coding:utf-8 -*-
class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here
        newnumbers = sorted(numbers)
        index = 1; last = newnumbers[0]
        for i in range(len(newnumbers)):
            if i>0 and last==newnumbers[i]:
                index +=1
            if index > len(newnumbers)//2:
                return last
            elif last != newnumbers[i]:
                index = 1
                last = newnumbers[i]
        return 0
S = Solution()
A = [1,2,3,2,2,2,5,4,2]
print(S.MoreThanHalfNum_Solution(A))