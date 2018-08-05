# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    # 返回对应节点TreeNode
    def KthNode(self, pRoot, k):
        # write code here
        if not pRoot or k==0:
            return None
        result = []
        N = [0, k]
        self.MidSearch(pRoot, N, result)
        if k <= len(result):
            return result[k-1]
        else:
            return None
    
    def MidSearch(self, Root, N, result):
        if not Root or N[0] == N[1]:
            return
        self.MidSearch(Root.left, N, result)
        result.append(Root)
        N[0] += 1
        self.MidSearch(Root.right, N, result)

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
print(S.KthNode(All[0], 0))