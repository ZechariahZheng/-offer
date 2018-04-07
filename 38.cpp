#include <iostream>

using namespace std;

/*˼·������ǰ������������ʵ�Ҷ���ʱ���Ƚ���󣬷��ص����ڵ�ʱ����ȥ1*/
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

int TreeDepth(TreeNode* pRoot)
{
    int result = 0;
    if (pRoot == NULL)
        return result;
    int tmp = 0;
    PreSearch(pRoot, result, tmp);
    return result;
}