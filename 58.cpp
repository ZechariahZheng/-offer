#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

/*请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。*/
/*思路：二叉树的镜像
比较中序遍历的正反，只适合每个结点保存不一样的值
故，将二叉树镜像之后，将每个结点进行比较*/

/*二叉树的镜像*/
TreeNode* tmp = NULL;
void mirrorTree(TreeNode* pRoot)
{
    if (pRoot == NULL)
        return;
    tmp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = tmp;
    mirrorTree(pRoot->left);
    mirrorTree(pRoot->right);
}

/*二叉树的复制*/
TreeNode* copyTree(TreeNode* pRoot)
{
    if (pRoot == NULL)
        return NULL;
    TreeNode* newRoot = new TreeNode(pRoot->val);
    newRoot->left = copyTree(pRoot->left);
    newRoot->right = copyTree(pRoot->right);
    return newRoot;
}

/*比较镜像二叉树与原二叉树*/
bool compareTree(TreeNode* pRoot, TreeNode* newRoot)
{
    if (pRoot==NULL && newRoot==NULL)
        return true;
    if (pRoot!=NULL && newRoot==NULL)
        return false;
    if (pRoot==NULL && newRoot!=NULL)
        return false;
    if (pRoot->val != newRoot->val)
        return false;
    return compareTree(pRoot->left, newRoot->left) && compareTree(pRoot->right, newRoot->right);
}

bool isSymmetrical(TreeNode* pRoot)
{
    bool result = false;
    if (pRoot == NULL)
    {
        result = true;
        return result;
    }
    /*复制二叉树*/
    TreeNode* newRoot = copyTree(pRoot);
    /*将二叉树镜像*/
    mirrorTree(newRoot);
    /*比较镜像二叉树与原二叉树的每个结点*/
    result = compareTree(pRoot, newRoot);
    
    return result;
}

int main()
{
    return 0;
}