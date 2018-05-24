#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*栈的压入、弹出序列*/
/*解题想法：将压栈的序列逐个从底部出栈，压入辅助栈。如果辅助栈的栈顶元素
与所需出栈序列的栈顶元素相同，则辅助栈的栈顶元素出栈；否则，依次压入辅助
栈。如果最终辅助栈为空，则返回true，否则返回false
**/
bool IsPopOrder(vector<int> pushV,vector<int> popV) 
{
    /*入参判断*/
    if (pushV.size()!=popV.size() && pushV.size()==0)
        return false;
    /*将压栈序列逐个压入辅助栈，边压栈的过程边判断*/
    stack<int> tmpV;

    int j = 0;
    for (int i = 0; i < pushV.size(); i++)
    {
        /*将序列压入辅助栈*/
        tmpV.push(pushV[i]);
        /*判断辅助栈的栈顶元素与出栈序列的元素*/
        while (!(tmpV.empty()) && tmpV.top()==popV[j])
        {
            tmpV.pop();
            j++;
        }
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