#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。*/

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