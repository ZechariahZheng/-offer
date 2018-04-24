#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。*/

/*思路：
遍历整个字符串，预留两个栈
一个vector保留不同的字符，另一个vector保留不同的字符出现的次数*/
string str;
//Insert one char from stringstream
void Insert(char ch)
{
    str = str + ch;         //插入字符
}

//return the first appearence once char in current stringstream
char FirstAppearingOnce()
{
    char result = '#';
    if (str.size() == 0)
        return '#';
    vector<char> DifChar;
    vector<int> ShowNum;
    bool ExistFlag = false;
    const char* test = str.c_str();
    
    while (*test != '\0')
    {
        ExistFlag = false;
        /*是否已经存在*/
        for (int i = 0; i < DifChar.size(); i++)
        {
            if (*test == DifChar[i])
            {
                ExistFlag = true;
                ShowNum[i]++;
                break;
            }
        }
        if (ExistFlag == false)
        {
            DifChar.push_back(*test);
            ShowNum.push_back(1);
        }
        test++;
    }
    
    /*寻找ShowNum中的第一个1*/
    for (int i = 0; i < ShowNum.size(); i++)
    {
        if (ShowNum[i] == 1)
        {
            result = DifChar[i];
            break;
        }
    }
    
    return result;
}

int main()
{
    str = "google";
    char test = FirstAppearingOnce();
    cout << test << endl;
    system("pause");
    return 0;
}