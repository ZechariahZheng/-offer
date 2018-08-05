# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.result = []
    def movingCount(self, threshold, rows, cols):
        # write code here
        if rows==1 and cols==1:
            return 1
        flag = [[False]*cols for i in range(rows)]          #访问标志位
        self.MyMovingCount(threshold, rows, cols, 0, 0, flag)
        return len(self.result)
    def MyMovingCount(self, threshold, rows, cols, currows, curcols, flag):
        ways = [1, -1]
        for way in ways:
            if currows+way<rows and currows+way>=0 and flag[currows+way][curcols]==False:
                tmp = 0
                for n in str(currows+way):
                    tmp += int(n)
                for m in str(curcols):
                    tmp += int(m)
                if tmp <= threshold:
                    flag[currows+way][curcols] = True           #表示已被访问过
                    print("the node is %d %d" %(currows+way, curcols))
                    self.result.append([currows+way, curcols])
                    self.MyMovingCount(threshold, rows, cols, currows+way, curcols, flag)
        for way in ways:
            if curcols+way<cols and curcols+way>=0 and flag[currows][curcols+way]==False:
                tmp = 0
                for n in str(curcols+way):
                    tmp += int(n)
                for m in str(currows):
                    tmp += int(m)
                if tmp <= threshold:
                    flag[currows][curcols+way] = True           #表示已被访问过
                    print("the node is %d %d" %(currows, curcols+way))
                    self.result.append([currows, curcols+way])
                    self.MyMovingCount(threshold, rows, cols, currows, curcols+way, flag)
        return

S = Solution()
print(S.movingCount(15,1,1))