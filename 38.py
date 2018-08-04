# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def TreeDepth(self, pRoot):
        # write code here
        if not pRoot:
            return 0
        result = [0]
        tmp = [0]
        self.PreSearch(pRoot, tmp, result)
        return result[0]
        
    def PreSearch(self, Root, tmp, result):
        if not Root:
            if tmp[0] > result[0]:
                result[0] = tmp[0]
            return
        tmp[0] += 1
        self.PreSearch(Root.left, tmp, result)
        self.PreSearch(Root.right, tmp, result)
        tmp[0] -= 1