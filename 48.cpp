#include <iostream>

using namespace std;

/*写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。*/

/*思路：分三步
第一步各位相加不进位
第二步只考虑进位运算
第三步把前两步骤的结果相加*/

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