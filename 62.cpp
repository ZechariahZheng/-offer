#include <iostream>

using namespace std;

/*给定一颗二叉搜索树，请找出其中的第k大的结点。例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。*/

/*思路：
遍历整个二叉树，将结果保存在vector数组中，然后将该数组从小到大排序，返回第k个节点（该方法对于空节点无用）

利用二叉搜索树的中序遍历，即从小到大排序

注：二叉搜索树的定义:
1、若任意节点的左子树不空，则左子树上所有节点的值均小于它的根节点的值；
2、若任意节点的右子树不空，则右子树上所有节点的值均大于它的根节点的值；
3、任意节点的左、右子树也分别为二叉查找树；
4、没有键值相等的节点。*/

void midSearch(TreeNode* pRoot, int &count, const int k, TreeNode* &result)
{
    if (pRoot == NULL || count <= 0)
        return;
    midSearch(pRoot->left, count, k, result);      //遍历左子树
    count++;            //返回到上一层，故需要加上1
    if (count == k)     //找到
    {
        result = pRoot;
        return;
    }
    if (count!=k)
    {
        midSearch(pRoot->right, count, k, result);
    }
}

TreeNode* KthNode(TreeNode* pRoot, int k)
{
    TreeNode* result = NULL;
    if (pRoot == NULL || k < 1)
        return result;
    int i = 1;
    midSearch(pRoot, i, k, result);
    
    return result;
}

int main()
{
    return 0;
}