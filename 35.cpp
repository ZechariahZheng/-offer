#include <iostream>

using namespace std;

/*�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ������,
�����������е�����Ե�����P������P��1000000007ȡģ�Ľ������� �����P%1000000007*/

/*˼·������һ���������飬����ǰ������֣��Ƚϵ�ǰ���ֱȸ�������������С��*/

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
            /*��ǰ�����븨��������бȽ�*/
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