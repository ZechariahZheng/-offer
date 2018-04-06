#include <iostream>
#include <vector>

using namespace std;

/*在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
并返回它的位置*/

/*思路：三个数组，一个存储不一样的字符，一个存储第一次出现的位置；另一个存储不一样字符的出现次数*/

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
            /*查找字母是否出现过*/
            if (str[i-1] == DifChar[j])
            {
                ExistFlag = 1;
                break;
            }
        }
        if (0 == ExistFlag)
        {
            /*字母未出现过*/
            DifChar.push_back(str[i-1]);
            FirstShow.push_back(i);
            ShowNum.push_back(1);
        }
        else
        {
            /*字母出现过*/
            ShowNum[j]++;   //出现次数加1
        }
        i++;
    }
    /*查找第一个1出现的位置*/
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