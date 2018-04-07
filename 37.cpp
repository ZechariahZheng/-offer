#include <iostream>
#include <vector>
#include <algorithm>

/*统计一个数字在排序数组中出现的次数。*/

int GetNumberOfK(vector<int> data ,int k) 
{
    if (data.empty())
        return 0;
    vector<int>::iterator it_1;
    vector<int>::iterator it_2;
    vector<int>::iterator it;
    sort(data.begin(), data.end());     //排序
    it_1 = find(data.begin(), data.end(), k);
    if (it_1 == data.end())
        return 0;
    it_2 = find(it_1, data.end(), k+1);
    int result = 0;
    for (it = it_1; it < it_2; ++it)
    {
        if (*it == k)
            result++;
        else
            break;
    }
    return result;
}

int main()
{
    
}
