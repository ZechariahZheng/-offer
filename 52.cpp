#include <iostream>

uisng namespace std;

/*请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配*/

/*思路
1、下一位是*，分三种情况
1.1、matCore(str+1,pattern)模式串匹配成功，并尝试匹配下一个字符
1.3、matchCore(str,pattern+2)模式串未匹配，
2、下一位不是*，则pattern对应为应该为str相等或者pattern的对应为.
    matchCore(str+1, pattern+1)
3、对应不匹配*/
bool match(char* str, char* pattern)
{
    if (str == NULL || pattern == NULL)
        return false;
    return matchCore(str, pattern);
}

bool matchCore(char* str, char* pattern)
{
    /*迭代终止条件*/
    if (*str == '\0' && *pattern == '\0')
        return true;
    if (*str != '\0' && *pattern == '\0')
        return false;
    /*下一位是* */
    if (*(pattern+1) == '*')
    {
        /*当前字符匹配或者当前pattern字符为.*/
        if (*str == *pattern || (*pattern=='.'&&*str!='\0'))
            return matchCore(str+1, pattern) || matchCore(str, pattern+2);
        else    //前面字符串为匹配
            return matchCore(str, pattern+2);
    }
    if (*str == *pattern || (*pattern=='.'&&*str!='\0'))
        return matchCore(str+1, pattern+1);
    
    return false;
}

int main()
{
    return 0;
}