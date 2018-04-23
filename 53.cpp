#include <iostream>

using namespace std;

/*请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。*/
 
/*思路：
挨个遍历字符串，其中每个字符都可以是数字
1、第一个字符可以是"+、-"
2、第二个字符可以是".(但前一个数字必须是数字，且整个字符串只能有一个)、e或是E"
3、整个字符串
".、e"只能出现一次，
全局不能出现两次加号
点号不能在e的右边(如果e存在)
全局可以出现两次减号，但第二次减号必须在e的相邻右边
全局可以出现一次加号和一次减号，但是第二次的减号必须在E相邻右边
全局e不能出现在最后一个位置
当全局不存在e时，全局加号只能出现在第一个位置*/
bool isNumeric(char* string)
{
    bool result = false;
    if (string == NULL)
        return result;
    
    int cnt = 0;
    result = true;
    int PointNum = 0;
    int ENum = 0;
    int PlusNum = 0;
    int MinusNum = 0;
    int PosPoint = 0;       //点号的位置
    int PosE = 0;
    int PosMinus = 0;
    int PosPlus = 0;
    while (*string != '\0')
    {
        if (cnt==0 && ((*string>='0'&&*string<='9')||*string=='+'||*string=='-'))
        {
            if (*string == '+')
            {
                PlusNum++;
                PosPlus = cnt;
            }
            if (*string == '-')
            {
                MinusNum++;
                PosMinus = cnt;
            }
            string++;
            cnt++;
            continue;
        }
        else if (cnt == 0)
        {
            result = false;
            break;
        }
        else if(cnt > 0)    //第二个字符以后的字符
        {
            /*如果出现数字、加减、e和E，还有点号以外的字符*/
            if (*string=='.')
            {
                PointNum++;
                PosPoint = cnt;
            }
            if (*string=='e'||*string=='E')
            {
                ENum++;
                PosE = cnt;
            }
            if (*string == '+')
            {
                PlusNum++;
                PosPlus = cnt;
            }
            if (*string == '-')
            {
                MinusNum++;
                PosMinus = cnt;
            }
            if (!((*string>='0'&&*string<='9')||*string=='+'||*string=='-'||*string=='.'||*string=='e'||*string=='E'))
            {
                result = false;
                break;
            }
            cnt++;
            string++;
        }
    }
    /*判断点号、E和加号/减号的数量*/
    if (PointNum>1 || ENum>1 || PlusNum>1 || MinusNum>2)
        result = false;
    /*判断点号不能在E的右边*/
    if (ENum==1 && PosPoint>PosE)
        result = false;
    /*判断全局可以出现两次减号，但第二次减号必须在e的相邻右边*/
    if (MinusNum==2 && (PosMinus-PosE)!=1)
        result = false;
    /*判断全局可以出现一次加号和一次减号，但是第二次的减号必须在E相邻右边*/
    if ((PlusNum==1 && MinusNum==1 && ENum==1 && (PosMinus-PosE)!=1) ||
        (PlusNum==1 && MinusNum==1 && ENum==0))
        result = false;
    /*判断全局e不能出现在最后一个位置*/
    if (PosE == cnt-1)
        result = false;
    /*判断全局加号只能出现在第一个位置*/
    if (ENum==0 && PosPlus!=0)
        result = false;
    
    return result;
}

int main()
{
    char *test = "+1a0";
    bool result = isNumeric(test);
    if (result)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    system("pause");
    return 0;
}