#include <iostream>

/*�㷨˼�룺����һ������ʽ�����ڵڶ�������ʽ����������*/

using namespace std;

int sup[max], temp[max];
/*sup�Ǳ������ʽ�����飬sup[n]�е�ֵ��ʾx^n��ϵ��
* temp����ʱ����ʽ��������˵��м����*/

int main()
{
    int target;     //Ŀ������
    int i, j, k;
    
    while (cin >> target)
    {
        for (i = 0; i <= target; i++)
        {
            /*��ʼ����һ������ʽ*/
            sup[i] = 1;
            temp[i] = 0;
        }
        
        /*���ɺ����ĵ�i������ʽ��������2g����i��2��ʼ
         *��������ֵ���ǹ���������i������Ҫȡ��������*/
        for (i = 2; i <= target; i++)
        {
            /*������ǰ����ʽ(��ǰ����ʽҲ�൱����ʱ�Ľ��)��ÿһ�����i������ʽ���*/
            for (j = 0; j <= target; j++)
            {
                /*������i������ʽ��ÿһ��˴�������С������ɴ�����*/
                for (k = 0; k+j <= target; k+=i)
                {
                    /*�����㣬ע�����;��i������ʽ�ĸ����ϵ��Ϊ1
                     *���temp[3]���У�temp[3] = sup[1]+sup[2]+sup[3]*/
                    temp[j+k] += sup[j]; 
                }
            }
            for (j = 0; j <= target; j++)
            {
                sup[j] = temp[j];
                temp[j] = 0;
            }
        }
        cout << sup[target] << endl;        //������
    }
    return 0;
}

