#include <iostream>

using namespace std;

/*请实现两个函数，分别用来序列化和反序列化二叉树
注：将树写入一个文件被称为“序列化”，读取文件后重建同样的二叉树被称为”反序列化“*/

/*思路：
序列化：使用先序遍历保存二叉树到文件中（注：同时把二叉树到文件）
反序列化：读取每个节点，忽略‘#’
注：需将数字转换为字符串，使用sprintf函数快速转换，利用strcpy和strcat函数快速复制字符串*/


TreeNode* buildTree(char *&str)
{
    if (*str == '#')
    {
        str++;
        return NULL;
    }
    int number = 0;
    while (*str != ',')
    {
        number = number*10+*str-'0';
        str++;
    }
    str++;
    TreeNode* root = new TreeNode(number);
    root->left = buildTree(str);
    root->right = buildTree(str);
    
    return root;
}

char* Serialize(TreeNode *root)
{
    if (root == NULL)
        return "#";
    char tmp[20];
    sprintf(tmp, "%d,", root->val);
    char *left = Serialize(root->left);
    char *right = Serialize(root->right);
    char *result = new char[strlen(tmp)+strlen(left)+strlen(right)];
    strcpy(result, tmp);
    strcat(result, left);
    strcat(result, right);
    
    return result;
}

TreeNode* Deserialize(char *str)
{
    if (str == NULL)
        return NULL;
    return buildTree(str);
}

int main()
{
    return 0;
}