#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,���Ƕ��ں�����������û���ˡ�
ACMerϣ�����ǰ����,������������ձ黯,���Ժܿ���������Ǹ�����������1���ֵĴ�����*/

int CountNumberOf1(char *input)
{
    int result = 0;
    while (*input != '\0')
    {
        if (*input == '1')
            result++;
        input++;
    }
    return result;
}

int NumberOf1Between1AndN_Solution(int n)
{
    if (n == 0)
        return 0;
    char StringNum[20];
    int result = 0;
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(StringNum, 0, sizeof(StringNum));
        sprintf(StringNum, "%d", i);
        tmp = CountNumberOf1(StringNum); 
        result += tmp;
    }
    return result;
}

int main()
{
    cout << NumberOf1Between1AndN_Solution(13) << endl;
    
    system("pause");
    return 0;
}