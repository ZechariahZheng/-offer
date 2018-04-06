#include <iostream>
#include <stack>

using namespace std;

/*输入两个链表，找出它们的第一个公共结点。*/

/*思路：分别把两个链表的结点放入两个栈里，这样两个链表的尾结点就位于两个栈的栈顶，
接下来比较两个栈顶的结点是否相同。如果相同，则把栈顶弹出接着比较下一个栈顶，直到找到最后一个相同的结点。*/

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