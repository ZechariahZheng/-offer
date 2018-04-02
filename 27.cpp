#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

/*˼·��   �����ַ����и������ַ������ڵ�һλ���ú����һλ֮����ַ��ֱ�����ڵڶ�λ��
���ú����һ�ڶ�λ���ַ��ֱ�����ڵ���λ��һ�����ơ�ÿ�β�����ɺ���Ҫ���ַ����ָ�����ʼ״̬���������Ľ��������*/

/*ע������㣺
**1���ظ���ĸ�������ظ���ĸ�������ڽ��н�����ʱ��ֱ������ȥ
**2�����ֵ�����ÿ���ڽ��н���֮�󣬰�ʣ���Ԫ�ؽ���һ������*/

/*ð������ƽ��ʱ�临�Ӷ�O(N^2)*/
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

/*��������֪��*/
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
            /*�ظ���ĸ����*/
            if (k != i && str[k] == str[i])
                continue;
            swap(str[k], str[i]);                 //������ĸ
            bubbleSort(str, k+1, length);           //ʣ����ĸ����
            PrePermutation(str, k+1, length, result);    //��������֮�󣬵ݹ�����n-1��֮��ʣ����ַ���
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