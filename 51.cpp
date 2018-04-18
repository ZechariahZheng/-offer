#include <iostream>
#include <vector>

using namespace std;

/*����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],
����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]������ʹ�ó�����*/

/*˼·��
A[]={1,2,3}��B[] 
B[0]=A[1]��A[2]=2��3=6 
B[1]=A[0]��A[2]=1��3=3 
B[2]=A[0]��A[1]=1��2=2
�ʣ�B[1]��ʼ�Ժ�Ķ�����A[0]�˵�A[i-1]��Ȼ���ٴ�A[i+1]�˵�A[n-1]
�ȽϺ󲿷ֵ�����Ƿ�i+1����*/
vector<int> multiply(const vector<int>& A) 
{
    vector<int> result;
    int n = A.size();
    if (n < 2)
        return result;
    int tmp = 1;
    /*����B[0]*/
    for (int i = 1; i < n; i++)
    {
        tmp *= A[i];
    }
    result.push_back(tmp);
    tmp = 1;
    /*����ʣ�µ�B[i]��ֵ*/
    for (int i = 1; i < n; i++)
    {
        /*�ȼ�����Ե�A[i-1]*/
        for (int j = 0; j < i; j++)
        {
            tmp *= A[j];
        }
        /*�ټ�����Ե�A[n-1]*/
        for (int j = i+1; j < n; j++)
        {
            tmp *= A[j];
        }
        result.push_back(tmp);
        tmp = 1;
    }
    return result;
}

int main()
{
    int array[] = {1,2,3};
    vector<int> test(&array[0], &array[3]);
    vector<int> result = multiply(test);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    system("pause");
    return 0;
}