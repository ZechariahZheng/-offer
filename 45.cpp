#include <iostream>
#include <vector>
#include <algorithm>

/*思路：将输入序列按从小到大排序，相邻两个数字的差距不能超过数组中含有0的个数，
且除了0之外不能含有其他两个相同的数字，因为这一定不是顺子*/

using namespace std;

bool IsContinuous( vector<int> numbers )
{
    bool result = false;
    if (numbers.empty())
        return result;
    sort(numbers.begin(), numbers.end());
    
    int pre, now;
    pre = -1;   //先前的数
    int ZeroNum = 0;
    int len = 0;
    /*比较两两相邻的数,记录下0的个数和是否有相同的数,和所有数字相差的距离*/
    for (int i = 0; i < numbers.size(); i++)
    {
        now = numbers[i];
        if (now == pre && now != 0)
        {
            /*相同的数*/
            result = false;
            return result;
        }
        /*记录0的个数*/
        if (now == 0)
            ZeroNum++;
        /*统计差距*/
        if (now-pre>1 && pre>0)
        {
            len += now-pre-1;
        }
        pre = now;
    }
    if (ZeroNum == len)
        result = true;
    return result;
}

int main()
{
    int a[] = {3,0,0,0,0};
    vector<int> test(&a[0], &a[5]);
    bool result = IsContinuous(test);
    if (result == false)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    system("pause");
    return 0;
}