#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

/*从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。*/

/*思路：
二叉树的层次遍历，利用队列来实现
要知道何时遍历完一层:使用两个队列，一个表示该层所有节点，另一个表示下一层所有节点*/

vector<vector<int> > Print(TreeNode* pRoot) 
{
    vector<vector<int> > result;
    if (pRoot == NULL)
        return result;
    queue<TreeNode*> qFather;           //当前该层的所有结点
    queue<TreeNode*> qChild;            //下一层的所有结点
    queue<TreeNode*> qClear;
    vector<int> tmpResult;
    TreeNode* tmp = NULL;
    qFather.push(pRoot);
    
    while (!qFather.empty())
    {
        tmp = qFather.front();
        qFather.pop();
        tmpResult.push_back(tmp->val);
        if (tmp->left)
            qChild.push(tmp->left);
        if (tmp->right)
            qChild.push(tmp->right);
        if (qFather.empty())    //如果该层遍历完毕
        {
            qFather = qChild;
            qChild = qClear;        //清空下一层的节点
            result.push_back(tmpResult);
            tmpResult.clear();      //清空临时值
        }
    }
    return result;
}

int main()
{
    return 0;
}