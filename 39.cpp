#include <iostream>
#include <limits.h>
#include <stdlib.h>

using namespace std;

/*����һ�ö��������жϸö������Ƿ���ƽ���������
ƽ��������Ķ��壺���������ĸ߶�������1*/

/*˼·����������������ȣ�Ȼ��Ƚ����������ĸ߶Ȳ�*/

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