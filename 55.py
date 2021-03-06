# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def Print(self, pRoot):
        # write code here
        if not pRoot:
            return []
        Now = [pRoot]       #该层所有节点
        Next = [None]       #下一层所有节点
        N = 1
        result = []
        
        while Next != []:
            if Next != []:
                Next = []
            for p in Now:
                if p.left:
                    Next.append(p.left)
                if p.right:
                    Next.append(p.right)
            tmp = []
            while len(Now) > 0:
                if N%2 == 1:
                    tmp.append(Now[0].val)
                    Now.pop(0)
                else:
                    tmp.append(Now[-1].val)
                    Now.pop()
            result.append(tmp)
            Now = Next
            N += 1
        return result
        
All = []
test = [8, 6, 10, 5, 7, 9, 11]
for n in test:
    All.append(TreeNode(n))
All[0].left = All[1]
All[0].right = All[2]
All[1].left = All[3]
All[1].right = All[4]
All[2].left = All[5]
All[2].right = All[6]
S = Solution()
print(S.Print(All[0]))