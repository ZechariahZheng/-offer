# -*- coding:utf-8 -*-
class Solution:
    def LastRemaining_Solution(self, n, m):
        # write code here
        if n==0 and m==0:
            return -1
        all = list(range(n))
        while len(all) > 1:
            if len(all) > m:
                all.pop(m-1)
                all = all[m-1:] + all[:m-1]
            else:
                if m%len(all) == 0:
                    all.pop(len(all)-1)
                else:
                    tmp = m%len(all)-1
                    all.pop(tmp)
                    all = all[tmp:] + all[:tmp]
        return all[0]
        
S = Solution()
print(S.LastRemaining_Solution(3, 4))