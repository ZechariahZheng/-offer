#include <iostream>
#include <string.h>

using namespace std;

/*请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy*/
/*思路：
先统计字符串中空格的个数，重新分配字符串的长度
然后从后向前遍历以前的字符串，遇到空格，向新分配的字符串内填入"%20"

注：没有重新分配地址，直接在原来的位置上扩充*/

void replaceSpace(char *str,int length) 
{
    char *result = NULL;
    
    char *saveStr = str;
    /*统计空格的个数*/
    int nulNum = 0;
    while (*str != '\0')
    {
        if (*str == ' ')
            nulNum++;
        str++;
    }
    str = saveStr;
    char *end = str+length;               //源串的最后一个位置
    char *finish = str+length+nulNum*2;     //信串的最后一个位置
    while (end != finish)
    {
        if (*end == ' ')
        {
            *finish = '0';
            finish--;
            *finish = '2';
            finish--;
            *finish = '%';
        }
        else
        {
            *finish = *end;
        }
        finish--;
        end--;
    }
}

int main()
{
    
    system("pause");
    return 0;
}