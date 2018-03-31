#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*ջ��ѹ�롢��������*/
/*�����뷨����ѹջ����������ӵײ���ջ��ѹ�븨��ջ���������ջ��ջ��Ԫ��
�������ջ���е�ջ��Ԫ����ͬ������ջ��ջ��Ԫ�س�ջ����������ѹ�븨��
ջ��������ո���ջΪ�գ��򷵻�true�����򷵻�false
**/
bool IsPopOrder(vector<int> pushV,vector<int> popV) 
{
    /*����ж�*/
    if (pushV.size()!=popV.size() && pushV.size()==0)
		return false;
    /*��ѹջ�������ѹ�븨��ջ����ѹջ�Ĺ��̱��ж�*/
    stack<int> tmpV;
    vector<int>::iterator itPush = pushV.begin();
    vector<int>::iterator itPop = popV.begin();

    while (itPush != pushV.end())
    {
        /*��ѹջ����ѹ�븨��ջ��ֱ��������ջ���е�ջ��Ԫ��*/
        if (*itPush == *itPop)
        {
            itPop++;
        }
        else
        {
            tmpV.push(*itPush);
        }
        ++itPush;
    }

    /*ѹջ������ȫ�����븨��ջ���ж�ʣ���ջ�����븨��ջ*/
    while (tmpV.top()==*itPop && (!tmpV.empty()))
    {
        tmpV.pop();
        itPop++;
		if (tmpV.empty())
			break;
    }
    
    if (tmpV.empty())
        return true;
    else
        return false;
}

int main()
{
	int tmp_1[5] = {1,2,3,4,5};
	int tmp_2[5] = {4,5,3,2,1};
	int tmp_3[5] = {4,3,5,1,2};
    vector<int> a(&tmp_1[0], &tmp_1[5]);
    vector<int> b(&tmp_2[0], &tmp_2[5]);
    vector<int> c(&tmp_3[0], &tmp_3[5]);
    

    if (IsPopOrder(a,c))
        cout << "YES" << endl;
    else
        cout << "NO" <<endl;

	system("pause");
    return 0;
}