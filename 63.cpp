#include <iostream>
#include <vector>

using namespace std;

/*如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。*/

/*思路：
将数组插入到一个vector数组中，然后排序，取出中位数*/
vector<int> All;

void Insert(int num)
{
    All.push_back(num);
}

double GetMedian()
{
    sort(All.begin(), All.end());
    int n = All.size();
    double result = 0.0;
    if (n > 0)
    {
        if (n%2 == 0)       //偶数
        {
            result = (All[n/2]+All[n/2-1])/2.0;
        }
        else    //奇数
        {
            result = All[(n-1)/2];
        }
    }
    return result;
}

int main()
{
    return 0;
}