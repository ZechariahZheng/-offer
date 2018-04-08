#include <iostream>

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2)
{
    if (data.empty())
        return;
    vector<int> DifNums;
    vector<int> ShowTimes;
    bool ExistFlag = false;
    
    for (int i = 0; i < data.size(); i++)
    {
        ExistFlag = false;
        for (int j = 0; j < DifNums.size(); j++)
        {
            if (DifNums[j] == data[i])
            {
                ExistFlag = true;
                ShowTimes[j]++;
                break;
            }
        }
        if (ExistFlag == false)
        {
            DifNums.push_back(data[i]);
            ShowTimes.push_back(1);
        }
    }
    int TWO = 2;
    for (int i = 0; i < ShowTimes.size() && TWO >= 1; i++)
    {
        if (ShowTimes[i] == 1)
        {
            if (TWO == 2)
            {
                *num1 = DifNums[i];
                TWO--;
            }
            else if (TWO == 1)
            {
                *num2 = DifNums[i];
                TWO--;
            }
        }
    }
}

int main()
{
    int a[] = {2,4,3,6,3,2,5,5};
    vector<int> test(&a[0], &a[8]);
    int num1 = 0;
    int num2 = 0;
    FindNumsAppearOnce(test, &num1, &num2);
    cout << num1 << endl;
    cout << num2 << endl;
    system("pause");
    return 0;
}