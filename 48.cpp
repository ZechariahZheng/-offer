#include <iostream>

using namespace std;

/*дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�*/

/*˼·��������
��һ����λ��Ӳ���λ
�ڶ���ֻ���ǽ�λ����
��������ǰ������Ľ�����*/

int Add(int num1, int num2)
{
    int sum, mark;
    
    do {
        sum = num1^num2;
        mark = (num1&num2)<<1;
        num1 = sum;
        num2 = mark;
    }while(num2 != 0);
    return num1;
}

int main()
{
    return 0;
}