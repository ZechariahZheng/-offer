#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*��ֻ��������2��3��5��������������Ugly Number��������6��8���ǳ�������14���ǣ���Ϊ����������7�� 
ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������*/

/*˼·����һ��������ǰ���������2��3��5���е���������֮������У����������бȽϣ����ȳ��ֵĵ�һ�������������
���ø������飬����ǰ���������2��3��5,ÿ�����������������һ��Ԫ�صĳ���2/3/5�Ļ���Ȼ������*/
int GetUglyNumber_Solution(int index) 
{
    if (index == 0)
        return 0;
	int resultIndex = index;
    vector<int> result;
    result.push_back(1);
    vector<int> tmp;
    int i = result.size()-1;
	int oldSize;
	int tmpI = 0;
    while (index > 0)
    {
		oldSize = result.size();
        while (i < oldSize)
        {
            /*ÿ��������2,3,5*/
            tmp.push_back(result[i]*2);
            tmp.push_back(result[i]*3);
            tmp.push_back(result[i]*5);
            sort(tmp.begin(), tmp.end());
			
			if (result[oldSize-1] < tmp[tmpI])
			{
				result.push_back(tmp[tmpI]);
				tmpI++;
			}
			else
			{
				for (int j = tmpI+1; j < tmp.size(); j++)
					if (tmp[j] > result[oldSize-1])
					{
						result.push_back(tmp[j]);
						tmpI = j;
						break;
					}
			}
            i++;
        }
        i = result.size()-1;
        index--;
    }
    return result[resultIndex-1];
}

int main()
{
    cout << GetUglyNumber_Solution(11) << endl;
    system("pause");
    return 0;
}