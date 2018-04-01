#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};



/*输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。*/

/*思路：使用前序遍历到达叶结点后，但是要以上遍历的节点之和小于expectNumber*/

/*参数说明：root根节点
            */
void PreOrder(TreeNode* root, vector<vector<int>> &result, vector<int> &resultTmp, const int expectNumber, int &sum)
{
    if (root != NULL)
    {
        resultTmp.push_back(root->val);
        sum += root->val;
        
        if (root->left==NULL && root->right==NULL)      //为叶结点
        {
            if (sum == expectNumber)        //满足要求
                result.push_back(resultTmp);
        }
        if (root->left != NULL)
            PreOrder(root->left, result, resultTmp, expectNumber, sum);
        if (root->right != NULL)
            PreOrder(root->right, result, resultTmp, expectNumber, sum);
        /*在返回父节点之前删除，当前的节点*/
        resultTmp.pop_back();
        sum -= root->val;
    }
}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber) 
{
    vector<vector<int> > result;
    vector<int> resultTmp;
    int sum = 0;
    if (root == NULL)
        return result;
    else
        PreOrder(root, result, resultTmp, expectNumber, sum);
    return result;
}

int main()
{
    TreeNode x[5];
    x[0].val = 10;
    x[0].left = &x[1];
    x[0].right = &x[2];
    x[1].val = 5;
    x[1].left = &x[3];
    x[1].right = &x[4];
    x[2].val = 5;
    x[2].left = NULL;
    x[2].right = NULL;
    x[3].val = 4;
    x[3].left = NULL;
    x[3].right = NULL;
    x[4].val = 7;
    x[4].left = NULL;
    x[4].right = NULL;
    vector<vector <int>> result;
    result = FindPath(&x[0], 22);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}