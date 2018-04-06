#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。*/

/*思路：后一个数等于前面的数乘以2、3、5所有的数的排序之后的数中，与结果数组中比较，首先出现的第一个比它大的数。
采用辅助数组，保存前面的数乘以2、3、5,每次推入结果数组中最后一个元素的乘以2/3/5的积，然后排序*/
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
            /*每个数乘以2,3,5*/
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