# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def deleteDuplication(self, pHead):
        # write code here，只是删除重复值的节点
        if not pHead:
            return None
        result = []
        last = 0
        while pHead:
            if len(result) > 0:
                if pHead.val == result[-1].val:
                    if len(result) >= 2:
                        result[-2].next = pHead.next
                    last = pHead.val
                    result.pop()
                else:
                    result.append(pHead)
            else:
                if last != pHead.val:
                    result.append(pHead)
            pHead = pHead.next
        if result != []:
            return result[0]
        else:
            return None