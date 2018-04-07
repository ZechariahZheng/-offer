#include <iostream>
#include <limits.h>
#include <stdlib.h>

using namespace std;

/*输入一棵二叉树，判断该二叉树是否是平衡二叉树。
平衡二叉树的定义：左右子树的高度相差不超过1*/

/*思路：求左右子树的深度，然后比较左右子树的高度差*/

void PreSearch(TreeNode* pRoot, int& result, int& tmp)
{
    if (pRoot == NULL)
    {
        if (tmp > result)
            result = tmp;
        return;
    }
    tmp++;
    PreSearch(pRoot->left, result, tmp);
    PreSearch(pRoot->right, result, tmp);
    tmp--;
}

bool IsBalanced_Solution(TreeNode* pRoot) 
{
    if (pRoot == NULL)
        return false;
    int leftDepth = 0;
    int rightDepth = 0;
    int tmp = 0;
    bool result = false;
    if (pRoot->left != NULL)
    {
        PreSearch(pRoot->left, leftDepth, tmp);
        tmp = 0;
    }
    if (pRoot->right != NULL)
        PreSearch(pRoot->right, rightDepth, tmp);
    if (abs(leftDepth-rightDepth) <= 1)
        result = true;
    return result;
}