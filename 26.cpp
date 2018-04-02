/*����һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��*/

/*˼·�������������������������һ�飬���浽�����У�Ȼ�󽫶�����Ԫ�س�ջ*/
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