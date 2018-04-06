#include <iostream>
#include <stack>

using namespace std;

/*�������������ҳ����ǵĵ�һ��������㡣*/

/*˼·���ֱ����������Ľ���������ջ��������������β����λ������ջ��ջ����
�������Ƚ�����ջ���Ľ���Ƿ���ͬ�������ͬ�����ջ���������űȽ���һ��ջ����ֱ���ҵ����һ����ͬ�Ľ�㡣*/

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) 
{
    if (pHead1 == NULL || pHead2 == NULL)
        return NULL;
    
    stack<ListNode*> stack1;
    stack<ListNode*> stack2;
    
    while (pHead1 != NULL)
    {
        stack1.push(pHead1);
        pHead1 = pHead1->next;
    }
    
    while (pHead2 != NULL)
    {
        stack2.push(pHead2);
        pHead2 = pHead2->next;
    }
    
    ListNode *result = NULL;
    while (!stack1.empty() && !stack2.empty())
    {
        if (stack1.top() == stack2.top())
        {
            result = stack1.top();
            stack1.pop();
            stack2.pop();
        }
        else
            break;
    }
    return result;
}