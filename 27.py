# -*- coding:utf-8 -*-
import itertools
class Solution:
    def Permutation(self, ss):
        # write code here
        if not ss:
            return []

def test(ss):
    return list(map(''.join, itertools.permutations(ss)))

A = test("abc")
print(A)