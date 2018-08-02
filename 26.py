# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def Convert(self, pRootOfTree):
        # write code here
        if not pRootOfTree:
            return pRootOfTree
        tmp = []
        self.MidSearch(pRootOfTree, tmp)
        for i in range(len(tmp)):
            if i==0:
                tmp[i].left = None
                if len(tmp) > 2:
                    tmp[i].right = tmp[1]
                else:
                    tmp[i].right = None
            elif i==len(tmp)-1:
                tmp[i].right = None
                tmp[i].left = tmp[i-1]
            else:
                tmp[i].left = tmp[i-1]
                tmp[i].right = tmp[i+1]
        return tmp[0]
    def MidSearch(self, Root, all):
        if not Root:
            return
        self.MidSearch(Root.left, all)
        all.append(Root)
        self.MidSearch(Root.right, all)

