#include <iostream>

using namespace std;

/*在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,
求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007*/

/*思路：采用一个辅助数组，保存前面的数字，比较当前数字比辅助数组中数字小的*/

int InversePairs(vector<int> data) 
{
    if (data.size() == 0 || data.size() == 1)
        return 0;
    
    vector<int> fu;
    int result = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (fu.size() != 0)
        {
            /*当前数字与辅助数组进行比较*/
            for (int j = 0; j < fu.size(); j++)
            {
                if (fu[j] > data[i])
                    result++;
            }
        }
        fu.push_back(data[i]);
    }
    return result;
}
    
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 0};
    vector<int> test(&a[0], &a[8]);
    cout << InversePairs(test) << endl;
    system("pause");
    return 0;
}