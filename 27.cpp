#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

/*思路：   首先字符串中个各个字符出现在第一位，让后除第一位之外的字符分别出现在第二位。
再让后除第一第二位的字符分别出现在第三位。一次类推。每次操作完成后需要把字符串恢复到初始状态，方便后面的交替操作。*/

/*注意的两点：
**1、重复字母：对于重复字母，我们在进行交换的时候直接跳过去
**2、按字典排序：每次在进行交换之后，把剩余的元素进行一次排列*/

/*冒泡排序：平均时间复杂度O(N^2)*/
void bubbleSort(string arr, int begin, int length)
{
    for (int i = begin; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

/*迭代交换知道*/
void PrePermutation(string str, int k, int length, vector<string> &result)
{
    if (k == length)
    {
        result.push_back(str);
    }
    else
    {
        for (int i = k; i < length; i++)
        {
            /*重复字母忽略*/
            if (k != i && str[k] == str[i])
                continue;
            swap(str[k], str[i]);                 //交换字母
            bubbleSort(str, k+1, length);           //剩余字母排序
            PrePermutation(str, k+1, length, result);    //交换排序之后，递归排序n-1个之后剩余的字符串
            bubbleSort(str, k+1, length);
        }
    }
}

vector<string> Permutation(string str) 
{
    vector<string> result;
    if (str.size() == 0)
    {
        return result;
    }
    PrePermutation(str, 0, str.size(), result);
    return result;
}

int main()
{
    string str = "abc";
    vector<string> result;
    result = Permutation(str);
    for (int i = 0; i < result.size(); i++)
	{
		string str = result[i];
        cout << str << endl;
	}
    
    system("pause");
    return 0;
}