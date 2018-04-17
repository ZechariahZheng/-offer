#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

/*将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0*/
/*思路：
1.正负数的输出 
2.含有字母字符 
3.考虑数字过大或过小导致的溢出现象 
4.字符串前面含有空格*/

typedef enum STATE {        //设置一个枚举类型来判别输入是否非法
    VAILD,
    INVAILD
}STATE;

STATE state = VALID;        //先将状态设置为合法
int StrToInt(string str) 
{
    int flag = 1;           //设置符号标志
    long long ret = 0;      //考虑到返回值可能较大，定义为long long
    const char *strch = str.c_str();
    
    while (isspace(*strch))
    {
        strch++;
    }
    
    if (*strch == '+')      //如果是正数，不用处理
        strch++;
    if (*strch == '-')      //如果是负数，将符号标志取反
    {
        flag = -flag;
        strch++;
    }
    
    while (*strch)
    {
        if (isdigit(*strch))
        {
            ret = ret*10 +(*strch-'0')*flag;
            if (ret>INT_MAX || ret<INT_MIN)
            {
                ret = 0;
                break;
            }
            strch++;
        }
        else        //不是合法的值
        {
            state = INVAILD;        //将状态值为非法
            ret = 0;
            break;
        }
    }
    
    return (int)ret;
};

int main()
{
    
    return 0;
}