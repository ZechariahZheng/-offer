#include <iostream>
#include <vector>

using namespace std;

/*С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100�����������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��
û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22�����ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck!
*/

/*��ĸ��������
˼·�����������ҵ���Ϊs�����*/
vector<vector<int> > FindContinuousSequence(int sum)
{
    int tmp;
    vector<int> tmpResult;
    vector<vector<int>> result;
    bool IsSum = false;
    
    for (int i = 1; i < sum; i++)
    {
        tmp = i;
        tmpResult.push_back(i);
        IsSum = false;
        for (int j = i+1; j < sum; j++)
        {
            tmp += j;
            if (tmp < sum)
            {
                tmpResult.push_back(j);
            }
            else if (tmp == sum)
            {
                tmpResult.push_back(j);
                IsSum = true;
                break;
            }
            else
                break;
        }
        if (IsSum == true)
            result.push_back(tmpResult);
        tmpResult.swap(vector<int>());
    }
	return result;
}

int main()
{
    vector<vector<int>> result;
    result = FindContinuousSequence(100);
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