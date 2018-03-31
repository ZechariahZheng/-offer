#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。*
*如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。*/
/*思路：
已知条件：后序序列最后一个值为root；二叉搜索树左子树值都比root小，右子树值都比root大。
1、确定root；
2、遍历序列（除去root结点），找到第一个大于root的位置，则该位置左边为左子树，右边为右子树；
3、遍历右子树，若发现有小于root的值，则直接返回false；
4、分别判断左子树和右子树是否仍是二叉搜索树（即递归步骤1、2、3）。*/

/*参数说明：start数组起点*
*           end数组终点*/
bool VerifySquenceOfBST_INT(int* sequence,int start,int end) 
{
   if(start>=end)
   {
       return true;//如果数组中只有一个节点返回TRUE
   }
   int right=start;
   int point=sequence[end];
   int i=end-1;    
   for(;i>=0;i--)
   {
       if(sequence[i]<point)
       {
           right=i;
           break;//标记右子树上节点的最左边位置
       }
   }
   for(;i>=0;i--)
   {
       if(sequence[i]>=point)
       {
           return false;//如果左子树上有比根节点大的值返回false
       }
   }
   return VerifySquenceOfBST_INT(sequence,right+1,end-1)&&VerifySquenceOfBST_INT(sequence,start,right);

}
bool VerifySquenceOfBST(vector<int> sequence) 
{
    if (sequence.empty())
        return false;
    int *sequenceInt = new int[sequence.size()];
    for (int i = 0; i < sequence.size(); i++)
        sequenceInt[i] = sequence[i];
    return VerifySquenceOfBST_INT(sequenceInt, 0, sequence.size()-1);
}

int main()
{
    int a[5] = {1,2,3,4,5};
    vector<int> test(&a[0], &a[5]);
    bool flag = VerifySquenceOfBST(test);
    if (flag)
		cout << "YES" << endl;
	else
		cout <<"NO" << endl;
	system("pause");
    return 0;
}