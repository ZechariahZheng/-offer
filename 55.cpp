#include <iostream>

using namespace std;

/*一个链表中包含环，请找出该链表的环的入口节点*/

/*思路：
从链表头开始依次遍历下去，并保存下访问的地址
每寻找一个地址和以前的地址进行比较，如果相同则找到该入口结点*/

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    if (pHead == NULL)
        return NULL;
    vector<ListNode*> Visited;
    ListNode* result = NULL;
    bool flag = false;

    while (pHead != NULL)
    {
        for (int i = 0; i < Visited.size(); i++)
        {
            if (pHead == Visited[i])
            {
                flag = true;
                result = pHead;
                break;
            }
        }
        if (flag == false)
            Visited.push_back(pHead);
        else
            break;
        pHead = pHead->next;
    }
    return result;
}

int main()
{
    return 0;
}