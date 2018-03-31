#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*�������´�ӡ������*/
/*˼�룺���ϵ��£����ö�����ʱ���д洢��һ�����еĽڵ����һ������нڵ㣬�Ҷ��Ǵ����Ҵ洢��*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

vector<int> PrintFromTopToBottom(TreeNode* root) 
{
    if (root == NULL)
    {
        vector<int> result(0);
        return result;
    }
    queue<TreeNode*> tmp;     //�洢��һ������нڵ�
    queue<TreeNode*> tmp_1;     //�洢��һ������нڵ�
    queue<TreeNode*> result;  //�洢���
    
    result.push(root);
    tmp.push(root);
    do{
        while (!tmp.empty())
        {           
            TreeNode* tmpNode = tmp.front();
            if (tmpNode->left != NULL)
            {
                tmp_1.push(tmpNode->left);
                result.push(tmpNode->left);
            }
            if (tmpNode->right != NULL)
            {
                tmp_1.push(tmpNode->right);
                result.push(tmpNode->right);
            }
            tmp.pop();
        }
        swap(tmp, tmp_1);       //����һ���Ƶ���һ��, ��һ���ʼ��Ϊ0
    }while(!tmp.empty());       //ֻҪ��һ��һֱ�нڵ㣬��ѭ��ִ��
    
    vector<int> resultV(result.size(), 0);
    int VAL = 0;
    for (int i = 0; i < resultV.size(); i++)
    {
        VAL = result.front()->val;
        resultV[i] = VAL;
        result.pop();
    }
    return resultV;
}

int main()
{
    TreeNode x[5];
    x[0].val = 0;
    x[0].left = &x[1];
    x[0].right = &x[2];
    x[1].val = 1;
    x[1].left = &x[3];
    x[1].right = &x[4];
    x[2].val = 2;
    x[2].left = NULL;
    x[2].right = NULL;
    x[3].val = 3;
    x[3].left = NULL;
    x[3].right = NULL;
    x[4].val = 4;
    x[4].left = NULL;
    x[4].right = NULL;
    
    vector<int> tmp;
    tmp = PrintFromTopToBottom(&x[0]);    
    for (int i = 0; i < tmp.size(); i++)
        cout << tmp[i] << endl;
	system("pause");
    return 0;
}