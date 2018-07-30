# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

#注：head = listNode 直接用类赋值，该类就是地址
class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        result = []
        head = listNode
        while head:
            result.insert(0, head.val)
            head = head.next
        return result