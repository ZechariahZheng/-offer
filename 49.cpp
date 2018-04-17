#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

/*��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0*/
/*˼·��
1.����������� 
2.������ĸ�ַ� 
3.�������ֹ�����С���µ�������� 
4.�ַ���ǰ�溬�пո�*/

typedef enum STATE {        //����һ��ö���������б������Ƿ�Ƿ�
    VAILD,
    INVAILD
}STATE;

STATE state = VALID;        //�Ƚ�״̬����Ϊ�Ϸ�
int StrToInt(string str) 
{
    int flag = 1;           //���÷��ű�־
    long long ret = 0;      //���ǵ�����ֵ���ܽϴ󣬶���Ϊlong long
    const char *strch = str.c_str();
    
    while (isspace(*strch))
    {
        strch++;
    }
    
    if (*strch == '+')      //��������������ô���
        strch++;
    if (*strch == '-')      //����Ǹ����������ű�־ȡ��
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
        else        //���ǺϷ���ֵ
        {
            state = INVAILD;        //��״ֵ̬Ϊ�Ƿ�
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