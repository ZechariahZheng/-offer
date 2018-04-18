#include <iostream>
#include <vector>

using namespace std;

/*��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2��*/

/*˼·������vector��һ����Ų�һ�������֣���һ����Ų�һ�����ֳ��ֵĴ���*/

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
            if (DifNums[j] == tmp)   //�ҵ���ͬ����
            {
                ShowTimes[j]++;
                DupNum++;
                ExistFlag = true;
                break;
            }
        }
        if (ExistFlag == false)   //δ�ҵ���ͬ����
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