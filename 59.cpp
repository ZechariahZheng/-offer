#include <iostream>
#include <queue>
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

/*请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。*/

/*思路：
二叉树的层次遍历的变形
二叉树的层次遍历使用队列来实现
交叉的使用队列和栈保存同一层的所有结点*/

/*二叉树的层次遍历*/
vector<vector<int> > levelTree(TreeNode* pRoot)
{
    vector<vector<int> > result;
    if (pRoot == NULL)
        return result;
    int i = 1;
    queue<TreeNode*> qTreeFather;       //遍历父节点队列
    queue<TreeNode*> qTreeChild;       //遍历子节点队列（从左到右）
    vector<int> tmpResult;
    stack<int> tmpStackResult;
    int tmpVal = 0;
    TreeNode* tmp = NULL;
    qTreeFather.push(pRoot);
    
    while (!qTreeFather.empty())
    {
        tmp = qTreeFather.front();
        qTreeFather.pop();
        
        if (i%2 == 0)
            tmpStackResult.push(tmp->val);          
        else
            tmpResult.push_back(tmp->val);          //保存从左到右的值
        
        if (tmp->left)
            qTreeChild.push(tmp->left);
        if (tmp->right)
            qTreeChild.push(tmp->right);
        
        /*一层遍历完成，遍历下一层*/
        if (qTreeFather.empty())
        {
            /*该层按从右到左排序*/
            if (i%2 == 0)
            {
                tmpResult.clear();
                while (!tmpStackResult.empty())
                {
                    tmpVal = tmpStackResult.top();
                    tmpResult.push_back(tmpVal);
                    tmpStackResult.pop();
                }
            }
            result.push_back(tmpResult);
            tmpResult.clear();
            swap(qTreeFather, qTreeChild);      //启动下一层
            i++;
        }
    }
    return result;
}

vector<vector<int> > Print(TreeNode* pRoot) 
{
    vector<vector<int> > result;
    if (pRoot == NULL)
        return result;
    result = levelTree(pRoot);
    
    return result;
}

int main()
{
    return 0;
}