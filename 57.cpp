#include <iostream>

using namespace std;

/*给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。*/

/*思路：该节点的下一个节点应该是该节点的右子树上的叶子节点
1、该节点的右子树不为空，按中序遍历寻找到叶子节点(即一直寻找最左端的叶子节点)
2、该节点的右子树为空，返回到上一层的节点
（1）该节点为上一层节点的左子树节点，返回上一层节点
（2）该节点为上一层节点的右子树节点，再遍历父节点的上一层节点，判断是否为其左子树节点*/
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
    /*中序遍历*/
    TreeLinkNode *result = NULL;
    if (pNode == NULL)
        return result;

    /*如果该节点的右子树不为空*/
    if (pNode->right != NULL)
    {
        TreeLinkNode *father = pNode->right;
        while (father->left != NULL)
        {
            father = father->left;
        }
        result = father;
    }
    else    //该节点的右子树为空
    {
        while (pNode->next != NULL)
        {
            if (pNode == pNode->next->left)
            {
                result = pNode->next;
                break;
            }
            pNode = pNode->next;
        }
    }
    return result;
}

int main()
{
    return 0;
}