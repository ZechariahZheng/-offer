# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def EntryNodeOfLoop(self, pHead):
        # write code here
        if not pHead:
            return None
        Visited = []
        flag = False
        result = None
        while pHead:
            for tmp in Visited:
                if tmp == pHead:
                    flag = True
                    result = pHead
            if not flag:
                Visited.append(pHead)
            else:
                break
            pHead = pHead.next
        return result