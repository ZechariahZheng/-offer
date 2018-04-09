#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

/*输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，
如果有多对数字的和等于S，输出两个数的乘积最小的。*/

/*思路：挨个数字遍历，将和为S的两个数保存到数组*/
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