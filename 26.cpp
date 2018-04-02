/*输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。*/

/*思路：利用中序遍历将二叉树搜索一遍，保存到队列中，然后将队列中元素出栈*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
void MidSearch(TreeNode* pRootOfTree, queue<TreeNode*>&q)
{
    if (pRootOfTree == NULL)
        return;
    MidSearch(pRootOfTree->left, q);
    q.push(pRootOfTree);
    MidSearch(pRootOfTree->right, q);
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
    if (pRootOfTree == NULL)
        return NULL;
    queue<TreeNode*> q;
    MidSearch(pRootOfTree, q);
    TreeNode* result = q.front();
    TreeNode* now;
    TreeNode* next;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        if (!q.empty())
        {
            next = q.front();
            next->left = now;
        }
        else
        {
            next = NULL;
        }
        now->right = next;
    }
    return result;
}