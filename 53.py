# -*- coding:utf-8 -*-
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None      next是指向父节点的
class Solution:
    def GetNext(self, pNode):
        # write code here
        if not pNode:
            return None
        #右子树不为空
        result = None
        if pNode.right:
            father = pNode.right
            while father.left:
                father = father.left
            result = father
        else:       #右子树为空
            while pNode.next:
                if pNode == pNode.next.left:
                    result = pNode.next
                    break
                pNode = pNode.next
        return result