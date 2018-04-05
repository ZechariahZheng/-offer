#include <iostream>

/*算法思想：将第一个多项式，乘于第二个多项式，。。。。*/

using namespace std;

int sup[max], temp[max];
/*sup是保存多项式的数组，sup[n]中的值表示x^n的系数
* temp是临时多项式，保存相乘的中间情况*/

int main()
{
    int target;     //目标重量
    int i, j, k;
    
    while (cin >> target)
    {
        for (i = 0; i <= target; i++)
        {
            /*初始化第一个多项式*/
            sup[i] = 1;
            temp[i] = 0;
        }
        
        /*生成后续的第i个多项式，此题是2g，故i从2开始
         *如果砝码的值不是规律增长，i可能需要取决于输入*/
        for (i = 2; i <= target; i++)
        {
            /*遍历当前多项式(当前多项式也相当于暂时的结果)的每一项与第i个多项式相乘*/
            for (j = 0; j <= target; j++)
            {
                /*遍历第i个多项式的每一项，此处构造用小砝码组成大砝码*/
                for (k = 0; k+j <= target; k+=i)
                {
                    /*幂运算，注意理解;第i个多项式的各项的系数为1
                     *如果temp[3]则有：temp[3] = sup[1]+sup[2]+sup[3]*/
                    temp[j+k] += sup[j]; 
                }
            }
            for (j = 0; j <= target; j++)
            {
                sup[j] = temp[j];
                temp[j] = 0;
            }
        }
        cout << sup[target] << endl;        //输出结果
    }
    return 0;
}

