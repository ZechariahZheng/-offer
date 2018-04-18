#include <iostream>
#include <vector>

using namespace std;

/*在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。*/

/*思路：两个vector，一个存放不一样的数字，另一个存放不一样数字出现的次数*/

bool duplicate(int numbers[], int length, int* duplication)
{
    if (length <= 0)
        return false;
    
    vector<int> DifNums;
    vector<int> ShowTimes;
    bool ExistFlag = false;
    int DupNum = 0;
    int tmp = 0;
    
    for (int i = 0; i < length; i++)
    {
        tmp = numbers[i];
        ExistFlag = false;
        for (int j = 0; j < DifNums.size(); j++)
        {
            if (DifNums[j] == tmp)   //找到相同的数
            {
                ShowTimes[j]++;
                DupNum++;
                ExistFlag = true;
                break;
            }
        }
        if (ExistFlag == false)   //未找到相同的数
        {
            DifNums.push_back(tmp);
            ShowTimes.push_back(1);
        }
    }
    if (DupNum == 0)
        return false;
    
    int first = 0;
    for (int i = 0; i < ShowTimes.size(); i++)
    {
        if (ShowTimes[i]>1 && first==0)
        {
            duplication[0] = DifNums[i];
            first++;
        }
    }
    return true;
}

int main()
{
    int array[] = {2,3,1,0,2,5,3};
    int result[7] = {-1,-1,-1,-1,-1,-1,-1};
    (void)duplicate(array, 7, result);
    for (int i = 0; i < 7; i++)
        cout << result[i] << endl;
    system("pause");
    return 0;
}