#include <iostream>
#include <vector>

using namespace std;

/*��һ���ַ���(1<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,
����������λ��*/

/*˼·���������飬һ���洢��һ�����ַ���һ���洢��һ�γ��ֵ�λ�ã���һ���洢��һ���ַ��ĳ��ִ���*/

int FirstNotRepeatingChar(string str) 
{
    if (str.size() == 0)
        return -1;
    
    vector<char> DifChar;
    vector<int> FirstShow;
    vector<int> ShowNum;
    vector<char>::iterator it;
    int i = 1;
    int j = 0;
    int ExistFlag = 0;
    while (i != str.size())
    {
        ExistFlag = 0;
        for (j = 0; j < DifChar.size(); j++)
        {
            /*������ĸ�Ƿ���ֹ�*/
            if (str[i-1] == DifChar[j])
            {
                ExistFlag = 1;
                break;
            }
        }
        if (0 == ExistFlag)
        {
            /*��ĸδ���ֹ�*/
            DifChar.push_back(str[i-1]);
            FirstShow.push_back(i);
            ShowNum.push_back(1);
        }
        else
        {
            /*��ĸ���ֹ�*/
            ShowNum[j]++;   //���ִ�����1
        }
        i++;
    }
    /*���ҵ�һ��1���ֵ�λ��*/
    for (i = 0; i < ShowNum.size(); i++)
    {
        if (ShowNum[i] == 1)
            break;
    }
    return FirstShow[i];
}

int main()
{
    string str = "hwhhwaww";
    cout << FirstNotRepeatingChar(str) << endl;
    system("pause");
    return 0;
}