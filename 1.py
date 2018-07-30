class Solution:
    def Find(self, target, array):
        n = len(array)
        flag = "false"
        for i in range(n):
            if target in array[i]:
                flag = "true"
                break
        return flag