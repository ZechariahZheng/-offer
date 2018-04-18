#include <iostream>
#include <vector>

using namespace std;

/*给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。*/

/*思路：
A[]={1,2,3}求B[] 
B[0]=A[1]×A[2]=2×3=6 
B[1]=A[0]×A[2]=1×3=3 
B[2]=A[0]×A[1]=1×2=2
故：B[1]开始以后的都是先A[0]乘到A[i-1]，然后再从A[i+1]乘到A[n-1]
比较后部分的相乘是否i+1超过*/
vector<int> multiply(const vector<int>& A) 
{
    vector<int> result;
    int n = A.size();
    if (n < 2)
        return result;
    int tmp = 1;
    /*计算B[0]*/
    for (int i = 1; i < n; i++)
    {
        tmp *= A[i];
    }
    result.push_back(tmp);
    tmp = 1;
    /*计算剩下的B[i]的值*/
    for (int i = 1; i < n; i++)
    {
        /*先计算乘以到A[i-1]*/
        for (int j = 0; j < i; j++)
        {
            tmp *= A[j];
        }
        /*再计算乘以到A[n-1]*/
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