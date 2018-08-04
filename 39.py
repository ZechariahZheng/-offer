# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def IsBalanced_Solution(self, pRoot):
        # write code here
        #思路：平衡二叉树的定义：左右子树的高度相差不超过1
        #求左右子树的深度，然后比较左右子树的高度差
        if not pRoot:
            return True
        LeftDepth, RightDepth = [0], [0]
        p = pRoot
        self.PreSearch(pRoot.left, [1], LeftDepth)
        self.PreSearch(p.right, [1], RightDepth)
        if abs(LeftDepth[0]-RightDepth[0])==1:
            return True
        else:
            return False
    def PreSearch(self, Root, tmp, result):
        if not Root:
            if tmp[0] > result[0]:
                result[0] = tmp[0]
        tmp[0] += 1
        self.PreSearch(Root.left, tmp, result)
        self.PreSearch(Root.right, tmp, result)
        tmp[0] -= 1