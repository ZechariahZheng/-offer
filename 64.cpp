#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

/*给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
 {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。*/

/*思路：
使用一个临时数，保存下滑动窗口的此刻最大数值，遍历完所有之后返回其中的最大值
*/


vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> result;
    if(num.empty()||size>num.size()||size<1)
        return result;
    int tmpMax = INT_MIN;
    int numSize = num.size();
    for (int i = 0; i < (numSize-size+1); i++)
    {
        tmpMax = num[i];
        for (int j = i+1; j < (i+size); j++)
        {
            if (tmpMax < num[j])
                tmpMax = num[j];
        }
        result.push_back(tmpMax);
    }
    return result;
}

int main()
{
    return 0;
}