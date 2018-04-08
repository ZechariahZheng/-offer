#include <iostream>
#include <vector>

using namespace std;

/*小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
*/

/*非母函数问题
思路：挨个数字找到和为s的组合*/
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