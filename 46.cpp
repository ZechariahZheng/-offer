#include <iostream>
#include <list>

using namespace std;

/*˼·�������n>=mʱ������m-1���뿪
        �����n<mʱ������m%n-1���뿪
����һ��Ԫ�س�����֮����Ҫ�����ƶ��������Ƿ����ѭ������
�������ѭ�����У�������ͨ����ģ��ѭ������*/
        

int LastRemaining_Solution(int n, int m)
{
    /*�����ж�*/
    if (n == 1)
        return 0;
    if (n == 0)
        return -1;
    list<int> numbers;
    for (int i = 0; i < n; i++)
        numbers.push_back(i);
    
    /*��ʼѭ��*/
    list<int>::iterator it;
    list<int>::iterator tmp;
    int cnt;
    list<int>::iterator current = numbers.begin();
    while (numbers.size() > 1)
    {
        cnt = 0;
        it = current;                   //ָ��ͷָ��
        if (numbers.size() >= m)        /*ɾ���ִ�����е�m-1��Ԫ��*/
        {
            while (cnt < m-1)
            {
                it++;
                if (it == numbers.end())        //���ָ�����β��+1��λ�ã�������ָ��ͷ��
                    it = numbers.begin();
                cnt++;
            }
            numbers.erase(it++);
            tmp = it;
            n--;
            /*ɾ��Ԫ�غ󣬶��е�ͷָ��Ҫ����ָ��*/
            if (tmp == numbers.end())
                current = numbers.begin();
            else
                current = tmp;
        }
        else    //ɾ���ִ�����е�m%n-1��Ԫ��
        {
            if (m%n >= 1)
            {
                while (cnt < m%n-1)
                {
                    it++;
                    if (it == numbers.end())        //���ָ�����β��+1��λ�ã�������ָ��ͷ��
                        it = numbers.begin();
                    cnt++;
                }
            }
            else
            {
                /*�պó�������ɾ���¶��е����һ��Ԫ��*/
                while (cnt < n-1)
                {
                    it++;
                    if (it == numbers.end())
                        it = numbers.begin();
                    cnt++;
                }
            }
            it = numbers.erase(it++);
            n--;
            /*ɾ��Ԫ�غ󣬶��е�ͷָ��Ҫ����ָ��*/
            tmp = it;
            if (tmp == numbers.end())
                current = numbers.begin();
            else
                current = tmp;
        }
    }
    return numbers.front();
}

int main()
{
    int result = LastRemaining_Solution(6, 6);
    cout << result << endl;
    system("pause");
    return 0;
}