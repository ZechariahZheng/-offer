#include <iostream>
#include <vector>
#include <algorithm>

/*˼·�����������а���С�������������������ֵĲ�಻�ܳ��������к���0�ĸ�����
�ҳ���0֮�ⲻ�ܺ�������������ͬ�����֣���Ϊ��һ������˳��*/

using namespace std;

bool IsContinuous( vector<int> numbers )
{
    bool result = false;
    if (numbers.empty())
        return result;
    sort(numbers.begin(), numbers.end());
    
    int pre, now;
    pre = -1;   //��ǰ����
    int ZeroNum = 0;
    int len = 0;
    /*�Ƚ��������ڵ���,��¼��0�ĸ������Ƿ�����ͬ����,�������������ľ���*/
    for (int i = 0; i < numbers.size(); i++)
    {
        now = numbers[i];
        if (now == pre && now != 0)
        {
            /*��ͬ����*/
            result = false;
            return result;
        }
        /*��¼0�ĸ���*/
        if (now == 0)
            ZeroNum++;
        /*ͳ�Ʋ��*/
        if (now-pre>1 && pre>0)
        {
            len += now-pre-1;
        }
        pre = now;
    }
    if (ZeroNum == len)
        result = true;
    return result;
}

int main()
{
    int a[] = {3,0,0,0,0};
    vector<int> test(&a[0], &a[5]);
    bool result = IsContinuous(test);
    if (result == false)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    system("pause");
    return 0;
}