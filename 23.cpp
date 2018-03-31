#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����*
*����������Yes,�������No���������������������������ֶ�������ͬ��*/
/*˼·��
��֪�����������������һ��ֵΪroot������������������ֵ����rootС��������ֵ����root��
1��ȷ��root��
2���������У���ȥroot��㣩���ҵ���һ������root��λ�ã����λ�����Ϊ���������ұ�Ϊ��������
3����������������������С��root��ֵ����ֱ�ӷ���false��
4���ֱ��ж����������������Ƿ����Ƕ��������������ݹ鲽��1��2��3����*/

/*����˵����start�������*
*           end�����յ�*/
bool VerifySquenceOfBST_INT(int* sequence,int start,int end) 
{
   if(start>=end)
   {
       return true;//���������ֻ��һ���ڵ㷵��TRUE
   }
   int right=start;
   int point=sequence[end];
   int i=end-1;    
   for(;i>=0;i--)
   {
       if(sequence[i]<point)
       {
           right=i;
           break;//����������Ͻڵ�������λ��
       }
   }
   for(;i>=0;i--)
   {
       if(sequence[i]>=point)
       {
           return false;//������������бȸ��ڵ���ֵ����false
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