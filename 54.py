# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def isSymmetrical(self, pRoot):
        # write code here
        return self.isSymBT(pRoot,pRoot)
         
    def isSymBT(self,tree1,tree2):
        if tree1 == None and tree2 == None:
            return True
        if tree1 == None or tree2 == None:
            return False
        if tree1.val != tree2.val:
            return False
         
        return self.isSymBT(tree1.left,tree2.right) and self.isSymBT(tree1.right,tree2.left)