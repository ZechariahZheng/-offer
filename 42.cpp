#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

/*����һ����������������һ������S���������в������������ǵ����ǵĺ�������S��
����ж�����ֵĺ͵���S������������ĳ˻���С�ġ�*/

/*˼·���������ֱ���������ΪS�����������浽����*/
vector<int> FindNumbersWithSum(vector<int> array,int sum)
{
    vector<int> result;
    if (array.size() == 0)
        return result;
    vector<pair<int, int>> tmp;
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = i+1; j < array.size(); j++)
        {
            if (array[i]+array[j] == sum)
            {
                tmp.push(make_pair(array[i], array[j]));
            }
        }
    }
    
    int min = INT_MAX;
    int first, second, tmp;
    for (int i = 0; i < tmp.size(); i++)
    {
        first = tmp[i].first;
        second = tmp[i].second;
        tmp = first*second;
        if (tmp < min)
        {
            min = tmp;
            result.clear();
            result.push(first);
            result.push(second);
        }
    }
    return result;
}

int main()
{
    system("pause");
    return 0;
}